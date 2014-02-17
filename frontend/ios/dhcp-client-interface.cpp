/*
 * CVS Version: $Id: dhcp-client-interface.cpp,v 1.2 2013/02/23 00:30:05 benny Exp $
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

CLICON_MODE=STRINGIFY(IOS_INTERFACE);

/* IP ADDRESS */
ip("Interface Internet Protocol config commands") address("Set the IP address of an interface") dhcp("IP Address negotiated via DHCP"), cli_set("interface[].unit[].inet.dhcp_client $!name=ios_interface_cb() $!unit=ios_interface_cb() $enabled=(int)1"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") address("Set the IP address of an interface") dhcp("IP Address negotiated via DHCP"), cli_del("interface[].unit[].inet.dhcp_client $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
