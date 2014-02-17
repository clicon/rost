/*
 * CVS Version: $Id: quagga_route_map.common.cpp,v 1.6 2011/10/30 05:46:43 benny Exp $
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

#include "ios_macros.h"
CLICON_MODE=STRINGIFY(IOS_BASE:IOS_ENABLE);

    /* SHOW ROUTE-MAP */
show("Show running system information") route-map("route-map information"), cli_all_exec("show route-map"), SHOW;
show("Show running system information") route-map("route-map information") <string>("route-map name"), cli_all_exec("show route-map %s"), SHOW;
show("Show running system information") route-map("route-map information") zebra("RIP route-map information"), cli_zebra_exec("show route-map "), SHOW;
show("Show running system information") route-map("route-map information") zebra("Zebra route-map information") <string>("route-map name"), cli_zebra_exec("show route-map %s"), SHOW;

