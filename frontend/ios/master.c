/*
 *  CVS Version: $Id: master.c,v 1.31 2014/01/09 04:32:16 benny Exp $
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <syslog.h>
#include <assert.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/param.h>
#include <net/if.h>
#include <netinet/in.h>

/* clicon */
#include <cligen/cligen.h>
#include <clicon/clicon.h>
#include <clicon/clicon_cli.h>

/* rost lib */
#include <quaggapi.h>

/* local */
#include "ios.h"

/* Current CLI mode */
struct qa_mode cli_mode = {QA_MODE_BASE, };

/* tree of cli modes */
struct ios_mode ios_tree[] = { 
    { IOS_MODE_NONE, IOS_MODE_NONE, NULL, NULL },
    { IOS_MODE_BASE, IOS_MODE_NONE, MODE_BASE, "%U@%H>" },
    { IOS_MODE_ENABLE, IOS_MODE_NONE, MODE_ENABLE, "%U@%H#" },
    { IOS_MODE_CONFIG, IOS_MODE_ENABLE, MODE_CONFIG, "%U@%H(config)#"},
    { IOS_MODE_ACLSTD, IOS_MODE_CONFIG, MODE_ACLSTD, "%U@%H(config-std-acl)#"},
    { IOS_MODE_ACLNSTD, IOS_MODE_CONFIG, MODE_ACLNSTD, "%U@%H(config-std-nacl)#"},
    { IOS_MODE_ACLEXT, IOS_MODE_CONFIG, MODE_ACLEXT, "%U@%H(config-ext-acl)#"},
    { IOS_MODE_INTERFACE, IOS_MODE_CONFIG, MODE_INTERFACE, "%U@%H(config-if)#"},
    { IOS_MODE_RIP, IOS_MODE_CONFIG, MODE_RIP, "%U@%H(config-router)#"},
    { IOS_MODE_RIPNG, IOS_MODE_CONFIG, MODE_RIPNG, "%U@%H(config-router)#"},
    { IOS_MODE_OSPF, IOS_MODE_CONFIG, MODE_OSPF, "%U@%H(config-router)#"},
    { IOS_MODE_OSPF6, IOS_MODE_CONFIG, MODE_OSPF6, "%U@%H(config-router)#"},
    { IOS_MODE_BGP, IOS_MODE_CONFIG, MODE_BGP, "%U@%H(config-router)#"},
    { IOS_MODE_ISIS, IOS_MODE_CONFIG, MODE_ISIS, "%U@%H(config-router)#"},
    { IOS_MODE_ROUTE_MAP, IOS_MODE_CONFIG, MODE_ROUTEMAP, "%U@%H(config-route-map)#"},
    { IOS_MODE_MAX, IOS_MODE_NONE, NULL, NULL },
};



static int
cli_mode_num(const char *name)
{
    int i;

    for (i = IOS_MODE_BASE; i < IOS_MODE_MAX-1; i++)
	if (strcmp(name, ios_tree[i].im_stxmode)==0)
	    return ios_tree[i].im_mode;
    
    return -1;   
}



/*
 * Ctrl-Z cligen hook. Execute 'end' if in one of the config modes.
 */
int 
plugin_susp_hook (clicon_handle h, char *buf, int prompt_width, int *cursor_loc)
{
    int mode;

    mode = cli_mode_num(cli_syntax_mode(h));
    if (mode <= QA_MODE_ENABLE)
	return -1;
    
  strncpy(buf, "end\n\0", 5);
  *cursor_loc = strlen ("end");
  return -2;	/* Report things changed. */
}

/*
 * CLIgen parse hook. If command did not match current mode, return the next mode
 * up if we want to try matching in another mode.
 */
char *
plugin_parse_hook(clicon_handle h, char *cmd, char *name)
{
    int mode;

    mode = cli_mode_num(name);
    if (mode <= QA_MODE_CONFIG)
	return NULL;

    if (ios_tree[mode].im_up == IOS_MODE_NONE)
	return NULL;

    return ios_tree[ios_tree[mode].im_up].im_stxmode;
}

/*
 * interface callback for cli_set parser
 */
