/*
 *  CVS Version: $Id: rost_syslog.h,v 1.2 2011/08/20 14:12:35 olof Exp $
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

#ifndef __ROST_SYSLOG_H__
#define __ROST_SYSLOG_H__
 
#define SYSLOG_DBDIR     "/tmp/"
#define SYSLOG_DBFILE    "syslog.db"
#define SYSLOG_DB        SYSLOG_DBDIR SYSLOG_DBFILE

int syslog_sqlite3_exec(char *filename,
			int flags,
			char *query,
			int (*cb)(void *, int, char **, char **),
			void *cbarg);

#endif /* __ROST_SYSLOG_H__ */
