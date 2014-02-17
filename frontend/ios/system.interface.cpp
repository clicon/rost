/*
 * CVS Version: $Id: system.interface.cpp,v 1.7 2014/01/10 14:08:26 olof Exp $
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

ip("Interface Internet Protocol config commands") redirects("Enable sending ICMP Redirect messages"), cli_set("interface[].unit[].ipv4.send_redirects $!name=ios_interface_cb() $!unit=ios_interface_cb() $status=(int)1"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") redirects("Enable sending ICMP Redirect messages"), cli_set("interface[].unit[].ipv4.send_redirects $!name=ios_interface_cb() $!unit=ios_interface_cb() $status=(int)0"), ADMIN;

/* IP PROXY-ARP */
ip("Interface Internet Protocol config commands") proxy-arp("Enable proxy ARP"), cli_set("interface[].unit[].ipv4.proxy_arp $!name=ios_interface_cb() $!unit=ios_interface_cb() $status=(int)1"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") proxy-arp("Enable proxy ARP"), cli_set("interface[].unit[].ipv4.proxy_arp $!name=ios_interface_cb() $!unit=ios_interface_cb() $status=(int)0"), ADMIN;

/* IP VERIFY */
ip("Interface Internet Protocol config commands") verify("Enable per packet validation") source("Validation of source address") reachable-via("Specify reachability check to apply to the source address") rx("Source is reachable via interface on which packet was received"), cli_set("interface[].unit[].ipv4.rp_filter $!name=ios_interface_cb() $!unit=ios_interface_cb() $status=(int)1"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") verify("Enable per packet validation") source("Validation of source address") reachable-via("Specify reachability check to apply to the source address") rx("Source is reachable via interface on which packet was received"), cli_set("interface[].unit[].ipv4.rp_filter $!name=ios_interface_cb() $!unit=ios_interface_cb() $status=(int)0"), ADMIN;

/* ENCAPSULATION */
#ifdef notyet
encapsulation("Set encapsulation type for an interface") dot1Q("IEEE 802.1Q Virtual LAN") <number range[1:4094]>("IEEE 802.1Q VLAN ID"), cli_ifvlan_set("interface[].unit[].dot1q $!name=ios_interface_cb() $!unit=ios_interface_cb() $vlan"), ADMIN);
no("Negate a command or set its defaults") encapsulation("Set encapsulation type for an interface") dot1Q("IEEE 802.1Q Virtual LAN"), cli_ifvlan_del("interface[].unit[].dot1q $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") encapsulation("Set encapsulation type for an interface") dot1Q("IEEE 802.1Q Virtual LAN") <number range[1:4094]>("IEEE 802.1Q VLAN ID"), cli_ifvlan_del("interface[].unit[].dot1q $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
#endif