int
ios_interface_cb(cvec *vars, cg_var *cv, cg_var *arg)
{
    char *name;
    
    if ((name = cv_name_get(cv)) == NULL)
	return -1;

    if (*name == '!')
	name++;

    if (!strcmp (name, "name")) {
	cv_type_set(cv, CGV_STRING);
	cv_string_set(cv, cli_mode.u.iface);
	return 0;
    }

    if (!strcmp (name, "unit")) {
	cv_type_set(cv, CGV_INT);
	cv_int_set(cv, 0);  /* XXX No support for sub-interfaces yet */
	return 0;
    }

    return -1;    
}


/*
 * route-map callback for cli_set parser
 */
int
ios_routemap_cb(cvec *vars, cg_var *cv, cg_var *arg)
{
    char *name;
    
    if ((name = cv_name_get(cv)) == NULL)
	return -1;

    if (*name == '!')
	name++;

    if (!strcmp (name, "name")) {
	cv_type_set(cv, CGV_STRING);
	cv_string_set(cv, cli_mode.u.route_map.name);
	return 0;
    }
    
    if (!strcmp (name, "line")) {
	cv_type_set(cv, CGV_INT);
	cv_int_set(cv, (int)cli_mode.u.route_map.seq);
	return 0;
    }
    
    if (!strcmp (name, "action")) {
	cv_type_set(cv, CGV_STRING);
	cv_string_set(cv, (cli_mode.u.route_map.permit ? "permit" : "deny"));
	return 0;
    }
    
    return -1;    
}


int
plugin_init(clicon_handle h)
{
    int i;

    memset (&cli_mode, 0, sizeof (cli_mode));
    cli_mode.mode = IOS_MODE_BASE;

    /* Init all modes */
    for (i = IOS_MODE_BASE; i < IOS_MODE_MAX; i++) {

	/* Set prompt format */
	if (cli_set_prompt(h, ios_tree[i].im_stxmode, ios_tree[i].im_prompt) < 0)
	    cli_output(stderr, "Faled to set prompt format for group '%s'\n",
		       ios_tree[i].im_stxmode);
    }
    
	
    /* Set active syntax mode to IOS_MODE_BASE */
    if (cli_set_syntax_mode(h, MODE_BASE) == 0)
	cli_output(stderr, "Failed to set active syntax mode\n");


    /* Set comment character */
    cli_set_comment(h, '!');

    /* Set auto-commit mode */
    clicon_autocommit_set(h, 1);

    return 0;
}

static void
cli_mode_exit()
{
    switch (cli_mode.mode) {
    
    case IOS_MODE_ACLNSTD:
	free(cli_mode.u.aclname);
	cli_mode.u.aclname = NULL;
	break;

    case IOS_MODE_INTERFACE:
	free (cli_mode.u.iface);
	cli_mode.u.iface = NULL;
	break;

    case IOS_MODE_BGP:
	cli_mode.u.bgp_as = 0;
	break;

    case IOS_MODE_ROUTE_MAP:
	free (cli_mode.u.route_map.name);
	cli_mode.u.route_map.name = NULL;
	break;

    default:
	/* Nothing */
	break;
    }
}


/*
 * cli_del_modetree - Disable mode tree (router ospf, router rip etc..) and
 *                    also delete any underlying keys from db
 */
int
cli_del_modetree(clicon_handle h, cvec *vars, cg_var *arg)
{
    char *ptr;
    char *key;
    char *opcmd;
    int retval = -1;
    cg_var *cv = NULL; 

    key = cv_string_get(arg);
    for (ptr=key; *ptr && *ptr != ' '; ptr++) /* Do nothing */ ;
  
    /* First remove all child keys */
    opcmd = chunk_sprintf(__FUNCTION__, "^%.*s\\..*%s", ptr-key, key, ptr);
    if ((cv = cv_new(CGV_STRING)) == NULL){
	fprintf(stderr, "%s: cv_new: %s\n", __FUNCTION__, strerror(errno));
	goto done;
    }
    if(cv_parse(opcmd, cv) < 0) {
	perror("cv_parse");
	goto done;
    }
    if ((retval = cli_del(h, vars, cv)) < 0) {
	goto done;
    }
    retval = cli_del(h, vars, arg);

done:
    if (cv)
	cv_free(cv);
    unchunk_group(__FUNCTION__);

    return retval;
}


/*
 * cli_ios_mode
 * CISCO ios set mode
 */
