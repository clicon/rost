/*
 * CVS Version: $Id: system.common.cpp,v 1.11 2014/01/10 14:08:26 olof Exp $
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
CLICON_PLUGIN="system";

/* SHOW DEBUGGING */
show("Show running system information") debugging("State of each debugging option"), cli_show_debugging(), ADMIN;
show("Show running system information") debugging("State of each debugging option") zebra("Zebra information"), cli_zebra_exec("show debugging zebra"), ADMIN;
show("Show running system information") debugging("State of each debugging option") ospf("OSPF information"), cli_ospf_exec("show debugging ospf"), ADMIN;

/* PING */
ping("Send echo messages") <string>("Ping destination address or hostname"), cli_run("ping %s -c5"), PING;
ping("Send echo messages") <string>("Ping destination address or hostname") repeat("specify repeat count") <number>, cli_run("ping %s -c%n"), PING;
ping("Send echo messages") <string>("Ping destination address or hostname") repeat("specify repeat count") <number> size("specify datagram size") <number range[36:1824]>, cli_run("ping %s -c%n -s%n"), PING;
ping("Send echo messages") <string>("Ping destination address or hostname") size("specify datagram size") <number range[36:1824]>, cli_run("ping %s -s%n -c5"), PING;
ping("Send echo messages") <string>("Ping destination address or hostname") size("specify datagram size") <number range[36:1824]> repeat("specify repeat count") <number>, cli_run("ping %s -s%n -c%n"), PING;

/* SHOW ARP */
show("Show running system information") arp("ARP table"), cli_run(STRINGIFY(CONCAT(PROG_ARP, -n))), SHOW;
show("Show running system information") arp("ARP table") <interface:string expand_interface()>("ARP table for interface"), cli_run(STRINGIFY(CONCAT(PROG_ARP, -ni %s))), SHOW;

/* SHOW CLOCK */
show("Show running system information") clock("Display the system clock"), cli_run("date"), SHOW;

/* SHOW MEMORY */
show("Show running system information") memory("Memory statistics"), cli_run("/usr/bin/free"), SHOW;
show("Show running system information") memory("Memory statistics") detail("Detailed memory statistics"), cli_run("/bin/cat /proc/meminfo"), SHOW;

/* SHOW INVENTORY */
show("Show running system information")  inventory("Show the physical inventory"), cli_show_inventory(), SHOW;

/* SHOW HOSTNAME */
show("Show running system information") hostname("Show hostname"), show_hostname(), SHOW;

/* SHOW IP SOCKETS */
show("Show running system information") ip("IP information") sockets("Open IP sockets"), cli_run("netstat -aut"), SHOW;

/* SHOW IP TRAFFIC */
show("Show running system information") ip("IP information") traffic("IP protocol statistics"), cli_run("netstat -s"), SHOW;

/* SHOW USERS */
show("Show running system information") users("Display information about terminal lines"), cli_run("who -uH"), SHOW;

/* SHOW VERSION */
show("Show running system information") version("Display version information"), cli_version(), SHOW;

/* TRACEROUTE */
traceroute("Trace route to destination") <string>("Trace route to destination address or hostname"), cli_run("traceroute %s"), PING;
traceroute("Trace route to destination") <string>("Trace route to destination address or hostname") numeric("display numeric address"), cli_run("traceroute %s -n"), PING;
traceroute("Trace route to destination") <string>("Trace route to destination address or hostname") source("specify source address or interface name") <string>("Source address or interface name"), cli_run("traceroute %s -s%s"), PING;
traceroute("Trace route to destination") <string>("Trace route to destination address or hostname") source("specify source address or interface name") <string>("Source address or interface name") numeric("display numeric address"), cli_run("traceroute %s -s%s -n"), PING;
traceroute("Trace route to destination") <string>("Trace route to destination address or hostname") ttl("specify maximum ttl") <number range[1:255]>("maximum ttl"), cli_run("traceroute %s -m%n"), PING;
traceroute("Trace route to destination") <string>("Trace route to destination address or hostname") ttl("specify maximum ttl") <number range[1:255]>("maximum ttl") numeric("display numeric address"), cli_run("traceroute %s -m%n -n"), PING;
traceroute("Trace route to destination") <string>("Trace route to destination address or hostname") ttl("specify maximum ttl") <number range[1:255]>("maximum ttl") source("specify source address or interface name") <string>("Source address or interface name"), cli_run("traceroute %s -m%n -s%s "), PING;
traceroute("Trace route to destination") <string>("Trace route to destination address or hostname") ttl("specify maximum ttl") <number range[1:255]>("maximum ttl") source("specify source address or interface name") <string>("Source address or interface name") numeric("display numeric address"), cli_run("traceroute %s -m%n -s%s -n"), PING;
