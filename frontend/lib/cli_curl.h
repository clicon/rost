/*
 *  CVS Version: $Id: cli_curl.h,v 1.1 2013/04/14 16:20:40 olof Exp $
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

#ifndef _CLICON_CURL_H_
#define _CLICON_CURL_H_

#include <curl/curl.h>

int clicon_path2url(char *path, cg_var *cgv);
char *clicon_url_sprint(cg_var *url, const char *label);
int clicon_curl_copy(cg_var *from, cg_var *to, long conntimeout);

#endif /* _CLICON_CURL_H_ */
