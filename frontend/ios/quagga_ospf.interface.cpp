/*
 * CVS Version: $Id: quagga_ospf.interface.cpp,v 1.8 2014/01/10 14:08:25 olof Exp $
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

    /* IP OSPF COST */
ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") cost("Interface cost") <number range[1:65535]>("Cost"), cli_set("interface[].unit[].ospf.cost $!name=ios_interface_cb() $!unit=ios_interface_cb() $cost"), ADMIN;

no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") cost("Interface cost"), cli_del("interface[].unit[].ospf.cost $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") cost("Interface cost") <number range[1:65535]>("Cost"), cli_del("interface[].unit[].ospf.cost $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;

    /* IP OSPF NETWORK */
ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") network("Network type") broadcast("Specify OSPF broadcast multi-access network"), cli_set("interface[].unit[].ospf.network-type $!name=ios_interface_cb() $!unit=ios_interface_cb() $network-type=(string)\"broadcast\""), ADMIN;
ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") network("Network type") non-broadcast("Specify OSPF NBMA network"),  cli_set("interface[].unit[].ospf.network-type $!name=ios_interface_cb() $!unit=ios_interface_cb() $network-type=(string)\"non-broadcast\""), ADMIN;
ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") network("Network type") point-to-multipoint("Specify OSPF point-to-multipoint network"),  cli_set("interface[].unit[].ospf.network-type $!name=ios_interface_cb() $!unit=ios_interface_cb() $network-type=(string)\"point-to-multipoint\""), ADMIN;
ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") network("Network type") point-to-point("Specify OSPF point-to-point network"),  cli_set("interface[].unit[].ospf.network-type $!name=ios_interface_cb() $!unit=ios_interface_cb() $network-type=(string)\"point-to-point\""), ADMIN;

no("Neg ate a command or set its defaults") ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") network("Network type"),  cli_del("interface[].unit[].ospf.network-type $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") network("Network type") broadcast("Specify OSPF broadcast multi-access network"), cli_del("interface[].unit[].ospf.network-type $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") network("Network type") non-broadcast("Specify OSPF NBMA network"), cli_del("interface[].unit[].ospf.network-type $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") network("Network type") point-to-multipoint("Specify OSPF point-to-multipoint network"), cli_del("interface[].unit[].ospf.network-type $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") network("Network type") point-to-point("Specify OSPF point-to-point network"), cli_del("interface[].unit[].ospf.network-type $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;

  
    /* IP OSPF PRIORITY */
ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") priority("Router priority") <number range[0:255]>("Priority"), cli_set("interface[].unit[].ospf.priority $!name=ios_interface_cb() $!unit=ios_interface_cb() $priority"), ADMIN;

no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") priority("Router priority"), cli_del("interface[].unit[].ospf.priority $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") ospf("OSPF interface commands") priority("Router priority") <number range[0:255]>("Priority"), cli_del("interface[].unit[].ospf.priority $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
