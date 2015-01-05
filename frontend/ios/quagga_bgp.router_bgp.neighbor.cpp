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
CLICON_MODE=STRINGIFY(IOS_BGP_NEIGHBOR);

/* NEIGHBOR ADVERTISEMENT-INTERVAL */
advertisement-interval("Minimum interval between sending BGP routing updates") <number range[0:600]>("Minimum interval between sending BGP routing updates"), cli_set("router.bgp.neighbor[].advertisement-interval $!neighbor $interval"), ADMIN;

/* NEIGHBOR ALLOWAS-IN */
allowas-in("Accept as-path with my AS present in it"), cli_set("router.bgp.neighbor[].allowas-in $!neighbor"), ADMIN;
allowas-in("Accept as-path with my AS present in it") <num_as:int8 range[1:10] show:1-10>, cli_set("router.bgp.neighbor[].allowas-in $!neighbor $num_as"), ADMIN;

/* NEIGHBOR DEFAULT-ORIGINATE */
default-originate("Originate default route to this neighbor"), cli_set("router.bgp.neighbor[].default-originate $!neighbor"), ADMIN;
default-originate("Originate default route to this neighbor") route-map("Route-map to specify criteria to originate default") <string>("route-map name"), cli_set("router.bgp.neighbor[].default-originate $!neighbor $route_map"), ADMIN;


/* NEIGHBOR DESCRIPTION */
description("Neighbor specific description") <rest>("Up to 80 characters describing this neighbor"), cli_set("router.bgp.neighbor[].description $!neighbor $description"), ADMIN;


/* NEIGHBOR DISTRIBUTE-LIST */
distribute-list("Filter updates to/from this neighbor") <string>("IP Access-list name") in("Filter incoming updates"), cli_set("router.bgp.neighbor[].distribute-list.in $!neighbor $acl"), ADMIN;
distribute-list("Filter updates to/from this neighbor") <string>("IP Access-list name") out("Filter outgoing updates"), cli_set("router.bgp.neighbor[].distribute-list.out $!neighbor $acl"), ADMIN;


/* NEIGHBOR EBGP-MULTIHOP */
ebgp-multihop("Allow EBGP neighbors not on directly connected networks"),  cli_set("router.bgp.neighbor[].ebgp-multihop $!neighbor"), ADMIN;
ebgp-multihop("Allow EBGP neighbors not on directly connected networks") <number range[1:255]>("maximum hop count"), cli_set("router.bgp.neighbor[].ebgp-multihop $!neighbor $maxhops"), ADMIN;


/* NEIGHBOR FILTER-LIST */
expand_filter-list("Establish BGP filters") <string>("AS path access-list name") in("Filter incoming updates"), cli_set("router.bgp.neighbor[].filter-list.in $!neighbor $acl"), ADMIN;
expand_filter-list("Establish BGP filters") <string>("AS path access-list name") out("Filter outgoing updates"), cli_set("router.bgp.neighbor[].filter-list.out $!neighbor $acl"), ADMIN;



/* NEIGHBOR LOCAL-AS */
neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") local-as("Specify a local-as number") <uint32 range[1:4294967295]>("AS number used as local AS"),  cli_set("router.bgp.neighbor[].local-as $!neighbor $localas"), ADMIN;
neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") local-as("Specify a local-as number") <uint32 range[1:4294967295]>("AS number used as local AS") no-prepend("Do not prepend local-as to updates from ebgp peers"), cli_set("router.bgp.neighbor[].local-as $!neighbor $localas $no_prepend=(string)\"no-prepend\""), expand_ADMIN;

/* MAXIMUM-PREFIX */ 
maximum-prefix("Maximum number of prefix accept from this peer") <uint32 range[1:4294967295]>("Maximum no. of prefix limit"), cli_set("router.bgp.neighbor[].maximum-prefix $!neighbor $maxprefix $threshold=(uint8)75 $restart=(uint16)0 $warning_only=(bool)false"); {
  <uint8 range[1:100]>("Threshold value (%) at which to generate a warning msg"), cli_set("router.bgp.neighbor[].maximum-prefix $!neighbor $maxprefix $threshold $restart=(uint16)0 $warning_only=(bool)false"); {
    restart("Restart bgp connection after limit is exceeded") <uint16 range[1:65535]>("Restart interval in minutes"), cli_set("router.bgp.neighbor[].maximum-prefix $!neighbor $maxprefix $threshold $restart_interval $warning_only=(bool)false");
    warning-only("Only give warning message when limit is exceeded"), cli_set("router.bgp.neighbor[].maximum-prefix $!neighbor $maxprefix $threshold $restart_interval=(uint16)0 $warning_only=(bool)true");
  }
  restart("Restart bgp connection after limit is exceeded") <uint16 range[1:65535]>("Restart interval in minutes"), cli_set("router.bgp.neighbor[].maximum-prefix $!neighbor $maxprefix $threshold=(uint8)75 $restart_interval $warning_only=(bool)false");
    warning-only("Only give warning message when limit is exceeded"), cli_set("router.bgp.neighbor[].maximum-prefix $!neighbor $maxprefix $threshold=(uint8)0 $restart_interval=(uint16)0 $warning_only=(bool)true");
}

