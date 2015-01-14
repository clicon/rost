/*
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
CLICON_MODE=STRINGIFY(IOS_BGP_NONEIGHBOR);

/* NO NEIGHBOR ADVERTISEMENT-INTERVAL */
advertisement-interval("Minimum interval between sending BGP routing updates") <number range[0:600]>("Minimum interval between sending BGP routing updates"), cli_del("router.bgp.neighbor[].advertisement-interval $!neighbor"), ADMIN;
advertisement-interval("Minimum interval between sending BGP routing updates"), cli_del("router.bgp.neighbor[].advertisement-interval $!neighbor"), ADMIN;

/* NEIGHBOR ALLOWAS-IN */
allowas-in("Accept as-path with my AS present in it"), cli_del("router.bgp.neighbor[].allowas-in $!neighbor"), ADMIN;
allowas-in("Accept as-path with my AS present in it") <num_as:int8 range[1:10] show:1-10>, cli_del("router.bgp.neighbor[].allowas-in $!neighbor $num_as"), ADMIN;

/* NO NEIGHBOR DEFAULT-ORIGINATE */
default-originate("Originate default route to this neighbor"), cli_del("router.bgp.neighbor[].default-originate $!neighbor"), ADMIN;
default-originate("Originate default route to this neighbor") route-map("Route-map to specify criteria to originate default"), cli_del("router.bgp.neighbor[].default-originate $!neighbor $route_map"), ADMIN;

/* NO NEIGHBOR DESCRIPTION */
description("Neighbor specific description") <rest>("Up to 80 characters describing this neighbor"), cli_del("router.bgp.neighbor[].description $!neighbor"), ADMIN;
description("Neighbor specific description"), cli_del("router.bgp.neighbor[].description $!neighbor"), ADMIN;


/* NO NEIGHBOR DISTRIBUTE-LIST */
distribute-list("Filter updates to/from this neighbor") <string>("IP Access-list name") in("Filter incoming updates"), cli_del("router.bgp.neighbor[].distribute-list.in $!neighbor $acl"), ADMIN;
distribute-list("Filter updates to/from this neighbor") <string>("IP Access-list name") out("Filter outgoing updates"), cli_del("router.bgp.neighbor[].distribute-list.out $!neighbor $acl"), ADMIN;


/* NO NEIGHBOR EBGP-MULTIHOP */
ebgp-multihop("Allow EBGP neighbors not on directly connected networks"), cli_del("router.bgp.neighbor[].ebgp-multihop $!neighbor"), ADMIN;
ebgp-multihop("expand_Allow EBGP neighbors not on directly connected networks") <number range[1:255]>("maximum hop count"), cli_del("router.bgp.neighbor[].ebgp-multihop $!neighbor"), ADMIN;

/* NO NEIGHBOR FILTER-LIST */
filter-list("Establish BGP filters") <string>("AS path access-list name") in("Filter incoming expand_updates"), cli_del("router.bgp.neighbor[].filter-list.in $!neighbor $acl"), ADMIN;
filter-list("expand_Establish BGP filters") <string>("AS path access-list name") out("Filter outgoing updates"), cli_del("router.bgp.neighbor[].filter-list.out $!neighbor $acl"), ADMIN;


