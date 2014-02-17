/*
 *  CVS Version: $Id: cli_expand.h,v 1.3 2014/01/23 21:14:36 benny Exp $
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

#ifndef _CLI_EXPAND_H_
#define _CLI_EXPAND_H_

/* functions are called directly using dlopen() */
int expand_bgp_as(clicon_handle h, char *name, cvec *vars, cg_var *arg, int *nr, char ***commands, char ***helptexts);
int expand_bgp_neighbor(clicon_handle h, char *name, cvec *vars, cg_var *arg, int *nr, char ***commands, char ***helptexts);
int expand_user(clicon_handle h, char *name, cvec *vars, cg_var *arg, int *nr, char ***commands, char ***helptexts);
int expand_configfile(clicon_handle h, char *name, cvec *vars, cg_var *arg, int *nr, char ***commands, char ***helptexts);
int expand_snapshot(clicon_handle h, char *name, cvec *vars, cg_var *arg, int *nr, char ***commands, char ***helptexts);
int expand_flash(clicon_handle h, char *name, cvec *vars, cg_var *arg, int *nr, char ***commands, char ***helptexts);
int expand_home(clicon_handle h, char *name, cvec *vars, cg_var *arg, int *nr, char ***commands, char ***helptexts);
int expand_cwd(clicon_handle h, char *name, cvec *vars, cg_var *arg, int *nr, char ***commands, char ***helptexts);
int expand_acl(clicon_handle h, char *name, cvec *vars, cg_var *arg, int *nr, char ***commands, char ***helptexts);
int expand_prefixlist(clicon_handle h, char *name, cvec *vars, cg_var *arg, int *nr, char ***commands, char ***helptexts);
int expand_routemap(clicon_handle h, char *name, cvec *vars, cg_var *arg, int *nr, char ***commands, char ***helptexts);


#endif /* _CLI_EXPAND_H_ */