/* NEIGHBOR NEXT-HOP-SELF */
neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") next-hop-self("Disable the next hop calculation for this neighbor"), cli_set("router.bgp.neighbor[].next-hop-self $!neighbor"), ADMIN;


/* NEIGHBOR PASSIVE */
neighbor("Specify a neighbor expand_router") <neighbor:ipv4addr>("Neighbor address") passive("Don't send open messages to this neighbor"), cli_set("router.bgp.neighbor[].passive $!neighbor"), ADMIN;


/* NEIGHBOR PASSWORD */
password("Set a password") <string>("The password"), cli_set("router.bgp.neighbor[].password $!neighbor $password"), ADMIN;


/* NEIGHBOR PEER-GROUP */
peer-group("Member of the peer-group") <peergroup:string show:WORD>("peer-group name"), cli_set("router.bgp.neighbor[].peer-group $!neighbor $peergroup"), ADMIN;

/* NEIGHBOR REMOVE-PRIVATE-AS */
remove-private-as("Remove private AS number from outbound updates"),  cli_set("router.bgp.neighbor[].remove-private-as $!neighbor"), ADMIN;


/* NEIGHBOR PREFIX-LIST */
prefix-list("Filter updates to/from this neighbor") <string>("Name of a prefix list") in("Filter incoming updates"), cli_set("router.bgp.neighbor[].prefix-list.in $!neighbor $prefix_list"), ADMIN;

prefix-list("Filter updates to/from this neighbor") <string>("Name of a prefix list") out("Filter outgoing updates"), cli_set("router.bgp.neighbor[].prefix-list.out $!neighbor $prefix_list"), ADMIN;



/* NEIGHBOR REMOTE-AS */
#ifdef notyet
neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") remote-as("Specify a BGP neighbor") <uint32 range[1:4294967295]>("AS of remote neighbor"), cli_set("router.bgp.neighbor[].remote-as $!neighbor $remote_as"), ADMIN;
neighbor("Specify a neighbor router") <neighbor:ipv4addr>("Neighbor address") remote-as("Specify a BGP neighbor") <uint32 range[1:4294967295]>("AS of remote neighbor"), cli_set("router.bgp.neighbor[].remote-as $!neighbor $remote_as"), ADMIN;
#endif
remote-as("Specify a BGP neighbor") <uint32 range[1:4294967295]>("AS of remote neighbor"), cli_set("router.bgp.neighbor[].remote-as $!neighbor $remote_as"), ADMIN;



/* NEIGHBOR ROUTEMAP */
route-map("Apply route map to neighbor") <string>("Name of route map") in("Apply map to incoming routes"), cli_set("router.bgp.neighbor[].route-map.in $!neighbor $route_map"), ADMIN;
route-map("Apply route map to neighbor") <string>("Name of route map") out("Apply map to outbound routes"), cli_set("router.bgp.neighbor[].route-map.out $!neighbor $route_map"), ADMIN;



/* NEIGHBOR SHUTDOWN */
shutdown("Administratively shut down this neighbor"), cli_set("router.bgp.neighbor[].shutdown $!neighbor"), ADMIN;


/* NEIGHBOR SOFT-RECONFIGURATION */
soft-reconfiguration("Per neighbor soft reconfiguration") inbound("Allow inbound soft reconfiguration for this neighbor"), cli_set("router.bgp.neighbor[].soft-reconfiguration.inbound $!neighbor"), ADMIN;


/* NEIGHBOR TIMERS */
timers("BGP per neighbor timers") connect("BGP connect timer") <number range[0:65535]>("Connect timer"), cli_set("router.bgp.neighbor[].timers.connect $!neighbor $connect"), ADMIN;
timers("BGP per neighbor timers") <number range[0:65535]>("Keepalive interval") <number range[0:65535]>("Holdtime"), cli_set("router.bgp.neighbor[].timers $!neighbor $keepalive $holdtime"), ADMIN;


/* NEIGHBOR UPDATE-SOURCE */
update-source("Source of routing updates") <neighbor:ipv4addr>("IPv4 address"), cli_set("router.bgp.neighbor[].update-source $!neighbor $source"), ADMIN;
update-source("Source of routing updates") <interface>("Interface name"), cli_set("router.bgp.neighbor[].update-source $!neighbor $source"), ADMIN;
    



/* NEIGHBOR WEIGHT */
weight("Set default weight for routes from this neighbor") <number range[0:65535]>("default weight"), cli_set("router.bgp.neighbor[].weight $!neighbor $weight"), ADMIN;
