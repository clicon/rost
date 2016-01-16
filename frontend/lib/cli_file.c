/*
 *  CVS Version: $Id: cli_file.c,v 1.9 2013/08/09 13:27:46 olof Exp $
 *
 *  Copyright (C) 2009-2014 Olof Hagsand and Benny Holmgren
 *
 *  This file is part of ROST.
 *
 *  ROST is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  ROST is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along wth ROST; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 * * 
 */

#ifdef HAVE_ROST_CONFIG_H
#include "rost_config.h" /* generated by config & autoconf */
#endif /* HAVE_ROST_CONFIG_H */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <libgen.h>
#include <signal.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <ctype.h>
#include <fcntl.h>
#include <netinet/in.h>

/* cligen */
#include <cligen/cligen.h>

/* clicon */
#include <clicon/clicon.h>
#include <clicon/clicon_cli.h>

/* lib */
#include "cli_curl.h"
#include "cli_system.h"

#include "cli_file.h"

/*
 * URL has local "protocol"?
 * ROST version where flash:// is also valid
 */
int
cli_url_islocal(cg_var *url)
{
    return 
	strcmp(cv_urlproto_get(url), "flash") == 0 ||
	strcmp(cv_urlproto_get(url), "file") == 0;
}


/*
 * Check for a file's existence and ask user to confirm overwriting?
 * Returns:
 *	0 if file does not exist or overwriting is confirmed.
 *	1 if overwriting it not confirmed
 *     -1 in case of error
 */
int
cli_overwrite(cg_var *cgv)
{
  int res = -1;
  struct stat st;
  char *path, *ptr;
  int nslash = 2;

  if (cv_type_get(cgv) != CGV_URL)
    return -1;

  if (!cli_url_islocal(cgv))
    return 0; /* Only check local files for now */

  /* Get a URL string */
  if ((path = clicon_url_sprint(cgv, __FUNCTION__)) == NULL)
    goto catch;
  /* Step forward to first path slash */
  ptr = path;
  while (nslash > 0 && (ptr = strchr(ptr, '/'))) {
    ptr++;
    nslash--;
  }
  if (!ptr || *ptr != '/')
    goto catch;
  path = ptr;
  
  /* Does target file exist?  XXX Only check local files for now */
  if (stat (path, &st) != 0) {
    if (errno != ENOENT) {
      perror(strrchr(path, '/')+1);
      goto catch;
    }
    else 
      res = 0;
  }
  else {
    if (!S_ISREG(st.st_mode)) {
      cli_output(stderr, "Target is not a regular file.\n");
      goto catch;
    }
    if (cli_yesno("Overwrite %s ? [y/N] ", strrchr(path, '/')+1) <= 0) {
	cli_output(stdout, "Aborted\n");
	res = 1;
    } else {
	res = 0;
    }

  }
  
 catch:
  unchunk_group(__FUNCTION__);
  return res;
}


/*
 * Copy between two URLs. 'from_url' and 'to_url' may be strings as well
 * in which case they are treated as local file:
 */ 