int
cli_ios_mode(clicon_handle h, cvec *vars, cg_var *arg)
{
    char   *key;
    cg_var *cgv;
    cg_var *cgvs; 
    cg_var *cv0;
    cg_var *cv1;

    cli_mode_exit();	/* Free up old mode data */
    cli_mode.mode = cv_int_get(arg);

    assert (cli_mode.mode == ios_tree[cli_mode.mode].im_mode);
    if ((cgvs = cv_new(CGV_STRING)) == NULL){
	fprintf(stderr, "%s: cv_new: %s\n", __FUNCTION__, strerror(errno));
	return 0;
    }
    switch (cli_mode.mode) {
    case IOS_MODE_ACLSTD: {
	char *fmt;

	cv1 = cvec_i(vars, 1);
	cli_mode.u.aclid = cv_uint32_get(cv1);
	fmt = chunk_sprintf(__FUNCTION__,
			    "ipv4.access-list.standard[] $!id=(uint32)%u",
			    cli_mode.u.aclid);
	if (fmt == NULL || cv_parse(fmt, cgvs) < 0) {
	    if (fmt) unchunk(fmt);
	    cli_mode.mode = IOS_MODE_CONFIG;
	    break;
	}
	unchunk(fmt);
	cli_set (h, vars, cgvs);
	break;
    }
	
    case IOS_MODE_ACLEXT: {
	char *fmt;

	cv1 = cvec_i(vars, 1);
	cli_mode.u.aclid = cv_uint32_get(cv1);
	fmt = chunk_sprintf(__FUNCTION__,
			    "ipv4.access-list.extended[] $!id=(uint32)%u",
			    cli_mode.u.aclid);
	if (fmt == NULL || cv_parse(fmt, cgvs) < 0) {
	    if (fmt) unchunk(fmt);
	    cli_mode.mode = IOS_MODE_CONFIG;
	    break;
	}
	unchunk(fmt);
	cli_set (h, vars, cgvs);
	break;
    }

    case IOS_MODE_ACLNSTD: {
	char *fmt;

	cv1 = cvec_i(vars, 1);
	cli_mode.u.aclname = strdup(cv_string_get(cv1));
	fmt = chunk_sprintf(__FUNCTION__,
			    "ipv4.access-list.standard.named[] $!name=(string)%s",
			    cli_mode.u.aclname);
	if (fmt == NULL || cv_parse(fmt, cgvs) < 0) {
	    if (fmt) unchunk(fmt);
	    cli_mode.mode = IOS_MODE_CONFIG;
	    break;
	}
	unchunk(fmt);
	cli_set (h, vars, cgvs);
	break;
    }
	
   case IOS_MODE_INTERFACE:
	cv1 = cvec_i(vars, 1);
	cli_mode.u.iface = strdup(cv_string_get(cv1));
	if (cli_mode.u.iface == NULL) {
	    perror ("interface");
	    cli_mode.mode = IOS_MODE_CONFIG;
	    break;
	}
	if(cv_parse("interface[].unit[] $!name $!unit=(int)0", cgvs) < 0) {
	    perror("cv_parse");
	    free(cli_mode.u.iface);
	    cli_mode.mode = IOS_MODE_CONFIG;
	    break;
	}
	cli_set (h, vars, cgvs);
	break;
	
    case IOS_MODE_RIP:

	if(cv_parse("router.rip $instance=(int)0", cgvs) < 0) {
	    perror("cv_parse");
	    cli_mode.mode = IOS_MODE_CONFIG;
	    break;
	}
	cli_set (h, vars, cgvs);
	break;
	
    case IOS_MODE_RIPNG:
	if(cv_parse("router.ripng $instance=(int)0", cgvs) < 0) {
	    perror("cv_parse");
	    cli_mode.mode = IOS_MODE_CONFIG;
	    break;
	}
	cli_set (h, vars, cgvs);
	break;
	
    case IOS_MODE_OSPF:
	if(cv_parse("router.ospf $instance=(int)0", cgvs) < 0) {
	    perror("cv_parse");
	    cli_mode.mode = IOS_MODE_CONFIG;
	    break;
	}
	cli_set (h, vars, cgvs);
	break;

    case IOS_MODE_OSPF6:
	if(cv_parse("router.ospf6 $instance=(int)0", cgvs) < 0) {
	    perror("cv_parse");
	    cli_mode.mode = IOS_MODE_CONFIG;
	    break;
	}
	cli_set (h, vars, cgvs);
	break;
	
    case IOS_MODE_BGP:
	/* First check if we already have BGP configured */
	if ((cgv = dbvar2cv (clicon_running_db(h), "router.bgp", "as"))) {
	    cv1 = cvec_i(vars, 1);
	    if (cv_int_get(cgv) != cv_int_get(cv1)) {
		cli_output(stderr, "BGP is already running; AS is %d\n",
			   cv_int_get(cgv));
		cv_free(cgv);
		cli_mode.mode = ios_tree[cli_mode.mode].im_up;
		break;
	    }
	}

	if(cv_parse("router.bgp $as", cgvs) < 0) {
	    perror("cv_parse");
	    cli_mode.mode = IOS_MODE_CONFIG;
	    break;
	}
	cli_set (h, vars, cgvs);
	break;
	
#ifdef ROST_ISIS_SUPPORT
    case IOS_MODE_ISIS:
	if(cv_parse("router.isis $instance=(int)0", cgvs) < 0) {
	    perror("cv_parse");
	    cli_mode.mode = IOS_MODE_CONFIG;
	    break;
	}
	cli_set (h, vars, cgvs)
	break;
	
#endif
	
    case IOS_MODE_ROUTE_MAP:  {
	int nvec;
	char **vec;
	cg_var *cv2 = cvec_i(vars, 2);

	cv0 = cvec_i(vars, 0);
	cv1 = cvec_i(vars, 1);

	vec = clicon_strsplit (cv_string_get(cv0), " ", &nvec, NULL);
	if (!vec)
	    return 0;
	
	cli_mode.u.route_map.permit = strcmp(vec[2], "permit") ? 0 : 1;
	cli_mode.u.route_map.name = strdup (cv_string_get(cv1));
	cli_mode.u.route_map.seq = cv_int_get(cv2);
	cli_mode.mode = IOS_MODE_ROUTE_MAP;
	unchunk (vec);
	if (cli_mode.u.route_map.permit)
	    key = "route-map[].line[] $!name $!line $action=(string)\"permit\"";
	else
	    key = "route-map[].line[] $!name $!line $action=(string)\"deny\"";
	if(cv_parse(key, cgvs) < 0) {
	    perror("cv_parse");
	    cli_mode.mode = IOS_MODE_CONFIG;
	    break;
	}
	cli_set (h, vars, cgvs);
    }
    }	
    /* Set active syntax mode to IOS_MODE_BASE */
    if (!cli_set_syntax_mode(h, ios_tree[cli_mode.mode].im_stxmode))
	cli_output(stderr, "Failed to set active syntax mode\n");
    if (cgvs)
	cv_free(cgvs);

    return 1;
}

