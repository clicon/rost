/*
 * CVS Version: $Id: quagga_route_map.routemap.cpp,v 1.8 2014/01/10 14:08:26 olof Exp $
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
CLICON_MODE=STRINGIFY(IOS_ROUTEMAP);


    /* CALL */
call("Jump to another Route-Map after match+set") <string>("Target route-map name"), cli_set("route-map[].line[].call $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $route_map"), ADMIN;
no("Negate a command or set its defaults") call("Jump to another Route-Map after match+set"), cli_set("route-map[].line[].call $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") call("Jump to another Route-Map after match+set") <string>("Target route-map name"), cli_set("route-map[].line[].call $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;

    /* CONTINUE */
continue("Continue on a different entry within the route-map"), cli_set("route-map[].line[].continue $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
continue("Continue on a different entry within the route-map") <number range[1:65536]>("Goto Clause number"), cli_set("route-map[].line[].continue $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $goto"), ADMIN;

no("Negate a command or set its defaults") continue("Continue on a different entry within the route-map"), cli_del("route-map[].line[].continue $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") continue("Continue on a different entry within the route-map") <number range[1:65536]>("Goto Clause number"), cli_del("route-map[].line[].continue $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;

    /* DESCRIPTION */
description("Route-map comment") <rest>("Comment describing this route-map rule"), cli_set("route-map[].line[].description $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $description"), ADMIN;

no("Negate a command or set its defaults") description("Route-map comment"), cli_del("route-map[].line[].description $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") description("Route-map comment") <rest>("Comment describing this route-map rule"), cli_del("route-map[].line[].description $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;

    /* MATCH AS-PATH */
match("Match values from routing table") as-path("Match BGP AS path list") <string>("AS path access-list name"), cli_set("route-map[].line[].match.as-path $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $as_path"), ADMIN;


no("Negate a command or set its defaults") match("Match values from routing table") as-path("Match BGP AS path list"), cli_del("route-map[].line[].match.as-path $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") as-path("Match BGP AS path list") <string>("AS path access-list name"), cli_del("route-map[].line[].match.as-path $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;

#ifdef notyet
    /* MATCH COMMUNITY */
match("Match values from routing table") community("Match BGP community list") <number range[1:99]>("Community-list number (standard)"), cli_rt_bgp_exec("match community %n"), ADMIN;
match("Match values from routing table") community("Match BGP community list") <number range[1:99]>("Community-list number (standard)") exact-match("Do exact matching of communities"), cli_rt_bgp_exec("match community %n exact-match"), ADMIN;
match("Match values from routing table") community("Match BGP community list") <number range[100:500]>("Community-list number (expanded)"), cli_rt_bgp_exec("match community %n"), ADMIN;
match("Match values from routing table") community("Match BGP community list") <number range[100:500]>("Community-list number (expanded)") exact-match("Do exact matching of communities"), cli_rt_bgp_exec("match community %n exact-match"), ADMIN;
match("Match values from routing table") community("Match BGP community list") <string>("Community-list name"), cli_rt_bgp_exec("match community %s"), ADMIN;
match("Match values from routing table") community("Match BGP community list") <string>("Community-list name") exact-match("Do exact matching of communities"), cli_rt_bgp_exec("match community %s exact-match"), ADMIN;

no("Negate a command or set its defaults") match("Match values from routing table") community("Match BGP community list"), cli_rt_bgp_exec("no match community"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") community("Match BGP community list") <number range[1:99]>("Community-list number (standard)"), cli_rt_bgp_exec("no match community %n"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") community("Match BGP community list") <number range[1:99]>("Community-list number (standard)") exact-match("Do exact matching of communities"), cli_rt_bgp_exec("no match community %n exact-match"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") community("Match BGP community list") <number range[100:500]>("Community-list number (expanded)"), cli_rt_bgp_exec("no match community %n"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") community("Match BGP community list") <number range[100:500]>("Community-list number (expanded)") exact-match("Do exact matching of communities"), cli_rt_bgp_exec("no match community %n exact-match"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") community("Match BGP community list") <string>("Community-list name"), cli_rt_bgp_exec("no match community %s"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") community("Match BGP community list") <string>("Community-list name") exact-match("Do exact matching of communities"), cli_rt_bgp_exec("no match community %s exact-match"), ADMIN;
#endif /* notyet */

    /* MATCH INTERFACE */
match("Match values from routing table") interface("Match first hop interface of route") <interface>("Interface name"), cli_set("route-map[].line[].match.interface $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $interface"), ADMIN;

no("Negate a command or set its defaults") match("Match values from routing table") interface("Match first hop interface of route"), cli_del("route-map[].line[].match.interface $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") interface("Match first hop interface of route") <interface>("Interface name"), cli_del("route-map[].line[].match.interface $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;


    /* MATCH IP ADDRESS */
match("Match values from routing table") ip("IP information") address("Match address of route") <number range[1:199]>("IP access-list number"), cli_set("route-map[].line[].match.ip.address $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $acl"), ADMIN;
match("Match values from routing table") ip("IP information") address("Match address of route") <number range[1300:2699]>("IP access-list number (expanded range)"), cli_set("route-map[].line[].match.ip.address $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $acl"), ADMIN;
match("Match values from routing table") ip("IP information") address("Match address of route") <string>("IP access-list name"), cli_set("route-map[].line[].match.ip.address $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $acl"), ADMIN;
match("Match values from routing table") ip("IP information") address("Match address of route") prefix-list("Match entries of prefix-lists") <string>("IP prefix-list name"), cli_set("route-map[].line[].match.ip.address.prefix-list $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $prefix_list"), ADMIN;

no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") address("Match address of route"), cli_del("route-map[].line[].match.ip.address $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") address("Match address of route") <number range[1:199]>("IP access-list number"), cli_del("route-map[].line[].match.ip.address $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") address("Match address of route") <number range[1300:2699]>("IP access-list number (expanded range)"), cli_del("route-map[].line[].match.ip.address $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") address("Match address of route") <string>("IP access-list name"), cli_del("route-map[].line[].match.ip.address $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") address("Match address of route") prefix-list("Match entries of prefix-lists"), cli_del("route-map[].line[].match.ip.address.prefix-list $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") address("Match address of route") prefix-list("Match entries of prefix-lists") <string>("IP prefix-list name"), cli_del("route-map[].line[].match.ip.address.prefix-list $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;

    /* MATCH IP NEXT-HOP */
match("Match values from routing table") ip("IP information") next-hop("Match next-hop address of route") <number range[1:199]>("IP access-list number"), cli_set("route-map[].line[].match.ip.next-hop $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $acl"), ADMIN;
match("Match values from routing table") ip("IP information") next-hop("Match next-hop address of route") <number range[1300:2699]>("IP access-list number (expanded range)"), cli_set("route-map[].line[].match.ip.next-hop $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $acl"), ADMIN;
match("Match values from routing table") ip("IP information") next-hop("Match next-hop address of route") <string>("IP access-list name"), cli_set("route-map[].line[].match.ip.next-hop $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $acl"), ADMIN;
match("Match values from routing table") ip("IP information") next-hop("Match next-hop address of route") prefix-list("Match entries of prefix-lists") <string>("IP prefix-list name"), cli_set("route-map[].line[].match.ip.next-hop.prefix-list $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $prefix_list"), ADMIN;

no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") next-hop("Match next-hop address of route"), cli_del("route-map[].line[].match.ip.next-hop $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") next-hop("Match next-hop address of route") <number range[1:199]>("IP access-list number"), cli_del("route-map[].line[].match.ip.next-hop $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") next-hop("Match next-hop address of route") <number range[1300:2699]>("IP access-list number (expanded range)"), cli_del("route-map[].line[].match.ip.next-hop $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") next-hop("Match next-hop address of route") <string>("IP access-list name"), cli_del("route-map[].line[].match.ip.next-hop $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") next-hop("Match next-hop address of route") prefix-list("Match entries of prefix-lists"), cli_del("route-map[].line[].match.ip.next-hop.prefix-list $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") next-hop("Match next-hop address of route") prefix-list("Match entries of prefix-lists") <string>("IP prefix-list name"), cli_del("route-map[].line[].match.ip.next-hop.prefix-list $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;

    /* MATCH IP ROUTE-SOURCE */
match("Match values from routing table") ip("IP information") route-source("Match advertising source address of route") <number range[1:199]>("IP access-list number"), cli_set("route-map[].line[].match.ip.route-source $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $acl"), ADMIN;
match("Match values from routing table") ip("IP information") route-source("Match advertising source address of route") <number range[1300:2699]>("IP access-list number (expanded range)"), cli_set("route-map[].line[].match.ip.route-source $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $acl"), ADMIN;
match("Match values from routing table") ip("IP information") route-source("Match advertising source address of route") <string>("IP access-list name"), cli_set("route-map[].line[].match.ip.route-source $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $acl"), ADMIN;
match("Match values from routing table") ip("IP information") route-source("Match advertising source address of route") prefix-list("Match entries of prefix-lists") <string>("IP prefix-list name"), cli_set("route-map[].line[].match.ip.route-source.prefix-list $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $prefix_list"), ADMIN;

no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") route-source("Match advertising source address of route"), cli_del("route-map[].line[].match.ip.route-source $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") route-source("Match advertising source address of route") <number range[1:199]>("IP access-list number"), cli_del("route-map[].line[].match.ip.route-source $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") route-source("Match advertising source address of route") <number range[1300:2699]>("IP access-list number (expanded range)"), cli_del("route-map[].line[].match.ip.route-source $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") route-source("Match advertising source address of route") <string>("IP access-list name"), cli_del("route-map[].line[].match.ip.route-source $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") route-source("Match advertising source address of route") prefix-list("Match entries of prefix-lists"), cli_del("route-map[].line[].match.ip.route-source.prefix-list $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") ip("IP information") route-source("Match advertising source address of route") prefix-list("Match entries of prefix-lists") <string>("IP prefix-list name"), cli_del("route-map[].line[].match.ip.route-source.prefix-list $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;


    /* MATCH METRIC */
match("Match values from routing table") metric("Match metric of route") <uint32 range[0:4294967295]>("Metric value"), cli_set("route-map[].line[].match.metric $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $metric"), ADMIN;


no("Negate a command or set its defaults") match("Match values from routing table") metric("Match metric of route"), cli_del("route-map[].line[].match.metric $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") match("Match values from routing table") metric("Match metric of route") <uint32 range[0:4294967295]>("Metric value"), cli_del("route-map[].line[].match.metric $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;

    /* ON-MATCH */
on-match("Exit policy on matches") goto("Goto Clause number") <number range[1:65535]>("Number"), cli_set("route-map[].line[].on-match $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $op=(string)\"goto\" $goto"), ADMIN;
on-match("Exit policy on matches") next("Next clause"), cli_set("route-map[].line[].on-match $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $op=(string)\"next\""), ADMIN;

no("Negate a command or set its defaults") on-match("Exit policy on matches") goto("Goto Clause number"), cli_del("route-map[].line[].on-match $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $op=(string)\"goto\""), ADMIN;
no("Negate a command or set its defaults") on-match("Exit policy on matches") goto("Goto Clause number") <number range[1:65535]>("Number"), cli_del("route-map[].line[].on-match $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $op=(string)\"goto\" $goto"), ADMIN;
no("Negate a command or set its defaults") on-match("Exit policy on matches") next("Next clause"), cli_del("route-map[].line[].on-match $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $op=(string)\"next\""), ADMIN;
    

#ifdef notyet
    /* SET AGGREGATOR */
#endif /* notyet */

    /* SET AS-PATH */
set("Set values in destination routing protocol") as-path("Transform BGP AS-path attribute") exclude("Exclude from the as-path") <rest>("AS number list (space separated)"), cli_set("route-map[].line[].set.as-path.exclude $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $as_path"), ADMIN;
set("Set values in destination routing protocol") as-path("Transform BGP AS-path attribute") prepend("Prepend to the as-path") <rest>("AS number list (space separated)"), cli_set("route-map[].line[].set.as-path.prepend $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()  $as_path"), ADMIN;

no("Negate a command or set its defaults") set("Set values in destination routing protocol") as-path("Transform BGP AS-path attribute") exclude("Exclude from the as-path"), cli_del("route-map[].line[].set.as-path.exclude $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") as-path("Transform BGP AS-path attribute") exclude("Exclude from the as-path") <rest>("AS number list (space separated)"), cli_del("route-map[].line[].set.as-path.exclude $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $as_path"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") as-path("Transform BGP AS-path attribute") prepend("Prepend to the as-path"), cli_del("route-map[].line[].set.as-path.prepend $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") as-path("Transform BGP AS-path attribute") prepend("Prepend to the as-path") <rest>("AS number list (space separated)"), cli_del("route-map[].line[].set.as-path.prepend $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $as_path"), ADMIN;


#ifdef notyet
    /* SET ATOMIC-AGGREGATOR */
#endif /* notyet */

#ifdef notyet
    /* SET COMM-LIST */
#endif /* notyet */

#ifdef notyet
    /* SET COMMUNITY */
set("Set values in destination routing protocol") community("BGP community attribute") <rest>("Community list; aa:nn|local-AS|no-advertise|no-export|internet [additive]"), cli_rt_bgp_exec("set community %r"), ADMIN;
set("Set values in destination routing protocol") community("BGP community attribute") none("No community attribute"), cli_rt_bgp_exec("set community none"), ADMIN;

no("Negate a command or set its defaults") set("Set values in destination routing protocol") community("BGP community attribute"), cli_rt_bgp_exec("no set community"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") community("BGP community attribute") <rest>("Community list; aa:nn|local-AS|no-advertise|no-export|internet [additive]"), cli_rt_bgp_exec("no set community %r"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") community("BGP community attribute") none("No community attribute"), cli_rt_bgp_exec("no set community none"), ADMIN;
#endif /* notyet */

#ifdef notyet
    /* SET EXTCOMMUNIY */
#endif /* notyet */

#ifdef notyet
    /* SET FORWARDING-ADDRESS */
#endif /* notyet */

    /* SET IP NEXT-HOP */
set("Set values in destination routing protocol") ip("IP information") next-hop("Next hop address") <ipv4addr>("IP address of next hop"), cli_set("route-map[].line[].set.ip.next-hop $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $nexthop"), ADMIN;
set("Set values in destination routing protocol") ip("IP information") next-hop("Next hop address") peer-address("Use peer address (for BGP only)"), cli_set("route-map[].line[].set.ip.next-hop $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $nexthop=(string)\"peer-address\""), ADMIN;
    
    
no("Negate a command or set its defaults") set("Set values in destination routing protocol") ip("IP information") next-hop("Next hop address"), cli_del("route-map[].line[].set.ip.next-hop $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") ip("IP information") next-hop("Next hop address") <ipv4addr>("IP address of next hop"), cli_del("route-map[].line[].set.ip.next-hop $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $nexthop"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") ip("IP information") next-hop("Next hop address") peer-address("Use peer address (for BGP only)"), cli_del("route-map[].line[].set.ip.next-hop $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
      
#ifdef notyet
    /* SET IPV6 */
#endif /* notyet */

    /* SET LOCAL-PREFERENCE */
set("Set values in destination routing protocol") local-preference("BGP local preference path attribute") <uint32 range[0:4294967295]>("Preference value"), cli_set("route-map[].line[].set.local-preference $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $localpref"), ADMIN;

no("Negate a command or set its defaults") set("Set values in destination routing protocol") local-preference("BGP local preference path attribute"), cli_del("route-map[].line[].set.local-preference $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") local-preference("BGP local preference path attribute") <uint32 range[0:4294967295]>("Preference value"),  cli_del("route-map[].line[].set.local-preference $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $localpref"), ADMIN;

    /* SET METRIC */
set("Set values in destination routing protocol") metric("Metric value for destination routing protocol") <uint32 range[0:4294967295]>("Metric value"), cli_set("route-map[].line[].set.metric $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $metric"), ADMIN;
set("Set values in destination routing protocol") metric("Metric value for destination routing protocol") +("Add metric") <uint32 range[0:4294967295]>("Metric value"), cli_set("route-map[].line[].set.metric $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $op=(string)\"+\" $metric"), ADMIN;
set("Set values in destination routing protocol") metric("Metric value for destination routing protocol") -("Subtract metric") <uint32 range[0:4294967295]>("Metric value"), cli_set("route-map[].line[].set.metric $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $op=(string)\"-\" $metric"), ADMIN;

no("Negate a command or set its defaults") set("Set values in destination routing protocol") metric("Metric value for destination routing protocol"), cli_del("route-map[].line[].set.metric $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") metric("Metric value for destination routing protocol") +("Add metric") <uint32 range[0:4294967295]>("Metric value"), cli_del("route-map[].line[].set.metric $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") metric("Metric value for destination routing protocol") -("Subtract metric") <uint32 range[0:4294967295]>("Metric value"), cli_del("route-map[].line[].set.metric $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
    
    /* SET METRIC-TYPE */
set("Set values in destination routing protocol") metric-type("Type of metric") type-1("OSPF external type 1 metric"), cli_set("route-map[].line[].set.metric-type $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $metric_type=(string)\"type-1\""), ADMIN;
set("Set values in destination routing protocol") metric-type("Type of metric") type-2("OSPF external type 2 metric"), cli_set("route-map[].line[].set.metric-type $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $metric_type=(string)\"type-2\""), ADMIN;

no("Negate a command or set its defaults") set("Set values in destination routing protocol") metric-type("Type of metric"), cli_del("route-map[].line[].set.metric-type $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") metric-type("Type of metric") type-1("OSPF external type 1 metric"), cli_del("route-map[].line[].set.metric-type $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $metric_type=(string)\"type-1\""), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") metric-type("Type of metric") type-2("OSPF external type 2 metric"), cli_del("route-map[].line[].set.metric-type $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $metric_type=(string)\"type-2\""), ADMIN;

    /* SET ORIGIN */
set("Set values in destination routing protocol") origin("BGP origin code") egp("remote EGP"), cli_set("route-map[].line[].set.origin $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $origin=(string)\"egp\""), ADMIN;
set("Set values in destination routing protocol") origin("BGP origin code") igp("local IGP"), cli_set("route-map[].line[].set.origin $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $origin=(string)\"igp\""), ADMIN;
set("Set values in destination routing protocol") origin("BGP origin code") incomplete("unknown heritage"), cli_set("route-map[].line[].set.origin $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $origin=(string)\"incomplete\""), ADMIN;

no("Negate a command or set its defaults") set("Set values in destination routing protocol"), cli_del("route-map[].line[].set.origin $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") origin("BGP origin code") egp("remote EGP"), cli_del("route-map[].line[].set.origin $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $origin=(string)\"egp\""), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") origin("BGP origin code") igp("local IGP"), cli_del("route-map[].line[].set.origin $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $origin=(string)\"igp\""), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") origin("BGP origin code") incomplete("unknown heritage"), cli_del("route-map[].line[].set.origin $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $origin=(string)\"incomplete\""), ADMIN;


    /* SET ORIGINATOR-ID */
set("Set values in destination routing protocol") originator-id("BGP originator ID attribute") <ipv4addr>("IP address of originator"), cli_set("route-map[].line[].set.originator-id $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $originator_id"), ADMIN;

no("Negate a command or set its defaults") set("Set values in destination routing protocol") originator-id("BGP originator ID attribute"), cli_del("route-map[].line[].set.originator-id $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") originator-id("BGP originator ID attribute") <ipv4addr>("IP address of originator"), cli_del("route-map[].line[].set.originator-id $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;

    /* SET PATHLIMIT*/
set("Set values in destination routing protocol") pathlimit("BGP AS-Pathlimit attribute") ttl("Set AS-Path Hop-count TTL") <number range[1:255]>("TTL"), cli_set("route-map[].line[].set.pathlimit.ttl $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $ttl"), ADMIN;

no("Negate a command or set its defaults") set("Set values in destination routing protocol") pathlimit("BGP AS-Pathlimit attribute") ttl("Set AS-Path Hop-count TTL"), cli_del("route-map[].line[].set.pathlimit.ttl $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") pathlimit("BGP AS-Pathlimit attribute") ttl("Set AS-Path Hop-count TTL") <number range[1:255]>("TTL"), cli_del("route-map[].line[].set.pathlimit.ttl $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;

    /* SET TAG */
set("Set values in destination routing protocol") tag("Tag value for routing protocol") <number range[0:65535]>("Tag value"), cli_set("route-map[].line[].set.tag $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $route_tag"), ADMIN;

no("Negate a command or set its defaults") set("Set values in destination routing protocol") tag("Tag value for routing protocol"), cli_del("route-map[].line[].set.tag $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") tag("Tag value for routing protocol") <number range[0:65535]>("Tag value"), cli_del("route-map[].line[].set.tag $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $route_tag"), ADMIN;


    /* SET WEIGHT */
set("Set values in destination routing protocol") weight("BGP weight for routing table") <uint32 range[0:4294967295]>("Weight value"), cli_set("route-map[].line[].set.weight $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $weight"), ADMIN;

no("Negate a command or set its defaults") set("Set values in destination routing protocol") weight("BGP weight for routing table"), cli_del("route-map[].line[].set.weight $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb()"), ADMIN;
no("Negate a command or set its defaults") set("Set values in destination routing protocol") weight("BGP weight for routing table") <uint32 range[0:4294967295]>("Weight value"), cli_del("route-map[].line[].set.weight $!name=ios_routemap_cb() $!line=ios_routemap_cb() $_SEQ=ios_routemap_cb() $action=ios_routemap_cb() $weight"), ADMIN;

