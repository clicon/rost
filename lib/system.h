/*
 *  CVS Version: $Id: system.h,v 1.9 2013/07/01 10:40:54 olof Exp $
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

#ifndef _SYSTEM_H_
#define _SYSTEM_H_

int rost_uptime(int *sec);

int rost_get_serialno(char *serialnr, int len);

int rost_get_product(char *product, int len);

int rost_proc_killbyname (const char *name, int sig);

int rost_err(int suberr, char *reason, ...);

#endif /* _SYSTEM_H_ */