int
cli_ios_mode_up(clicon_handle h, cvec *vars, cg_var *arg)
{
    cg_var *cv;
    
    if ((cv = cv_new(CGV_INT)) == NULL){
	fprintf(stderr, "%s: cv_new: %s\n", __FUNCTION__, strerror(errno));
	return -1;
    }
    cv_int_set(cv, ios_tree[cli_mode.mode].im_up);
    if (ios_tree[cli_mode.mode].im_up != IOS_MODE_NONE)
	return cli_ios_mode(h, vars, cv);
    return 0;
}

#if depreciated
int
cli_ios_show_running(clicon_handle h, struct lvmap *lmap)
{
    int fd = -1;
    FILE *f = NULL;
    char db[] = "/tmp/curdbXXXXXX";
    dbspec_key *dbspec;
    /*
     * XXX Hack. Copy db, add system.boot key and print it. 
     */
  
    if ((fd = mkstemp(db)) < 0 || (f = fdopen(fd, "w")) == NULL)
	goto catch;
    fclose(f);
    f = NULL;
    fd = -1;
  
    if (file_cp(clicon_running_db(h), db))
	goto catch;
    dbspec = clicon_dbspec_key(h);
    if(db_lv_op(dbspec, db, LV_SET, "system.boot $dummy=(int)0", NULL) < 0)
	goto catch;
    cli_show_lvmap(db, lmap);
    errno = 0;
  
catch:
    if(errno)
	fprintf(stderr, "%s\n", strerror(errno));
    if (f)
	fclose(f);
    else if (fd >= 0)
	close (fd);
    unlink(db);
  
    return 0;
}
#else
int
cli_ios_show_running(clicon_handle h, struct lvmap *lmap)
{
    char *out;
    char d2t[MAXPATHLEN+1];

    snprintf(d2t, MAXPATHLEN, "%s/ios.d2t", clicon_clispec_dir(h));
    out = clicon_db2txt(h, clicon_running_db(h), d2t);
    if(out) {
	cli_output_formatted(out);
        free(out);
    }
    return 0;
}
#endif /* depreciated */


