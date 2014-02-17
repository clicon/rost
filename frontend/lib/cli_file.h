/*
 *  CVS Version: $Id: cli_file.h,v 1.4 2013/08/05 14:30:56 olof Exp $
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

#ifndef _CLI_FILE_H_
#define _CLI_FILE_H_

int cli_copy (clicon_handle h, cg_var *, cg_var *, int);
int cli_sanitized_copy (clicon_handle h, cg_var *, cg_var *, int);
int cli_file_copy (clicon_handle h, cvec *vars, cg_var *arg);
int cli_copy_startup_url (clicon_handle h, cvec *vars, cg_var *arg);
int cli_copy_startup_running (clicon_handle h, cvec *vars, cg_var *arg);
int cli_copy_url_startup (clicon_handle h, cvec *vars, cg_var *arg);
int cli_copy_url_running (clicon_handle h, cvec *vars, cg_var *arg);
int cli_copy_url_url (clicon_handle h, cvec *vars, cg_var *arg);
int cli_copy_running_url (clicon_handle h, cvec *vars, cg_var *arg);
int cli_copy_candidate_url (clicon_handle h, cvec *vars, cg_var *arg);
int cli_copy_running_startup (clicon_handle h, cvec *vars, cg_var *arg);
int cli_dir (clicon_handle h, cvec *vars, cg_var *arg);
int cli_more_url (clicon_handle h, cvec *vars, cg_var *arg);
int cli_more (clicon_handle h, cvec *vars, cg_var *arg);
int cli_diff (clicon_handle h, cvec *vars, cg_var *arg);
int cli_file_del (clicon_handle h, cvec *vars, cg_var *arg);

#endif /* _CLI_FILE_H_ */

