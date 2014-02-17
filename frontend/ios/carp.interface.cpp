/*
 * CVS Version: $Id: carp.interface.cpp,v 1.7 2014/01/10 14:08:25 olof Exp $
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

#ifdef notyet
/* CARP TIMERS */
carp("CARP interface configuration commands") <number range[1:255]>("Virtual IP identifier") timers("Set CARP timersvirtual IP address") <ipv4prefix>("Virtual IP address"), cli_set("interface[].unit[].carp.$vhid.address $!name=ios_interface_cb() $!unit=ios_interface_cb() $vhid $address"), ADMIN;

carp("CARP interface configuration commands") <number range[1:255]>("Virtual IP identifier") ip("Set virtual IP address") <ipv4prefix>("Virtual IP address"), cli_del("interface[].unit[].carp.$vhid.address $!name=ios_interface_cb() $!unit=ios_interface_cb() $vhid $address"), ADMIN;

/* CARP IP */
carp("CARP interface configuration commands") <number range[1:255]>("Virtual IP identifier") ip("Set virtual IP address") <ipv4prefix>("Virtual IP address"), cli_set("interface[].unit[].carp.$vhid.address $!name=ios_interface_cb() $!unit=ios_interface_cb() $vhid $address"), ADMIN;
carp("CARP interface configuration commands") <number range[1:255]>("Virtual IP identifier") ip("Set virtual IP address") <ipv4prefix>("Virtual IP address"), cli_del("interface[].unit[].carp.$vhid.address $!name=ios_interface_cb() $!unit=ios_interface_cb() $vhid $address"), ADMIN;

/* CARP KEY */
carp("CARP interface configuration commands") <number range[1:255]>("Virtual IP identifier") key("Set CARP authentication key") <string>("Secret key"), cli_set("interface[].unit[].carp.$vhid.key $!name=ios_interface_cb() $!unit=ios_interface_cb() $vhid $key"), ADMIN;
no("Negate a command or set its defaults") carp("CARP interface configuration commands") <number range[1:255]>("Virtual IP identifier") key("Set CARP authentication key") <string>("Secret key"), cli_del("interface[].unit[].carp.$vhid.key $!name=ios_interface_cb() $!unit=ios_interface_cb() $vhid $key"), ADMIN;

/* CARP PREEMPT */
carp("CARP interface configuration commands") <number range[1:255]>("Virtual IP identifier") preempt("Overthrow lower priority Active routers"), cli_set("interface[].unit[].carp.$vhid.preempt $!name=ios_interface_cb() $!unit=ios_interface_cb() $vhid"), ADMIN;
no("Negate a command or set its defaults") carp("CARP interface configuration commands") <number range[1:255]>("Virtual IP identifier") preempt("Overthrow lower priority Active routers"), cli_del("interface[].unit[].carp.$vhid.preempt $!name=ios_interface_cb() $!unit=ios_interface_cb() $vhid"), ADMIN;
#endif  