#if depreciated
/*
 * Print config stored in an XML file as per the formatting specified
 * in the lvmap.
 */
int
cli_ios_show_config(clicon_handle h, char *file, struct lvmap *lmap)
{
    char *db;

    if ((db = clicon_tmpfile(__FUNCTION__)) == NULL)
	return -1;

    if (db_init(db) < 0)
	return -1;

    if (load_xml_to_db(file, clicon_dbspec_key(h), db) < 0) {
	unchunk(db);
	return -1;
    }

    cli_show_lvmap(db, lmap);
    unlink(db);
    unchunk(db);
    return 0;
}
#else /* depreciated */
/*
 * Print config stored in an XML file as per the formatting specified
 * in the lvmap.
 */
int
cli_ios_show_config(clicon_handle h, char *file, struct lvmap *lmap)
{
    char *db;
    char *out;
    char d2t[MAXPATHLEN+1];

    if ((db = clicon_tmpfile(__FUNCTION__)) == NULL)
	return -1;

    if (db_init(db) < 0)
	return -1;

    if (load_xml_to_db(file, clicon_dbspec_key(h), db) < 0) {
	unchunk(db);
	return -1;
    }

    snprintf(d2t, MAXPATHLEN, "%s/ios.d2t", clicon_clispec_dir(h));
    out = clicon_db2txt(h, clicon_running_db(h), d2t);
    if(out) {
	cli_output_formatted(out);
        free(out);
    }
    unlink(db);
    unchunk(db);

    return 0;
}
#endif /* depreciated */



int
show_hostname(clicon_handle h, cvec *vars, cg_var *arg)
{
    char hostname[64];
    
    if (gethostname(hostname, 63) < 0){
        cli_output (stderr, "gethostname: %s", strerror(errno));
	return -1;
    }
    cli_output(stdout, "hostname %s\n", hostname);
    return 0;
}

/*
 * ios archive functionality - save to archive
 */
int
ios_cli_config_archive(clicon_handle h, cvec *vars, cg_var *arg)
{
    char *s;

    if ((s = clicon_sock(h)) == NULL)
	return -1;
    return clicon_proto_save(s, clicon_running_db(h), 1/*snapshot*/, NULL);
}


/*
 * ios archive functionality - rollback
 */
int
ios_cli_config_replace(clicon_handle h, cvec *vars, cg_var *arg)
{
#ifdef XXXtoBeImplemented
    char filename[MAXPATHLEN];
    char *filename1;
    struct stat sb;
    char *dbname = clicon_candidate_db(h);
    char *running = clicon_running_db(h);
    cg_var *cv1 = cvec_i(vars, 1);

    filename1 = cv_string_get(cv1);
    snprintf(filename, MAXPATHLEN, "%s/%s", 
	     clicon_archive_dir(h) , filename1);
    if (stat(filename, &sb) < 0){
	fprintf(stderr, "load_config: stat(%s): %s\n", 
		filename, strerror(errno));
	return -1;
    }
    if (clicon_proto_load(s, 0, dbname, filename) < 0)
	return -1;
    if (clicon_autocommit(h)){
	if ((s = clicon_sock(h)) == NULL)
	    return -1;
	if (clicon_proto_commit(s, running, dbname, 0, 0) < 0)
	    return -1;
    }
#else
    cli_output(stdout, "Not implemented\n");
#endif
    return 0;
}


/*
 * XXXX To be replaced with clicon's cli_show_diff()
 */
