#ifdef HAVE_CONFIG_H
#include "clicon_config.h"
#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>
#include <netinet/in.h>
 
#include <curl/curl.h>
#if HAVE_CURL_TYPES_H
#include <curl/types.h>
#endif
#include <curl/easy.h>
 
/* cligen & clicon */
#include <cligen/cligen.h>
#include <clicon/clicon.h>

#include "cli_curl.h"

/*
 * URL has local "protocol"?
 */
static int
clicon_url_islocal(cg_var *url)
{
    return strcmp(cv_urlproto_get(url), "file") == 0;
}

/*
 * Convert a file-path to a file:/// url
 */
int
clicon_path2url(char *path, cg_var *cgv)
{
    int ret = -1;
    char **vec;
    char *urlstr;
    char cwd[PATH_MAX];

    /* Get current directory */
    if(getcwd (cwd, sizeof(cwd)) == NULL)
	strcpy(cwd, "/");
    
    /* Get real path */
    if ((vec = clicon_realpath(cwd, path, __FUNCTION__))==NULL)
	goto catch;
    
    if ((urlstr = chunk_sprintf(__FUNCTION__, "file://%s", vec[0])) == NULL)
	goto catch;
    cv_type_set(cgv, CGV_URL);
    if (cv_parse(urlstr, cgv) < 0)
	goto catch;

    ret = 0;
catch:
    unchunk_group(__FUNCTION__);
    return ret;
}

/*
 * Format an URL string from a cg_var struct.
 * The returned string will be chunk:ed using 'label'
 */
char *
clicon_url_sprint(cg_var *url, const char *label)
{
  char *res = NULL;
  char *path = cv_urlpath_get(url);

  if (!url || cv_type_get(url) != CGV_URL)
    return NULL;

  /* Format URL */
  while (*path && *path == '/')
    path++;
  res = chunk_sprintf(label, "%s://%s%s%s%s%s/%s",
		      cv_urlproto_get(url),
		      (cv_urluser_get(url)&&strlen(cv_urluser_get(url))) ?  cv_urluser_get(url) : "",
		      (cv_urlpasswd_get(url)&&strlen(cv_urlpasswd_get(url))) ? ":" : "",
		      (cv_urlpasswd_get(url)&&strlen(cv_urlpasswd_get(url))) ? cv_urlpasswd_get(url)  : "",
		      (cv_urluser_get(url)&&strlen(cv_urlpasswd_get(url))) ?  "@" : "",
		      cv_urladdr_get(url),
		      path);
     
  return res;
}

/*
 * Progress bar code borrowed from cURL source. 
 *
 COPYRIGHT AND PERMISSION NOTICE

 Copyright (c) 1996 - 2009, Daniel Stenberg, <daniel@haxx.se>.

 All rights reserved.

 Permission to use, copy, modify, and distribute this software for any purpose
 with or without fee is hereby granted, provided that the above copyright
 notice and this permission notice appear in all copies.

 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS. IN
 NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE
 OR OTHER DEALINGS IN THE SOFTWARE.

 Except as contained in this notice, the name of a copyright holder shall not
 be used in advertising or otherwise to promote the sale, use or other dealings
 in this Software without prior written authorization of the copyright holder.
 */
struct ProgressData {
  int calls;
  curl_off_t prev;
  int width;
  FILE *out; /* where to write everything to */
  curl_off_t initial_size;
  char *pfx; /* Bar prefix */
};

static int myprogress (void *clientp,
                       double dltotal,
                       double dlnow,
                       double ultotal,
                       double ulnow)
{
  /* The original progress-bar source code was written for curl by Lars Aas,
     and this new edition inherits some of his concepts. */

  char line[256];
  char outline[256];
  char format[40];
  double frac;
  double percent;
  int barwidth;
  int num;
  int i;

  struct ProgressData *bar = (struct ProgressData *)clientp;
  curl_off_t total = (curl_off_t)dltotal + (curl_off_t)ultotal +
    bar->initial_size; /* expected transfer size */
  curl_off_t point = (curl_off_t)dlnow + (curl_off_t)ulnow +
    bar->initial_size; /* we've come this far */

  if(point > total)
    /* we have got more than the expected total! */
    total = point;

  bar->calls++; /* simply count invokes */

  if(total < 1) {
    curl_off_t prevblock = bar->prev / 1024;
    curl_off_t thisblock = point / 1024;
    while ( thisblock > prevblock ) {
      fprintf( bar->out, "#" );
      prevblock++;
    }
  }
  else {
    frac = (double)point / (double)total;
    percent = frac * 100.0f;
    barwidth = bar->width - 7 - strlen(bar->pfx);
    num = (int) (((double)barwidth) * frac);
    for ( i = 0; i < num; i++ ) {
      line[i] = '#';
    }
    line[i] = '\0';
    snprintf(format, sizeof(format), "%s%%-%ds %%5.1f%%%%", bar->pfx, barwidth);
    snprintf(outline, sizeof(outline), format, line, percent );
    fprintf(bar->out, "\r%s", outline );
  }
  fflush(bar->out);
  bar->prev = point;

  return 0;
}

