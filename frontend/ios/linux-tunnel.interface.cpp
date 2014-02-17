/*
 * CVS Version: $Id: linux-tunnel.interface.cpp,v 1.3 2014/01/10 14:08:25 olof Exp $
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
CLICON_PLUGIN="linux-tunnel";

/* TUNNEL */
tunnel("protocol-over-protocol tunneling") {
	checksum("enable end to end checksumming of packets"),  tunnel_set("interface[].unit[].tunnel.csum $!name=ios_interface_cb() $!unit=ios_interface_cb() $csum"), ADMIN;
	source("source of tunnel packets") <address:ipv4addr>("source ip address"), tunnel_set("interface[].unit[].tunnel.source $!name=ios_interface_cb() $!unit=ios_interface_cb() $source"), ADMIN;
	destination("destination of tunnel") <address:ipv4addr>("destination ip address"), tunnel_set("interface[].unit[].tunnel.destination $!name=ios_interface_cb() $!unit=ios_interface_cb() $destination"), ADMIN;
	key("security or selector key") <key:number>("Key"), tunnel_set("interface[].unit[].tunnel.key $!name=ios_interface_cb() $!unit=ios_interface_cb() $key"), ADMIN;
	path-mtu-discovery("Enable Path MTU Discovery on tunnel"), cli_del("interface[].unit[].tunnel.nopmtu $!name=ios_interface_cb() $!unit=ios_interface_cb() $nopmtu"), ADMIN;
	tos("set type of service byte") <tos:number range[1:99]>("TOS"), tunnel_set("interface[].unit[].tunnel.tos $!name=ios_interface_cb() $!unit=ios_interface_cb() $tos"), ADMIN;
	ttl("set time to live") <ttl:number range[1:255]>("TTL"), tunnel_set("interface[].unit[].tunnel.ttl $!name=ios_interface_cb() $!unit=ios_interface_cb() $ttl"), ADMIN;
}

/* INTERFACE */
no("Negate a command or set its defaults") {
	tunnel("protocol-over-protocol tunneling") {
		checksum("enable end to end checksumming of packets"),  cli_del("interface[].unit[].tunnel.csum $!name=ios_interface_cb() $!unit=ios_interface_cb() $csum"), ADMIN;
		source("source of tunnel packets") <address:ipv4addr>("source ip address"), cli_del("interface[].unit[].tunnel.source $!name=ios_interface_cb() $!unit=ios_interface_cb() $source"), ADMIN;
		destination("destination of tunnel") <address:ipv4addr>("destination ip address"), cli_del("interface[].unit[].tunnel.destination $!name=ios_interface_cb() $!unit=ios_interface_cb() $destination"), ADMIN;
		key("security or selector key") <key:number>("Key"), cli_del("interface[].unit[].tunnel.key $!name=ios_interface_cb() $!unit=ios_interface_cb() $key"), ADMIN;
		path-mtu-discovery("Enable Path MTU Discovery on tunnel"), tunnel_set("interface[].unit[].tunnel.nopmtu $!name=ios_interface_cb() $!unit=ios_interface_cb() $nopmtu"), ADMIN;
		tos("set type of service byte") <tos:number range[0:99]>("TOS"), cli_del("interface[].unit[].tunnel.tos $!name=ios_interface_cb() $!unit=ios_interface_cb() $tos"), ADMIN;
		ttl("set time to live") <ttl:number range[1:255]>("TTL"), cli_del("interface[].unit[].tunnel.ttl $!name=ios_interface_cb() $!unit=ios_interface_cb() $ttl"), ADMIN;
	}
}
	