int
ios_cli_show_diff(clicon_handle h, char *db1, char *db2, struct lvmap *lmap)
{
    int ret;
    int  retval = -1;
    char *cmd;
    char *tmp1 = NULL;
    char *tmp2 = NULL;
    FILE *f1 = NULL;
    FILE *f2 = NULL;

    /* dump db1 to file */
    if ((tmp1 = clicon_tmpfile(__FUNCTION__)) == NULL)
	goto quit;
    if ((f1 = fopen(tmp1, "w")) == NULL){
	clicon_err(OE_UNIX, errno, "fopen");
	goto quit;
    }
    ret = lvmap_print(f1, db1, lmap, NULL);
    fclose(f1);
    if (ret < 0)
	goto quit;

    /* dump db2 to file */
    if ((tmp2 = clicon_tmpfile(__FUNCTION__)) == NULL)
	goto quit;
    if ((f2 = fopen(tmp2, "w")) == NULL){
	clicon_err(OE_UNIX, errno, "fopen");
	goto quit;
    }
    ret = lvmap_print(f2, db2, lmap, NULL);
    fclose(f2);
    if (ret < 0)
	goto quit;

    /* diff candidate with snapshot */
    cmd = chunk_sprintf(__FUNCTION__,
			"/usr/bin/diff -dU 1 %s %s | grep -v @@ | sed 1,2d", 
			tmp1, tmp2);
    if (cmd == NULL) {
	clicon_err(OE_UNIX, errno, "chunk");
	goto quit;
    }
    if (system(cmd) < 0)
	goto quit;
    
    retval = 0;
quit:
    
    if (tmp1)
	unlink(tmp1);
    if (tmp2)
	unlink(tmp2);
    unchunk_group(__FUNCTION__);
    return retval;
}



/*
 * ios archive functionality - show difference
 * Alternatives: 
 *    1. diff two files: dump candidate to file and diff them
 *    2. load the snapshot to db and db_diff. Cant do now because if I 
 *       load the configuration will be active.
 */
int
ios_cli_show_archive_diff(clicon_handle h, char *file, struct lvmap *lmap)
{
    char *archive;
    char *tmp = NULL;
    int  retval = -1;
    struct stat sb;

    /* Get snapshot file */
    archive = 
	chunk_sprintf(__FUNCTION__, "%s/%s", clicon_archive_dir(h), file);
    if (archive == NULL) {
	perror("chunk");
	return -1;
    }
    if (stat(archive, &sb) < 0){
	perror("stat");
	goto quit;
    }
    if ((tmp = clicon_tmpfile(__FUNCTION__)) == NULL)
	goto quit;
    if (db_init(tmp) < 0)
	goto quit;
    if (load_xml_to_db(archive, clicon_dbspec_key(h), tmp) < 0)
	goto quit;


    retval = ios_cli_show_diff(h, tmp, clicon_candidate_db(h), lmap);

  quit:
    if (tmp)
	unlink(tmp);
    unchunk_group(__FUNCTION__);

    return retval;
}


int
cli_ios_do(clicon_handle h, cvec *vars, cg_var *arg)
{
    char *cmd;
    char *mode;
    cg_var *cv = cvec_i(vars, 0);

    /* Run command in ENABLE mode */
    mode = ios_tree[IOS_MODE_ENABLE].im_stxmode;
    cmd = cv_string_get(cv) + strlen("do ");
    (void)cli_exec(h, cmd, &mode, NULL); /* ignore errors */

    return 0;
}

int
cli_test_log(clicon_handle h, cvec *vars, cg_var *arg)
{
    int i = 0;

    /* Seen on log and stderr if debug == 1 */
    clicon_debug(1, "%d: Debug level %d", ++i, 1); 

    /* Seen on log and stderr if debug == 2 */
    clicon_debug(2, "%d: Debug level %d", ++i, 2); 

    if (debug)     /* Seen on stderr if debug != 0 */
	fprintf(stderr, "%d: Debug print\n", ++i);
    
    /* Seen on log and stderr */
    clicon_log(LOG_EMERG, "%d: Log level emerg", ++i); 
    clicon_log(LOG_ERR, "%d: Log level err", ++i);
    clicon_log(LOG_WARNING, "%d: Log level warning", ++i);

    /* Seen on log and stderr */
    clicon_log(LOG_NOTICE, "%d: Log level notice", ++i);

    /* Seen on log and stderr */
    clicon_log(LOG_INFO, "%d: Log level info", ++i);

    /* Seen on log and stderr if debug != 0 */
    clicon_log(LOG_DEBUG, "%d: Log level debug", ++i); // xxx not seen

    /* Not seen */
    clicon_err(OE_UNIX, EBADF, "%d: Error unix EBADF", ++i);

#ifdef notused
    /* Seen on stderr */
    char str[64];
    sprintf(str, "%d: Error print", ++i);
    clicon_err_print(stderr, str);
#endif
    return 0;
}

int
cli_validate(clicon_handle h, cvec *vars, cg_var *arg)
{
    char *s;

    if ((s = clicon_sock(h)) == NULL)
	return -1;
    return clicon_proto_validate(s, clicon_candidate_db(h));
}