static
void progressbarinit(struct ProgressData *bar, char *pfx)
{
#ifdef __EMX__
  /* 20000318 mgs */
  int scr_size [2];
#endif
  char *colp;

  memset(bar, 0, sizeof(struct ProgressData));
  bar->pfx = pfx ? pfx : "";

/* TODO: get terminal width through ansi escapes or something similar.
         try to update width when xterm is resized... - 19990617 larsa */
#ifndef __EMX__
  /* 20000318 mgs
   * OS/2 users most likely won't have this env var set, and besides that
   * we're using our own way to determine screen width */
  colp = getenv("COLUMNS");
  if (colp != NULL)
    bar->width = atoi(colp);
  else
    bar->width = 79;
#else
  /* 20000318 mgs
   * We use this emx library call to get the screen width, and subtract
   * one from what we got in order to avoid a problem with the cursor
   * advancing to the next line if we print a string that is as long as
   * the screen is wide. */

  _scrsize(scr_size);
  bar->width = scr_size[0] - 1;
#endif

  bar->out = stdout;
}
/* 
 * End of cURL progress bar code
 */




/*
 * cURL callback. Write received date to FILE.
 */
static size_t
clicon_curl_get_cb(void *buffer, size_t size, size_t nmemb, void *stream)
{
  FILE *f = (FILE *)stream;
  return fwrite(buffer, size, nmemb, f);
}



/* 
 * Copy file from one URL to another.
 * Returns -1 on failure, 0 on success.
 */
int
clicon_curl_copy(cg_var *src, cg_var *dst, long conntimeout)
{
  char *err;
  char *tmp;
  int tmpfd = -1;
  int doprogress;
  FILE *tmpf = NULL;
  int ret = -1;
  CURL *curl;
  CURLcode res;
  char *srcurl;
  char *dsturl;
  struct ProgressData progressbar;

  curl_global_init(CURL_GLOBAL_DEFAULT);

  /* Create temp file stream */
  if ((tmp = chunk_sprintf(__FUNCTION__, "%s", "/tmp/cliconXXXXXX")) == NULL) {
    clicon_err(OE_UNDEF, errno, "chunk_sprintf");
    goto catch;
  }
  if ((tmpfd = mkstemp(tmp)) < 0) {
    clicon_err(OE_UNDEF, errno, "mkstemp");
    goto catch;
  }
  if ((tmpf = fdopen (tmpfd, "w+")) == NULL) {
    clicon_err(OE_UNDEF, errno, "fdopen");
    goto catch;
  }


  /* Allocate error buffer for curl */
  if ((err = chunk(CURL_ERROR_SIZE, __FUNCTION__)) == NULL) {
    clicon_err(OE_UNDEF, errno, "chunk");
    goto catch;
  }

  srcurl = clicon_url_sprint(src, __FUNCTION__);
  dsturl = clicon_url_sprint(dst, __FUNCTION__);
  if (srcurl == NULL || dsturl == NULL)
    goto catch;

  /*
   * Retrieve source file
   */
  if ((curl = curl_easy_init()) == NULL) {
    clicon_err(OE_UNDEF, errno, "curl_easy_init");
    goto catch;
  }
  curl_easy_setopt(curl, CURLOPT_URL, srcurl);
  curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, clicon_curl_get_cb);
  curl_easy_setopt(curl, CURLOPT_WRITEDATA, tmpf);
  curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, err);
  curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, conntimeout);
  if(clicon_url_islocal(src)) {
    doprogress = 0;
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L); 
  }
  else {
    doprogress = 1;
    progressbarinit(&progressbar, "RETR ");
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L); 
    curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, myprogress);
    curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &progressbar);
  }

  /*  curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);*/  /* protocol/debug output */
  res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);   /* cleanup */ 
  if (res != CURLE_OK) {
    clicon_err(OE_UNDEF, 0, "curl: %s", err);
    goto catch;
  }
  if (doprogress)
    fputs("\n", progressbar.out);
  
  /* Rewind tmp file */
  rewind (tmpf);

  /* 
   * Copy temp file to destination 
   */
  if ((curl = curl_easy_init()) == NULL) {
    clicon_err(OE_UNDEF, errno, "curl_easy_init");
    goto catch;
  }
  curl_easy_setopt(curl, CURLOPT_URL, dsturl);
  curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L); 
  curl_easy_setopt(curl, CURLOPT_READDATA, tmpf);
  curl_easy_setopt(curl, CURLOPT_ERRORBUFFER, err);
  curl_easy_setopt(curl, CURLOPT_CONNECTTIMEOUT, conntimeout);
  /* curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);*/ /* protocol/debug output */
  if(clicon_url_islocal(dst)) {
    doprogress = 0;
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 1L); 
  }
  else {
    doprogress = 1;
    progressbarinit(&progressbar, "SEND ");
    curl_easy_setopt(curl, CURLOPT_NOPROGRESS, 0L); 
    curl_easy_setopt(curl, CURLOPT_PROGRESSFUNCTION, myprogress);
    curl_easy_setopt(curl, CURLOPT_PROGRESSDATA, &progressbar);
  }

  res = curl_easy_perform(curl);
  curl_easy_cleanup(curl);   /* cleanup */ 
  if (res != CURLE_OK) {
    clicon_err(OE_UNDEF, 0, "curl: %s", err);
    goto catch;
  }
  if (doprogress)
    fputs("\n", progressbar.out);


  ret = 0;
  /* Fall through */

catch:
  curl_global_cleanup();
  if (tmpf)
    fclose (tmpf);
  else if (tmpfd != -1)
    close (tmpfd);
  if (tmp)
    unlink(tmp);
  unchunk_group(__FUNCTION__);
  return ret;
}
