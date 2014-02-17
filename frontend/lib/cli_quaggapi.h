/*
 *  CVS Version: $Id: cli_quaggapi.h,v 1.4 2013/08/05 14:30:56 olof Exp $
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
 */

#ifndef _CLI_QUAGGAPI_H_
#define _CLI_QUAGGAPI_H_

int cli_zebra_exec(clicon_handle h, cvec *vars, cg_var *arg);

int cli_rip_exec(clicon_handle h, cvec *vars, cg_var *arg);

int cli_ripng_exec(clicon_handle h, cvec *vars, cg_var *arg);

int cli_ospf_exec(clicon_handle h, cvec *vars, cg_var *arg);

int cli_rt_ospf6_exec(clicon_handle h, cvec *vars, cg_var *arg);

int cli_bgp_exec(clicon_handle h, cvec *vars, cg_var *arg);

int cli_isis_exec(clicon_handle h, cvec *vars, cg_var *arg);

int cli_all_exec(clicon_handle h, cvec *vars, cg_var *arg);

int cli_show_debugging(clicon_handle h, cvec *vars, cg_var *arg);

#endif /* _CLI_QUAGGAPI_H_ */
