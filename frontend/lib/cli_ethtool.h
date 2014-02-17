/*
 *  CVS Version: $Id: cli_ethtool.h,v 1.2 2013/08/05 14:30:56 olof Exp $
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

#ifndef _CLI_ETHTOOL_H_
#define _CLI_ETHTOOL_H_

struct ethtool_cmd *ethtool_client_gset(clicon_handle h, char *ifname, const char *label);
int ethtool_client_getlink(clicon_handle h, char *ifname, uint8_t *link);
struct osr_etstats *ethtool_client_gstats(clicon_handle h, char *ifname, const char *label);


#endif	/* _CLI_ETHTOOL_H_ */