/* NO NEIGHBOR LOCAL-AS */
local-as("Specify a local-as number"), cli_del("router.bgp.neighbor[].local-as $!neighbor"), ADMIN;
local-as("Specify a local-as number") <uint32 range[1:4294967295]>("AS number used as local AS"), cli_del("router.bgp.neighbor[].local-as $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("expand_Neighbor address") local-as("Specify a local-as number") <uint32 range[1:4294967295]>("AS number used as local AS") no-prepend("Do not prepend local-as to updates from ebgp peers"), cli_del("router.bgp.neighbor[].local-as $!neighbor"), ADMIN;

/* NO NEIGHBOR NEXT-HOP-SELF */
no("Negate a command or set its defaults") neighbor("Specify expand_a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") next-hop-self("Disable the next hop calculation for this neighbor"), cli_del("router.bgp.neighbor[].next-hop-self $!neighbor"), ADMIN;


/* NO NEIGHBOR PASSIVE */
passive("Don't send open messages to this neighbor"), cli_del("router.bgp.neighbor[].passive $!neighbor"), ADMIN;


/* NO NEIGHBOR PASSWORD */
password("Set a password"), cli_del("router.bgp.neighbor[].password $!neighbor $password"), ADMIN;

/* NEIGHBOR PEER-GROUP */
peer-group("Member of the peer-group") <peergroup:string show:WORD>("peer-group name"), cli_del("router.bgp.neighbor[].peer-group $!neighbor $peergroup"), ADMIN;

/* NO NEIGHBOR REMOVE-PRIVATE-AS */
remove-private-as("Remove private AS number from outbound updates"), cli_del("router.bgp.neighbor[].remove-private-as $!neighbor"), ADMIN;


/* NO NEIGHBOR PREFIX-LIST */


prefix-list("Filter updates to/from this neighbor") <string>("Name of a prefix list") in("Filter incoming updates"), cli_del("router.bgp.neighbor[].prefix-list.in $!neighbor $prefix_list"), ADMIN;
prefix-list("Filter updates to/from this neighbor") <string>("Name of a prefix list") out("Filter outgoing updates"), cli_del("router.bgp.neighbor[].prefix-list.out $!neighbor $prefix_list"), ADMIN;


/* NO NEIGHBOR REMOTE-AS */
remote-as("Specify a BGP neighbor") <number range[1:65535]>("AS of remote neighbor"), cli_del("router.bgp.neighbor[].remote-as $!neighbor $remote_as"), ADMIN;


/* NO NEIGHBOR ROUTEMAP */
route-map("Apply route map to neighbor") <string>("Name of route map") in("Apply map to incoming routes"), cli_del("router.bgp.neighbor[].route-map.in $!neighbor $route_map"), ADMIN;
route-map("Apply route map to neighbor") <string>("Name of route map") out("Apply map to outbound routes"), cli_del("router.bgp.neighbor[].route-map.out $!neighbor $route_map"), ADMIN;


/* NO NEIGHBOR SHUTDOWN */
shutdown("Administratively shut down this neighbor"), cli_del("router.bgp.neighbor[].shutdown $!neighbor"), ADMIN;


/* NO NEIGHBOR SOFT-RECONFIGURATION */
soft-reconfiguration("Per neighbor soft reconfiguration") inbound("Allow inbound soft reconfiguration for this neighbor"), cli_del("router.bgp.neighbor[].soft-reconfiguration.inbound $!neighbor"), ADMIN;


/* NO NEIGHBOR TIMERS */
timers("BGP per neighbor timers") connect("BGP connect timer"), cli_del("router.bgp.neighbor[].timers.connect $!neighbor"), ADMIN;
timers("BGP per neighbor timers") connect("BGP connect timer") <number range[0:65535]>("Connect timer"), cli_del("router.bgp.neighbor[].timers.connect $!neighbor"), ADMIN;
timers("BGP per neighbor timers"), cli_del("router.bgp.neighbor[].timers $!neighbor"), ADMIN;

/* NO NEIGHBOR UPDATE-SOURCE */
update-source("Source of routing updates"), cli_del("router.bgp.neighbor[].update-source $!neighbor"), ADMIN;
update-source("Source of routing updates") <neighbor:ipv4addr>("IPv4 address"), cli_del("router.bgp.neighbor[].update-source $!neighbor"), ADMIN;
update-source("Source of routing updates") <interface>("Interface name"), cli_del("router.bgp.neighbor[].update-source $!neighbor"), ADMIN;


/* NO NEIGHBOR WEIGHT */
weight("Set default weight for routes from this neighbor"), cli_del("router.bgp.neighbor[].weight $!neighbor"), ADMIN;
weight("Set default weight for routes from this neighbor") <number range[0:65535]>("default weight"), cli_del("router.bgp.neighbor[].weight $!neighbor"), ADMIN;

