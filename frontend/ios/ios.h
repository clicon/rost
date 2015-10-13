/*
 * CVS Version: $Id: ios.h,v 1.12 2013/08/05 14:31:08 olof Exp $
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
 *
 */

#ifndef _IOS_H_
#define _IOS_H_

#include "ios_macros.h"

struct ios_mode {
    int im_mode;			/* CLI mode */
    int im_up;				/* Up in tree (vector index) */
    char *im_stxmode;			/* Syntax mode */
    char *im_prompt;			/* Prompt format */
};


/*
 * Local variables
 */
extern struct qa_mode cli_mode;


/*
 * Function declarations
 */
int cli_ios_mode(clicon_handle handle, cvec *vars, cg_var *arg);
int cli_ios_do(clicon_handle handle, cvec *vars, cg_var *arg);
int cli_del_modetree(clicon_handle handle, cvec *vars, cg_var *arg);
int ios_cli_config_archive(clicon_handle handle, cvec *vars, cg_var *arg);
int ios_cli_config_replace(clicon_handle handle, cvec *vars, cg_var *arg);
int ios_cli_show_archive_diff(clicon_handle h, char *file);
int cli_ios_show_running(clicon_handle h);
int cli_ios_show_config(clicon_handle h, char *file);
int cli_ios_show_interfaces(clicon_handle handle, cvec *vars, cg_var *arg);
int cli_ios_show_interface(char *ifname, int cgv_argc, cg_var *cgv_argv);
int cli_ios_show_iface_stats(clicon_handle handle, cvec *vars, cg_var *arg);
int show_hostname(clicon_handle handle, cvec *vars, cg_var *arg);

int cli_test_log(clicon_handle handle, cvec *vars, cg_var *arg);

#endif  /* _IOS_H_ */