int 
cli_copy (clicon_handle h, cg_var *from_url, cg_var *to_url, int override)
{
  int ret = -1;
  char *from;
  cg_var *from_cv = NULL;
  cg_var *to_cv = NULL; 
  char *dest;
  char *tmp;
  char *save = NULL;
  char *dir;
#ifdef notyet
  struct sigaction old, new;
#endif
  struct stat st;

  if ((from_cv = cv_new(CGV_URL)) == NULL){
      cli_output(stderr, "%s: %s\n", __FUNCTION__, strerror(errno));
      goto catch;
  }
  if ((to_cv = cv_new(CGV_URL)) == NULL){
      cli_output(stderr, "%s: %s\n", __FUNCTION__, strerror(errno));
      goto catch;
  }

  /* Source is a string, let's convert to url */
  if (cv_type_get(from_url) == CGV_STRING) {
      if(clicon_path2url(cv_string_get(from_url), from_cv) < 0) {
	  cli_output(stderr, "Failed to convert source to URL\n");
	  goto catch;
      }
  }
  else
      cv_cp(from_cv, from_url);

  /* If local, check access */
  if (cli_url_islocal(from_cv)) {
    from = chunk_sprintf(__FUNCTION__,"%s%s",
			 cv_urlpath_get(from_cv)[0] != '/' ? "/" : "",
			 cv_urlpath_get(from_cv));
    if (access(from, R_OK) < 0) {
      cli_output(stderr, "%s: %s\n", from, strerror(errno));
      goto catch;
    }
    unchunk(from);
  }

  /* Destination is a string, let's convert to url */
  if (cv_type_get(to_url) == CGV_STRING) {
      if(clicon_path2url(cv_string_get(to_url), to_cv) < 0) {
	  cli_output(stderr, "Failed to convert destination to URL\n");
	  goto catch;
      }
  }
  else
      cv_cp(to_cv, to_url);

  /* Make destination path string */
  dest = chunk_sprintf(__FUNCTION__,"%s%s",
		       cv_urlpath_get(to_cv)[0] != '/' ? "/" : "",
		       cv_urlpath_get(to_cv));
  if (dest == NULL) {
      cli_output(stderr, "Failed to allocate memory\n");
      goto catch;
  }

  /* If destination path is a directory, append from-file basename */
  if(dest[strlen(dest)-1]=='/' ||
     (cli_url_islocal(to_cv) && lstat(dest, &st)==0 && S_ISDIR(st.st_mode))) {
      tmp = chunk_sprintf(__FUNCTION__, "%*s%s", 
		 dest[strlen(dest)-1]=='/' ? strlen(dest)-1 : strlen(dest),
			  dest,
			  strrchr(cv_urlpath_get(from_cv),'/'));
      if (tmp) {
	  free(cv_urlpath_get(to_cv)); /* XXX */
	  cv_urlpath_set(to_cv, tmp);
      }
      if (tmp == NULL || cv_urlpath_get(to_cv) == NULL) {
	  cli_output(stderr, "Failed to allocate memory\n");
	  goto catch;
      }
      unchunk(dest);
      dest = tmp;
  }

  if (cli_url_islocal(to_cv)) {

      if (override == 0)
	  if (cli_overwrite(to_cv) != 0)
	      goto catch;
      
      if ((dir = chunkdup(dest, strlen(dest)+1, __FUNCTION__))==NULL) {
	  cli_output(stderr, "Failed to allocate memory\n");
	  goto catch;
      }
      
      /* If flash: url, copy to tmp and then copy via clicon_config */    
      if (!strncmp(dest, ROST_IMAGE_DIR, strlen(ROST_IMAGE_DIR)) || 
	  !strncmp(dest, ROST_CONFIG_DIR, strlen(ROST_CONFIG_DIR))) {
	  save = strdup(cv_urlpath_get(to_cv));
	  if ((cv_urlpath_set(to_cv, clicon_tmpfile(__FUNCTION__))) == NULL) {
	      cli_output(stderr, "s: %s\n", __FUNCTION__, strerror(errno));
	      goto catch;
	  }
//	  to_cv->var_urlpath++; /* Move past '/' */ /* XXX */
	  cv_urlpath_set(to_cv, save+1);
      }
      else
	  if (access(dest, W_OK) < 0 && access(dirname(dir), W_OK) < 0) {
	      cli_output(stderr, "Write access denied: %s\n", dest);
	      goto catch;
	  }
  }
  
#ifdef notyet
  new.sa_handler = cli_copy_interrupt;
  new.sa_flags = 0;
  
  sigaction (SIGINT, NULL, &old);
  sigaction (SIGINT, &new, NULL);
#endif

  /* Let cURL do the copying */
  if (clicon_curl_copy (from_cv, to_cv, 15L) < 0) {
    if (clicon_errno) {
      cli_output(stderr,  "%s: %s", clicon_strerror(clicon_errno), clicon_err_reason);
      if (clicon_suberrno)
	  cli_output(stderr, ": %s", strerror(clicon_suberrno));
      cli_output(stderr, "\n");
    }
    goto catch;
  }
  
  /* If flash/config destination, have clicon_config copy to final destination */
  if (save) {
      cv_urlpath_set(to_cv, save);
      free(save);
      save = NULL;
//      to_cv->var_urlpath--; /* Move back to '/' */ /* XXX */
      chmod (cv_urlpath_get(to_cv), S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
#if CLICON_VERSION_MAJOR >= 3 && CLICON_VERSION_MINOR >= 1
      if (clicon_rpc_copy(h, cv_urlpath_get(to_cv), dest) < 0)
	  goto catch;
#else
      {
	char       *s;
	if ((s = clicon_sock(h)) == NULL)
	    goto catch;
	if (clicon_proto_copy(s, cv_urlpath_get(to_cv), dest) < 0)
	    goto catch;
      }
#endif
  }

#ifdef notyet
  sigaction (SIGINT, &old, NULL);
#endif
  
  ret = 0;
 catch:
  if (save) {
      if (cv_urlpath_get(to_cv)[0] != '/'){
	  cv_urlpath_set(to_cv, save);
      }
      unlink(cv_urlpath_get(to_cv));
      free(save);
  }
  if (from_cv)
      cv_free(from_cv);
  if (to_cv)
      cv_free(to_cv);
  unchunk_group(__FUNCTION__);
  return ret;
}

/*
 * Just a wrapper around url_sanitize() to replace flash:
 */
static int
cli_url_sanitize(cg_var *url)
{
    int     ret = -1;
    char   *path = NULL;
    cg_var *cv = NULL; 

    if (!url || cv_type_get(url) != CGV_URL)
	return -1;
    
    /* Sanitize path */
    if (strstr(cv_urlpath_get(url), "..")) {
	clicon_err(OE_UNDEF, EINVAL, "Invalid path: %s", cv_urlpath_get(url));
	return -1;
    }

    if (strcmp(cv_urlproto_get(url), "flash"))
    	return 0;

    path = chunk_sprintf(__FUNCTION__, "%s/%s",ROST_IMAGE_DIR, cv_urlpath_get(url));
    if (path == NULL) {
	perror("chunk");
	goto catch;
    }
    if ((cv = cv_new(CGV_URL)) == NULL){
	cli_output(stderr, "%s: %s\n", __FUNCTION__, strerror(errno));
	goto catch;
    }
    if (clicon_path2url(path, cv) < 0) {
	cli_output(stderr, "Failed to convert path to URL\n");
	goto catch;
    }

    free(cv_urlpath_get(url));
    cv_urlpath_set(url, cv_urlpath_get(cv));
    free(cv_urlproto_get(url));
    cv_urlproto_set(url, cv_urlproto_get(cv)); 

    if (cv_urlpath_get(url) == NULL || cv_urlproto_get(url) == NULL) {
	cli_output(stderr, strerror(errno));
	goto catch;
    }
    
    ret = 0;

catch:
    if (cv)
	cv_free(cv);
    unchunk_group(__FUNCTION__);
    return ret;
}
 

/*
 * Copy between two sanitized URLs
 */
int 
cli_sanitized_copy (clicon_handle h, cg_var *from_url, cg_var *to_url, int override)
{
  if (cli_url_sanitize(from_url) < 0 || cli_url_sanitize(to_url) < 0)
    return -1;
  
  return cli_copy (h, from_url, to_url, override);
}

static char *
cli_copy_url_temp(clicon_handle h, cg_var *url, const char *label)
{
    char   *tmp;
    char   *tmpurl;
    cg_var *cv = NULL; 
    char   *ret = NULL;
    
    if ((tmp = clicon_tmpfile(__FUNCTION__)) == NULL)
	return NULL;
    if ((tmpurl = chunk_sprintf(__FUNCTION__, "file://%s", tmp)) == NULL) {
	fprintf(stderr, "chunk_sprintf: failed to allocate");
	goto catch;
    }
    if ((cv = cv_new(CGV_URL)) == NULL){
	cli_output(stderr, "%s: %s\n", __FUNCTION__, strerror(errno));
	goto catch;
    }
    if (cv_parse(tmpurl, cv) < 0) {
	fprintf(stderr, "failed to parse url");
	goto catch;
    }
    if (cli_copy(h, url, cv, 1) < 0)
	goto catch;
    
    ret = chunkdup(tmp, strlen(tmp)+1, label);

catch:
    unchunk_group(__FUNCTION__);
    if (ret == NULL)
	unlink(tmp);
    if (cv)
	cv_free(cv);

    return ret;
}



/*
 * Copy startup-config to URL
 */
int
cli_copy_startup_url(clicon_handle h, cvec *vars, cg_var *arg)
{
    cg_var *cv = NULL; 
    char   *startup;
    int     retval = -1;
    cg_var *cv1 = cvec_i(vars, 1);

    if ((startup = chunk_sprintf(__FUNCTION__, "file://%s", 
				 clicon_startup_config(h))) == NULL) {
	fprintf(stderr, "chunk_sprintf: failed to allocate");
	goto catch;
    }

    if (cli_url_sanitize(cv1) < 0)
	goto catch;
    if ((cv = cv_new(CGV_URL)) == NULL){
	cli_output(stderr, "%s: %s\n", __FUNCTION__, strerror(errno));
	goto catch;
    }
    if (cv_parse(startup, cv) < 0)
	goto catch;

    if (cli_copy(h, cv, cv1, 0) < 0)
	goto catch;
    retval = 0;
  catch:
    if (cv)
	cv_free(cv);
    unchunk_group(__FUNCTION__);
    return retval;
}

/*
 * Load startup-config to running-config
 */
int
cli_copy_startup_running(clicon_handle h, cvec *vars, cg_var *arg)
{
    char *dbname = clicon_candidate_db(h);
    char *running_db   = clicon_running_db(h);

    /* will autocommit to current */
#if CLICON_VERSION_MAJOR >= 3 && CLICON_VERSION_MINOR >= 1
    if (clicon_rpc_load(h, 1, dbname, clicon_startup_config(h)) < 0)
	return -1;
    if (clicon_autocommit(h))
	if (clicon_rpc_commit(h, running_db, dbname, 0, 0) < 0)
	    return -1;
#else
    char *s;

    if ((s = clicon_sock(h)) == NULL)
	return -1;
    if (clicon_proto_load(s, 1, dbname, clicon_startup_config(h)) < 0)
	return -1;
    if (clicon_autocommit(h))
	if (clicon_proto_commit(s, running_db, dbname, 0, 0) < 0)
	    return -1;
#endif
    return 0;
}

/*
 * Copy URL to startup-config
 */
int
cli_copy_url_startup(clicon_handle h, cvec *vars, cg_var *arg)
{
  char   *tmp;
  char   *tmpurl;
  cg_var *cv = NULL;
  int     res = -1;
  char   *s;
  cg_var *cv1 = cvec_i(vars, 1);
  
  tmp = chunk_sprintf(__FUNCTION__, "/tmp/.temp-config.%u", getpid());
  tmpurl = chunk_sprintf(__FUNCTION__, "file://%s", tmp);
  if ((s = clicon_sock(h)) == NULL)
      return -1;
  if (tmp == NULL || tmpurl == NULL) {
    fprintf(stderr, "chunk_sprintf: failed to allocate");
    goto catch;
  }
  
  if (cli_url_sanitize(cv1) < 0)
    goto catch;

  if ((cv = cv_new(CGV_URL)) == NULL){
      cli_output(stderr, "%s: %s\n", __FUNCTION__, strerror(errno));
      goto catch;
  }

  if (cv_parse(tmpurl, cv) < 0)
    goto catch;

  if (cli_copy(h, cv1, cv, 0) < 0)
      goto catch;


#if CLICON_VERSION_MAJOR >= 3 && CLICON_VERSION_MINOR >= 1
  if (clicon_rpc_copy(h, tmp, clicon_startup_config(h)) < 0){
#else
  if (clicon_proto_copy(s, tmp, clicon_startup_config(h)) < 0){
#endif
    fprintf(stderr, "Error when copying file: %s\n", 
	    strerror(errno));
    goto catch;
  }

  res = 0;
  
  /* Fall through */
 catch:
  if (tmp)
#if CLICON_VERSION_MAJOR >= 3 && CLICON_VERSION_MINOR >= 1
      clicon_rpc_rm(h, tmp);
#else
      clicon_proto_rm(s, tmp);
#endif
  if (cv)
      cv_free(cv);
  unchunk_group(__FUNCTION__);
  return res;
}

/*
 * Load URL to running-config
 * arg is 'override/replace'
 */
int
cli_copy_url_running(clicon_handle h, cvec *vars, cg_var *arg)
{
  char   *tmp;
  char   *tmpurl;
  cg_var *cv = NULL;
  int     res = -1;
  int     override = cv_int_get(arg);
  char   *dbname = clicon_candidate_db(h);
  char   *running_db = clicon_running_db(h);
  char   *s;
  cg_var *cv1 = cvec_i(vars, 1);

  tmp = clicon_tmpfile(__FUNCTION__);
  tmpurl = chunk_sprintf(__FUNCTION__, "file://%s", tmp);
  if (tmp == NULL || tmpurl == NULL) {
      fprintf(stderr, "chunk_sprintf: failed to allocate");
      goto catch;
  }
  if ((s = clicon_sock(h)) == NULL)
      goto catch;

  if ((cv = cv_new(CGV_URL)) == NULL){
      cli_output(stderr, "%s: %s\n", __FUNCTION__, strerror(errno));
      goto catch;
  }
  if (cv_parse(tmpurl, cv) < 0)
      goto catch;
  
  if (cli_url_sanitize (cv1) < 0)
      goto catch;
  if ((res = cli_copy(h, cv1, cv, 1)) < 0)
      goto catch;
#if CLICON_VERSION_MAJOR >= 3 && CLICON_VERSION_MINOR >= 1
  if (clicon_rpc_load(h, override, dbname, tmp) < 0)
#else
  if (clicon_proto_load(s, override, dbname, tmp) < 0)
#endif
      goto catch;
  if (clicon_autocommit(h))
#if CLICON_VERSION_MAJOR >= 3 && CLICON_VERSION_MINOR >= 1
      if (clicon_rpc_commit(h, running_db, dbname, 0, 0) < 0)
#else
      if (clicon_proto_commit(s, running_db, dbname, 0, 0) < 0)
#endif
	  goto catch;
  res = 0;
  /* Fall through */
catch:
  if (tmp)
      unlink(tmp);
  if (cv)
      cv_free(cv);
  unchunk_group(__FUNCTION__);
  return res;
}

/*
 * Copy between two URLs
 */
int
cli_copy_url_url(clicon_handle h, cvec *vars, cg_var *arg)
{
    cg_var *cv1 = cvec_i(vars, 1);
    cg_var *cv2 = cvec_i(vars, 2);

    return cli_sanitized_copy (h, cv1, cv2, 0);
}

/*
 * Copy running-config to URL
 * Argument is database
 */
static int
cli_copy_db_url(clicon_handle h, cvec *vars, cg_var *arg)
{
  char   *tmp;
  char   *tmpurl;
  cg_var *cv = NULL; 
  int     res = -1;
  char   *dbname = cv_string_get(arg);
  char   *s;
  cg_var *cv1 = cvec_i(vars, 1);

  if ((s = clicon_sock(h)) == NULL)
      return -1;

  tmp = chunk_sprintf(__FUNCTION__, "/tmp/.temp-config.%u", getpid());
  tmpurl = chunk_sprintf(__FUNCTION__, "file://%s", tmp);
  if (tmp == NULL || tmpurl == NULL) {
    fprintf(stderr, "chunk_sprintf: failed to allocate");
    goto catch;
  }
  
#if CLICON_VERSION_MAJOR >= 3 && CLICON_VERSION_MINOR >= 1
  if (clicon_rpc_save(h, dbname, 0, tmp) < 0)
#else
  if (clicon_proto_save(s, dbname, 0, tmp) < 0)
#endif
      goto catch;

  if ((cv = cv_new(CGV_URL)) == NULL){
      cli_output(stderr, "%s: %s\n", __FUNCTION__, strerror(errno));
      goto catch;
  }
  if (cv_parse(tmpurl, cv) < 0)
    goto catch;
  
  if (cli_url_sanitize(cv1) < 0)
    goto catch;

  res = cli_copy (h, cv, cv1, 0);

  /* Fall through */
 catch:
  if (tmp)
#if CLICON_VERSION_MAJOR >= 3 && CLICON_VERSION_MINOR >= 1
      clicon_rpc_rm(h, tmp);
#else
      clicon_proto_rm(s, tmp);
#endif
  if (cv)
      cv_free(cv);
  unchunk_group(__FUNCTION__);
  return res;
}

int
cli_copy_running_url(clicon_handle h, cvec *vars, cg_var *arg)
{
    cg_var *cv = NULL; 
    
  if ((cv = cv_new(CGV_STRING)) == NULL){
      cli_output(stderr, "%s: %s\n", __FUNCTION__, strerror(errno));
      return 0;
  }
    if (cv_parse(clicon_running_db(h), cv) < 0) {
	cli_output(stderr, "Failed to parse string to cgv\n");
	return 0;
    }
    cli_copy_db_url(h, vars, cv);
    cv_free(cv);
    return 0;
}

int
cli_copy_candidate_url(clicon_handle h, cvec *vars, cg_var *arg)
{
    cg_var *cv = NULL; 

    if ((cv = cv_new(CGV_STRING)) == NULL){
	cli_output(stderr, "%s: %s\n", __FUNCTION__, strerror(errno));
	return 0;
    }
    if (cv_parse(clicon_candidate_db(h), cv) < 0) {
	cli_output(stderr, "Failed to parse string to cgv\n");
	return 0;
    }
    cli_copy_db_url(h, vars, cv);
    cv_free(cv);
    return 0;
}


/*
 * Save running-config to startup-config
 */
int
cli_copy_running_startup(clicon_handle h, cvec *vars, cg_var *arg)
{
    char *s, *c;

    if ((s = clicon_sock(h)) == NULL)
	return -1;
    if ((c = clicon_startup_config(h)) == NULL)
	return -1;
#if CLICON_VERSION_MAJOR >= 3 && CLICON_VERSION_MINOR >= 1
    return clicon_rpc_save(h, clicon_running_db(h), 0, c);
#else
    return clicon_proto_save(s, clicon_running_db(h), 0, c);
#endif
}


/*
 * List directory
 */
int
cli_dir (clicon_handle h, cvec *vars, cg_var *arg)
{
  char *file = "";
  char *cmd = NULL;
  cg_var *cv1 = cvec_i(vars, 1);

  if (cvec_len(vars) > 1)
      file = chunk_sprintf(__FUNCTION__, "/%s", cv_string_get(cv1));

  if (!strcmp(cv_string_get(arg), "HOME"))
    cmd = chunk_sprintf(__FUNCTION__, "ls -lF %s%s", getenv("HOME"), file);
  else if (!strcmp(cv_string_get(arg), "FLASH")) 
    cmd = chunk_sprintf(__FUNCTION__, "ls -lF %s%s", ROST_IMAGE_DIR, file);
  else {
      cli_output(stderr, "Unknown filesystem\n");
      goto catch;
  }
  if (cmd)
    clicon_proc_run(cmd, cli_output_formatted, 1);

 catch:
  unchunk_group(__FUNCTION__);
  return 0;
}



/*
 * Show file contents
 */
int
cli_more_url (clicon_handle h, cvec *vars, cg_var *arg)
{
    char *cmd;
    char *tmp;
    char *tmpurl;
    cg_var *cv = NULL;
    cg_var *cv1 = cvec_i(vars, 1);
    
    tmp = clicon_tmpfile(__FUNCTION__);
    tmpurl = chunk_sprintf(__FUNCTION__, "file://%s", tmp);
    if (tmp == NULL || tmpurl == NULL) {
	fprintf(stderr, "chunk_sprintf: failed to allocate");
	goto catch;
    }
    
    if ((cv = cv_new(CGV_URL)) == NULL){
	cli_output(stderr, "%s: %s\n", __FUNCTION__, strerror(errno));
	goto catch;
    }
    if (cv_parse(tmpurl, cv) < 0) {
	fprintf(stderr, "failed to parse url");
	goto catch;
    }

    if (cli_copy(h, cv1, cv, 1) < 0)
	goto catch;

    if ((cmd = chunk_sprintf(__FUNCTION__, "cat %s", tmp)) == NULL) {
	fprintf(stderr, "chunk_sprintf: failed to allocate");
	goto catch;
    }
    clicon_proc_run(cmd, cli_output_formatted, 1);
    unlink(tmp);
    
catch:
    if (cv)
	cv_free(cv);
  unchunk_group(__FUNCTION__);
  return 0;
}

/*
 * Show file contents
 */
int
cli_more (clicon_handle h, cvec *vars, cg_var *arg)
{
  char   *file = "";
  char   *cmd = NULL;
  cg_var *cv1 = cvec_i(vars, 1);

  if (cvec_len(vars) > 1)
      file = chunk_sprintf(__FUNCTION__, "%s", cv_string_get(cv1));

  if (!strcmp(cv_string_get(arg), "CWD"))
    cmd = chunk_sprintf(__FUNCTION__,"cat %s/%s", getcwd(NULL, PATH_MAX), file);
  else if (!strcmp(cv_string_get(arg), "HOME"))
    cmd = chunk_sprintf(__FUNCTION__, "cat %s/%s", getenv("HOME"), file);
  else if (!strcmp(cv_string_get(arg), "FLASH")) 
    cmd = chunk_sprintf(__FUNCTION__, "cat %s/%s", ROST_IMAGE_DIR, file);
  else if (strcmp (cv_string_get(arg), "CONFIG") == 0) 
    cmd = chunk_sprintf(__FUNCTION__, "cat %s/%s", ROST_CONFIG_DIR, file);
  else
    cmd = chunk_sprintf(__FUNCTION__, "cat %s", file);
  if (cmd)
    clicon_proc_run(cmd, cli_output_formatted, 1);

  unchunk_group(__FUNCTION__);
  return 0;
}

int
cli_show_file (clicon_handle h, cvec *vars, cg_var *arg)
{
    char *filename = cv_string_get(arg);
    char buf[64];
    FILE *f;

    if ((f = fopen(filename, "r")) == NULL){
	fprintf(stderr, "fopen(%s): %s\n", filename, strerror(errno));
	return -1;
    }
    while (fgets(buf, sizeof(buf), f) != NULL)
	cli_output(stdout, buf);
    return 0;
}


/*
 * Run "diff" on two files using specified diff-args.
 */
int
cli_diff (clicon_handle h, cvec *vars, cg_var *arg)
{
    char *cmd;
    char *file1;
    char *file2;
    int istmp1 = 0;
    int istmp2 = 0;
    char *diffargs = cv_string_get(arg);
    cg_var *cv1 = cvec_i(vars, 1);
    cg_var *cv2 = cvec_i(vars, 2);

    if (cv_type_get(cv1) == CGV_URL) {
	file1 = cli_copy_url_temp(h, cv1, __FUNCTION__);
	istmp1 = 1;
    } else
	file1 =  chunk_sprintf(__FUNCTION__, "%s", cv_string_get(cv1));
    
    if (cv_type_get(cv2) == CGV_URL) {
	file2 = cli_copy_url_temp(h, cv2, __FUNCTION__);
       istmp2 = 1;
    } else
	file2 =  chunk_sprintf(__FUNCTION__, "%s", cv_string_get(cv2));
    
    if (file1 == NULL || file2 == NULL) {
	cli_output(stderr, "Failed to resolve files\n");
	goto catch;
    }
    
    cmd = chunk_sprintf(__FUNCTION__, "diff%s%s %s %s", 
			(diffargs && strlen(diffargs) ? " " : ""),
			(diffargs && strlen(diffargs) ? diffargs : ""),
			file1, file2);
    if (cmd == NULL) {
	cli_output(stderr, "Failed to allocated command\n");
	goto catch;
    }
    
    clicon_proc_run(cmd, cli_output_formatted, 1);

catch:
    if(istmp1 && file1)
	unlink(file1);
    if(istmp2 && file2)
	unlink(file2);
    unchunk_group(__FUNCTION__);
    return 0;
}

/*
 * cligen callback to cli_copy()
 */
int
cli_file_copy (clicon_handle h, cvec *vars, cg_var *arg)
{
    cg_var *cv1 = cvec_i(vars, 1);
    cg_var *cv2 = cvec_i(vars, 2);

    cli_copy(h, cv1, cv2, 0);
    return 0;
}

/*
 * Delete file
 */
int
cli_file_del (clicon_handle h, cvec *vars, cg_var *arg)
{
  char   *path;
  char  **vec;
  int     ret;
  struct stat st;
  char   *s;
  cg_var *cv1 = cvec_i(vars, 1);

  vec = clicon_realpath(cv_string_get(arg), cv_string_get(cv1), __FUNCTION__);
  if (vec == NULL) {
      perror(cv_string_get(cv1));
      goto catch;
  }
  path = vec[0];
  if (stat (path, &st) < 0) {
      perror(path);
    goto catch;
  }
  if (!S_ISREG(st.st_mode)) {
    cli_output(stderr, "Target is not a regular file.\n");
    goto catch;
  }

  if (cli_yesno("Delete %s ? [y/N] ", strrchr(path, '/')+1) <= 0) {
    cli_output(stdout, "Aborted\n");
    goto catch;
  }
  
  if (!strncmp(path, ROST_IMAGE_DIR, strlen(ROST_IMAGE_DIR)) ||
      !strncmp(path, ROST_CONFIG_DIR, strlen(ROST_CONFIG_DIR))){
      if ((s = clicon_sock(h)) == NULL)
	  goto catch;
#if CLICON_VERSION_MAJOR >= 3 && CLICON_VERSION_MINOR >= 1
      ret = clicon_rpc_rm(h, path);
#else
      ret = clicon_proto_rm(s, path);
#endif
  }
  else 
    ret = unlink(path);
  if (ret < 0) {
    perror("Failed to unlink file");
    goto catch;
  }

 catch:
  unchunk_group(__FUNCTION__);
  return 0;
}
