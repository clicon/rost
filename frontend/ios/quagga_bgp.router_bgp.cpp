/*
 * CVS Version: $Id: quagga_bgp.router_bgp.cpp,v 1.11 2014/01/10 14:08:25 olof Exp $
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
CLICON_MODE=STRINGIFY(IOS_BGP);

/* AGGREGATE-ADDRESS <ipv4prefix> */
aggregate-address("Configure BGP aggregate entries") <ipv4prefix>("Aggregate prefix"), cli_set("router.bgp.aggregate-address[] $!prefix"), ADMIN; {
	as-set("Generate AS set path information"),  cli_set("router.bgp.aggregate-address[] $!prefix $as_set=(string)\"as-set\"")

 

, ADMIN;
	summary-only("Filter more specific routes from updates"), cli_set("router.bgp.aggregate-address[] $!prefix $summary_only=(string)\"summary-only\""), ADMIN;
 	summary-only("Filter more specific routes from updates") as-set("Generate AS set path information"), cli_set("router.bgp.aggregate-address[] $!prefix $summary_only=(string)\"summary-only\" $as_set=(string)\"as-set\""), ADMIN;
	as-set("Generate AS set path information") summary-only("Filter more specific routes from updates"), cli_set("router.bgp.aggregate-address[] $!prefix $summary_only=(string)\"summary-only\" $as_set=(string)\"as-set\""), ADMIN;
} /* AGGREGATE-ADDRESS <ipv4prefix> */

/* NO AGGREGATE-ADDRESS <ipv4prefix> */
no("Negate a command or set its defaults") aggregate-address("Configure BGP aggregate entries") <ipv4prefix>("Aggregate prefix") [(as-set("Generate AS set path information")|as-set("Generate AS set path information") summary-only("Filter more specific routes from updates")|summary-only("Filter more specific routes from updates")|summary-only("Filter more specific routes from updates") as-set("Generate AS set path information"))], cli_del("router.bgp.aggregate-address[] $!prefix"), ADMIN;


/* BGP ALWAYS-COMPARE-MED */
bgp("BGP specific commands") always-compare-med("Allow comparing MED from different neighbors"), cli_set("router.bgp.always-compare-med $status=(int)1"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") always-compare-med("Allow comparing MED from different neighbors"), cli_del("router.bgp.always-compare-med"), ADMIN;

#ifdef notyet
/* BGP BESTPATH */
bgp("BGP specific commands") bestpath("Change the default bestpath selection") as-path("AS-path attribute") ignore("Ignore as-path length in selecting a route"), cli_set("router.bgp.bestpath.as-path ignore"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") bestpath("Change the default bestpath selection") as-path("AS-path attribute") ignore("Ignore as-path length in selecting a route"), cli_bgp_exec("no bgp bestpath as-path ignore"), ADMIN;

bgp("BGP specific commands") bestpath("Change the default bestpath selection") compare-routerid("Compare router-id for identical EBGP paths"), cli_bgp_exec("bgp bestpath compare-routerid"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") bestpath("Change the default bestpath selection") compare-routerid("Compare router-id for identical EBGP paths"), cli_bgp_exec("no bgp bestpath compare-routerid"), ADMIN;

bgp("BGP specific commands") bestpath("Change the default bestpath selection") confed("Compare MED among confederation paths"), cli_bgp_exec("bgp bestpath med confed"), ADMIN;
bgp("BGP specific commands") bestpath("Change the default bestpath selection") missing-as-worst("Treat missing MED as the least preferred one"), cli_bgp_exec("bgp bestpath med missing-as-worst"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") bestpath("Change the default bestpath selection") confed("Compare MED among confederation paths"), cli_bgp_exec("no bgp bestpath med confed"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") bestpath("Change the default bestpath selection") missing-as-worst("Treat missing MED as the least preferred one"), cli_bgp_exec("no bgp bestpath med missing-as-worst"), ADMIN;
#endif /* notyet */

/* BGP DAMPENING */
bgp("BGP specific commands") dampening("Enable route-flap dampening"), cli_set("router.bgp.dampening $status=(int)1"), ADMIN; {
    <number range[1:45]>("Half-life time for the penalty"), cli_set("router.bgp.dampening $half_life"), ADMIN;
    <number range[1:45]>("Half-life time for the penalty") <number range[1:20000]>("Value to start reusing a route") <number range[1:20000]>("Value to start suppressing a route") <number range[1:255]>("Maximum duration to suppress a stable route"), cli_set("router.bgp.dampening $half_'life $reuse $suppress $max_suppress"), ADMIN;
} /* BGP DAMPENING */

no("Negate a command or set its defaults") bgp("BGP specific commands") dampening("Enable route-flap dampening"), cli_del("router.bgp.dampening $status=(int)0"), ADMIN; {
    <number range[1:45]>("Half-life time for the penalty"), cli_del("router.bgp.dampening $status=(int)0"), ADMIN;
    <number range[1:45]>("Half-life time for the penalty") <number range[1:20000]>("Value to start reusing a route") <number range[1:20000]>("Value to start suppressing a route") <number range[1:255]>("Maximum duration to suppress a stable route"), cli_del("router.bgp.dampening $status=(int)0"), ADMIN;
} /* NO BGP DAMPENING */

/* BGP DEFAULT */
#ifdef notyet
bgp("BGP specific commands") default("Configure BGP defaults") ipv4-unicast("Activate ipv4-unicast for a peer by default"), cli_set("router.bgp.default $ipv4_unicast=(string)\"ipv4-unicast\""), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") default("Configure BGP defaults") ipv4-unicast("Activate ipv4-unicast for a peer by default"),  cli_set("router.bgp.default $ipv4_unicast=(string)\"ipv4-unicast\""), ADMIN;
#endif /* notyet */
bgp("BGP specific commands") default("Configure BGP defaults") local-preference("local preference (higher=more preferred)") <uint32 range[0:4294967295]>("Configure default local preference value"), cli_set("router.bgp.default.local-preference $local_preference"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") default("Configure BGP defaults") local-preference("local preference (higher=more preferred)"), cli_del("router.bgp.default.local-preference"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") default("Configure BGP defaults") local-preference("local preference (higher=more preferred)") <uint32 range[0:4294967295]>("Configure default local preference value"), cli_del("router.bgp.default.local-preference"), ADMIN;


/* BGP DETERMINISTIC-MED */
bgp("BGP specific commands") deterministic-med("Pick the best-MED path among paths advertised from the neighboring AS"), cli_set("router.bgp.deterministic-med $status=(int)1"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") deterministic-med("Pick the best-MED path among paths advertised from the neighboring AS"), cli_del("router.bgp.deterministic-med"), ADMIN;


/* BGP ENFORCE-FIRST-AS */
bgp("BGP specific commands") enforce-first-as("Enforce the first AS for EBGP routes"), cli_set("router.bgp.enforce-first-as $status=(int)1"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") enforce-first-as("Enforce the first AS for EBGP routes"), cli_del("router.bgp.enforce-first-as"), ADMIN;

/* BGP LOG-NEIGHBOR-CHANGES */
bgp("BGP specific commands") log-neighbor-changes("Log neighbor up/down and reset reason"), cli_set("router.bgp.log-neighbor-changes $status=(int)1"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") log-neighbor-changes("Log neighbor up/down and reset reason"), cli_del("router.bgp.log-neighbor-changes"), ADMIN;

/* BGP NETWORK IMPORT-CHECK */
bgp("BGP specific commands") network("BGP network command") import-check("Check BGP network route exists in IGP"), cli_set("router.bgp.network.import-check $status=(int)1"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") network("BGP network command") import-check("Check BGP network route exists in IGP"), cli_del("router.bgp.network.import-check"), ADMIN;

      
/* BGP ROUTE-ID */
bgp("BGP specific commands") router-id("Override configured router identifier") <neighbor:ipv4addr>("Manually configured router identifier"), cli_set("router.bgp.router-id $routerid"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") router-id("Override configured router identifier"), cli_del("router.bgp.router-id"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") router-id("Override configured router identifier") <neighbor:ipv4addr>("Manually configured router identifier"), cli_del("router.bgp.router-id"), ADMIN;

/* BGP GRACEFUL-RESTART */
bgp("BGP specific commands") graceful-restart("Graceful restart capability parameters"), cli_set("router.bgp.graceful-restart"), ADMIN;
bgp("BGP specific commands") graceful-restart("Graceful restart capability parameters") stalepath-time("Set the max time to hold onto restarting peer's stale paths") <number range[1:3600]>("Delay value (seconds)"), cli_set("router.bgp.graceful-restart $stalepath_time"), ADMIN;

no("Negate a command or set its defaults") bgp("BGP specific commands") graceful-restart("Graceful restart capability parameters"), cli_del("router.bgp.graceful-restart"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") graceful-restart("Graceful restart capability parameters") stalepath-time("Set the max time to hold onto restarting peer's stale paths"), cli_del("router.bgp.graceful-restart"), ADMIN;
no("Negate a command or set its defaults") bgp("BGP specific commands") graceful-restart("Graceful restart capability parameters") stalepath-time("Set the max time to hold onto restarting peer's stale paths") <number range[1:3600]>("Delay value (seconds)"), cli_del("router.bgp.graceful-restart"), ADMIN;


/* DISTANCE */
distance("Define an administrative distance") <number range[1:255]>("Administrative distance") <ipv4prefix>("IP source prefix"), cli_set("router.bgp.distance[] $distance $!prefix"), ADMIN;
distance("Define an administrative distance") <number range[1:255]>("Administrative distance") <ipv4prefix>("IP source prefix") <string>("Access-list name"), cli_set("router.bgp.distance[] $distance $!prefix $acl"), ADMIN;
distance("Define an administrative distance") bgp("BGP distance") <number range[1:255]>("Distance for routes external to the AS") <number range[1:255]>("Distance for routes internal to the AS") <number range[1:255]>("Distance for local routes"), cli_set("router.bgp.distance.bgp $external $internal $local"), ADMIN;

no("Negate a command or set its defaults") distance("Define an administrative distance") <number range[1:255]>("Administrative distance") <ipv4prefix>("IP source prefix"), cli_del("router.bgp.distance[] $distance $!prefix"), ADMIN;
no("Negate a command or set its defaults") distance("Define an administrative distance") <number range[1:255]>("Administrative distance") <ipv4prefix>("IP source prefix") <string>("Access-list name"), cli_del("router.bgp.distance[] $distance $!prefix $acl"), ADMIN;
no("Negate a command or set its defaults") distance("Define an administrative distance") bgp("BGP distance"), cli_del("router.bgp.distance.bgp"), ADMIN;
no("Negate a command or set its defaults") distance("Define an administrative distance") bgp("BGP distance") <number range[1:255]>("Distance for routes external to the AS") <number range[1:255]>("Distance for routes internal to the AS") <number range[1:255]>("Distance for local routes"), cli_del("router.bgp.distance.bgp"), ADMIN;

/* NEIGHBOR ACTIVATE */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) activate("Enable the Address Family for this Neighbor"), cli_set("router.bgp.neighbor[].activate $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") activate("Enable the Address Family for this Neighbor"), cli_del("router.bgp.neighbor[].activate $!neighbor"), ADMIN;

/* NEIGHBOR ADVERTISEMENT-INTERVAL */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) advertisement-interval("Minimum interval between sending BGP routing updates") <number range[0:600]>("Minimum interval between sending BGP routing updates"), cli_set("router.bgp.neighbor[].advertisement-interval $!neighbor $interval"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") advertisement-interval("Minimum interval between sending BGP routing updates") <number range[0:600]>("Minimum interval between sending BGP routing updates"), cli_del("router.bgp.neighbor[].advertisement-interval $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") advertisement-interval("Minimum interval between sending BGP routing updates"), cli_del("router.bgp.neighbor[].advertisement-interval $!neighbor"), ADMIN;

/* NEIGHBOR DEFAULT-ORIGINATE */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) default-originate("Originate default route to this neighbor"), cli_set("router.bgp.neighbor[].default-originate $!neighbor"), ADMIN;
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) default-originate("Originate default route to this neighbor") route-map("Route-map to specify criteria to originate default") <string>("route-map name"), cli_set("router.bgp.neighbor[].default-originate $!neighbor $route_map"), ADMIN;

no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") default-originate("Originate default route to this neighbor"), cli_del("router.bgp.neighbor[].default-originate $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") default-originate("Originate default route to this neighbor") route-map("Route-map to specify criteria to originate default"), cli_del("router.bgp.neighbor[].default-originate $!neighbor $route_map"), ADMIN;

/* NEIGHBOR DESCRIPTION */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) description("Neighbor specific description") <rest>("Up to 80 characters describing this neighbor"), cli_set("router.bgp.neighbor[].description $!neighbor $description"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") description("Neighbor specific description") <rest>("Up to 80 characters describing this neighbor"), cli_del("router.bgp.neighbor[].description $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") description("Neighbor specific description"), cli_del("router.bgp.neighbor[].description $!neighbor"), ADMIN;


/* NEIGHBOR DISTRIBUTE-LIST */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) distribute-list("Filter updates to/from this neighbor") <string>("IP Access-list name") in("Filter incoming updates"), cli_set("router.bgp.neighbor[].distribute-list.in $!neighbor $acl"), ADMIN;
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) distribute-list("Filter updates to/from this neighbor") <string>("IP Access-list name") out("Filter outgoing updates"), cli_set("router.bgp.neighbor[].distribute-list.out $!neighbor $acl"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") distribute-list("Filter updates to/from this neighbor") <string>("IP Access-list name") in("Filter incoming updates"), cli_del("router.bgp.neighbor[].distribute-list.in $!neighbor $acl"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") distribute-list("Filter updates to/from this neighbor") <string>("IP Access-list name") out("Filter outgoing updates"), cli_del("router.bgp.neighbor[].distribute-list.out $!neighbor $acl"), ADMIN;


/* NEIGHBOR EBGP-MULTIHOP */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) ebgp-multihop("Allow EBGP neighbors not on directly connected networks"),  cli_set("router.bgp.neighbor[].ebgp-multihop $!neighbor"), ADMIN;
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) ebgp-multihop("Allow EBGP neighbors not on directly connected networks") <number range[1:255]>("maximum hop count"), cli_set("router.bgp.neighbor[].ebgp-multihop $!neighbor $maxhops"), ADMIN;

no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") ebgp-multihop("Allow EBGP neighbors not on directly connected networks"), cli_del("router.bgp.neighbor[].ebgp-multihop $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") ebgp-multihop("expand_Allow EBGP neighbors not on directly connected networks") <number range[1:255]>("maximum hop count"), cli_del("router.bgp.neighbor[].ebgp-multihop $!neighbor"), ADMIN;

/* NEIGHBOR FILTER-LIST */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) expand_filter-list("Establish BGP filters") <string>("AS path access-list name") in("Filter incoming updates"), cli_set("router.bgp.neighbor[].filter-list.in $!neighbor $acl"), ADMIN;
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) expand_filter-list("Establish BGP filters") <string>("AS path access-list name") out("Filter outgoing updates"), cli_set("router.bgp.neighbor[].filter-list.out $!neighbor $acl"), ADMIN;

no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") filter-list("Establish BGP filters") <string>("AS path access-list name") in("Filter incoming expand_updates"), cli_del("router.bgp.neighbor[].filter-list.in $!neighbor $acl"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") filter-list("expand_Establish BGP filters") <string>("AS path access-list name") out("Filter outgoing updates"), cli_del("router.bgp.neighbor[].filter-list.out $!neighbor $acl"), ADMIN;


/* NEIGHBOR LOCAL-AS */
neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") local-as("Specify a local-as number") <uint32 range[1:4294967295]>("AS number used as local AS"),  cli_set("router.bgp.neighbor[].local-as $!neighbor $localas"), ADMIN;
neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") local-as("Specify a local-as number") <uint32 range[1:4294967295]>("AS number used as local AS") no-prepend("Do not prepend local-as to updates from ebgp peers"), cli_set("router.bgp.neighbor[].local-as $!neighbor $localas $no_prepend=(string)\"no-prepend\""), expand_ADMIN;

no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") local-as("Specify a local-as number"), cli_del("router.bgp.neighbor[].local-as $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") local-as("Specify a local-as number") <uint32 range[1:4294967295]>("AS number used as local AS"), cli_del("router.bgp.neighbor[].local-as $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("expand_Neighbor address") local-as("Specify a local-as number") <uint32 range[1:4294967295]>("AS number used as local AS") no-prepend("Do not prepend local-as to updates from ebgp peers"), cli_del("router.bgp.neighbor[].local-as $!neighbor"), ADMIN;

/* NEIGHBOR NEXT-HOP-SELF */
neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") next-hop-self("Disable the next hop calculation for this neighbor"), cli_set("router.bgp.neighbor[].next-hop-self $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify expand_a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") next-hop-self("Disable the next hop calculation for this neighbor"), cli_del("router.bgp.neighbor[].next-hop-self $!neighbor"), ADMIN;


/* NEIGHBOR PASSIVE */
neighbor("Specify a neighbor expand_router") <neighbor:ipv4addr>("Neighbor address") passive("Don't send open messages to this neighbor"), cli_set("router.bgp.neighbor[].passive $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") passive("Don't send open messages to this neighbor"), cli_del("router.bgp.neighbor[].passive $!neighbor"), ADMIN;


/* NEIGHBOR PASSWORD */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) password("Set a password") <string>("The password"), cli_set("router.bgp.neighbor[].password $!neighbor $password"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") password("Set a password"), cli_del("router.bgp.neighbor[].password $!neighbor $password"), ADMIN;


#if notyet
/* NEIGHBOR PEER-GROUP */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) peer-group("Member of the peer-group") <string>("peer-group name"), cli_bgp_exec("neighbor %a peer-group %s"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") peer-group("Member of the peer-group") <string>("peer-group name"), cli_bgp_exec("no neighbor %a peer-group %s"), ADMIN;
#endif

/* NEIGHBOR REMOVE-PRIVATE-AS */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) remove-private-as("Remove private AS number from outbound updates"),  cli_set("router.bgp.neighbor[].remove-private-as $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") remove-private-as("Remove private AS number from outbound updates"), cli_del("router.bgp.neighbor[].remove-private-as $!neighbor"), ADMIN;


/* NEIGHBOR PREFIX-LIST */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) prefix-list("Filter updates to/from this neighbor") <string>("Name of a prefix list") in("Filter incoming updates"), cli_set("router.bgp.neighbor[].prefix-list.in $!neighbor $prefix_list"), ADMIN;

neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) prefix-list("Filter updates to/from this neighbor") <string>("Name of a prefix list") out("Filter outgoing updates"), cli_set("router.bgp.neighbor[].prefix-list.out $!neighbor $prefix_list"), ADMIN;

no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") prefix-list("Filter updates to/from this neighbor") <string>("Name of a prefix list") in("Filter incoming updates"), cli_del("router.bgp.neighbor[].prefix-list.in $!neighbor $prefix_list"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") prefix-list("Filter updates to/from this neighbor") <string>("Name of a prefix list") out("Filter outgoing updates"), cli_del("router.bgp.neighbor[].prefix-list.out $!neighbor $prefix_list"), ADMIN;


/* NEIGHBOR REMOTE-AS */
#ifdef notyet
neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") remote-as("Specify a BGP neighbor") <number range[1:65535]>("AS of remote neighbor"), cli_set("router.bgp.neighbor[].remote-as $!neighbor $remote_as"), ADMIN;
neighbor("Specify a neighbor router") <neighbor:ipv4addr>("Neighbor address") remote-as("Specify a BGP neighbor") <number range[1:65535]>("AS of remote neighbor"), cli_set("router.bgp.neighbor[].remote-as $!neighbor $remote_as"), ADMIN;
#endif
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) remote-as("Specify a BGP neighbor") <number range[1:65535]>("AS of remote neighbor"), cli_set("router.bgp.neighbor[].remote-as $!neighbor $remote_as"), ADMIN;

no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") remote-as("Specify a BGP neighbor") <number range[1:65535]>("AS of remote neighbor"), cli_del("router.bgp.neighbor[].remote-as $!neighbor $remote_as"), ADMIN;


/* NEIGHBOR ROUTEMAP */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) route-map("Apply route map to neighbor") <string>("Name of route map") in("Apply map to incoming routes"), cli_set("router.bgp.neighbor[].route-map.in $!neighbor $route_map"), ADMIN;
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) route-map("Apply route map to neighbor") <string>("Name of route map") out("Apply map to outbound routes"), cli_set("router.bgp.neighbor[].route-map.out $!neighbor $route_map"), ADMIN;

no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") route-map("Apply route map to neighbor") <string>("Name of route map") in("Apply map to incoming routes"), cli_del("router.bgp.neighbor[].route-map.in $!neighbor $route_map"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") route-map("Apply route map to neighbor") <string>("Name of route map") out("Apply map to outbound routes"), cli_del("router.bgp.neighbor[].route-map.out $!neighbor $route_map"), ADMIN;


/* NEIGHBOR SHUTDOWN */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) shutdown("Administratively shut down this neighbor"), cli_set("router.bgp.neighbor[].shutdown $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") shutdown("Administratively shut down this neighbor"), cli_del("router.bgp.neighbor[].shutdown $!neighbor"), ADMIN;


/* NEIGHBOR SOFT-RECONFIGURATION */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) soft-reconfiguration("Per neighbor soft reconfiguration") inbound("Allow inbound soft reconfiguration for this neighbor"), cli_set("router.bgp.neighbor[].soft-reconfiguration.inbound $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") soft-reconfiguration("Per neighbor soft reconfiguration") inbound("Allow inbound soft reconfiguration for this neighbor"), cli_del("router.bgp.neighbor[].soft-reconfiguration.inbound $!neighbor"), ADMIN;


/* NEIGHBOR TIMERS */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) timers("BGP per neighbor timers") connect("BGP connect timer") <number range[0:65535]>("Connect timer"), cli_set("router.bgp.neighbor[].timers.connect $!neighbor $connect"), ADMIN;
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) timers("BGP per neighbor timers") <number range[0:65535]>("Keepalive interval") <number range[0:65535]>("Holdtime"), cli_set("router.bgp.neighbor[].timers $!neighbor $keepalive $holdtime"), ADMIN;

no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") timers("BGP per neighbor timers") connect("BGP connect timer"), cli_del("router.bgp.neighbor[].timers.connect $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") timers("BGP per neighbor timers") connect("BGP connect timer") <number range[0:65535]>("Connect timer"), cli_del("router.bgp.neighbor[].timers.connect $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") timers("BGP per neighbor timers"), cli_del("router.bgp.neighbor[].timers $!neighbor"), ADMIN;

/* NEIGHBOR UPDATE-SOURCE */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) update-source("Source of routing updates") <neighbor:ipv4addr>("IPv4 address"), cli_set("router.bgp.neighbor[].update-source $!neighbor $source"), ADMIN;
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) update-source("Source of routing updates") <interface>("Interface name"), cli_set("router.bgp.neighbor[].update-source $!neighbor $source"), ADMIN;
    

no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") update-source("Source of routing updates"), cli_del("router.bgp.neighbor[].update-source $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") update-source("Source of routing updates") <neighbor:ipv4addr>("IPv4 address"), cli_del("router.bgp.neighbor[].update-source $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") update-source("Source of routing updates") <interface>("Interface name"), cli_del("router.bgp.neighbor[].update-source $!neighbor"), ADMIN;


/* NEIGHBOR WEIGHT */
neighbor("Specify a neighbor router") (<neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address")|<neighbor:ipv4addr>("Neighbor address")) weight("Set default weight for routes from this neighbor") <number range[0:65535]>("default weight"), cli_set("router.bgp.neighbor[].weight $!neighbor $weight"), ADMIN;

no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") weight("Set default weight for routes from this neighbor"), cli_del("router.bgp.neighbor[].weight $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <neighbor:ipv4addr expand_bgp_neighbor()>("Neighbor address") weight("Set default weight for routes from this neighbor") <number range[0:65535]>("default weight"), cli_del("router.bgp.neighbor[].weight $!neighbor"), ADMIN;


/* NETWORK */
network("Specify a network to announce via BGP") <ipv4prefix>("IP prefix"), cli_set("router.bgp.network[] $!prefix"), ADMIN;
network("Specify a network to announce via BGP") <ipv4prefix>("IP prefix") route-map("Route-map to modify the attributes") <string>("Name of the route map"), cli_set("router.bgp.network[] $!prefix $route_map"), ADMIN;

no("Negate a command or set its defaults") network("Specify a network to announce via BGP") <ipv4prefix>("IP prefix"), cli_del("router.bgp.network[] $!prefix"), ADMIN;
no("Negate a command or set its defaults") network("Specify a network to announce via BGP") <ipv4prefix>("IP prefix") route-map("Route-map to modify the attributes") <string>("Name of the route map"), cli_del("router.bgp.network[] $!prefix"), ADMIN;

/* REDISTRIBUTE CONNECTED */
redistribute("Redistribute information from another routing protocol") connected("Connected routes"), cli_set("router.bgp.redistribute.connected $status=(int)1"), ADMIN;
redistribute("Redistribute information from another routing protocol") connected("Connected routes") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_set("router.bgp.redistribute.connected $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") connected("Connected routes") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_set("router.bgp.redistribute.connected $metric $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") connected("Connected routes") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_set("router.bgp.redistribute.connected $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") connected("Connected routes") route-map("Route map reference") <string>("Pointer to route-map entries") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_set("router.bgp.redistribute.connected $route_map $metric"), ADMIN;


no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") connected("Connected routes"),  cli_del("router.bgp.redistribute.connected $route_map=(string)\"any\""), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") connected("Connected routes") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_del("router.bgp.redistribute.connected $metric"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") connected("Connected routes") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_del("router.bgp.redistribute.connected $metric $route_map"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") connected("Connected routes") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_del("router.bgp.redistribute.connected $route_map"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") connected("Connected routes") route-map("Route map reference") <string>("Pointer to route-map entries") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_del("router.bgp.redistribute.connected $route_map $metric"), ADMIN;

/* REDISTRIBUTE KERNEL */

redistribute("Redistribute information from another routing protocol") kernel("Kernel routes"), cli_set("router.bgp.redistribute.kernel $status=(int)1"), ADMIN;
redistribute("Redistribute information from another routing protocol") kernel("Kernel routes") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_set("router.bgp.redistribute.kernel $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") kernel("Kernel routes") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_set("router.bgp.redistribute.kernel $metric $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") kernel("Kernel routes") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_set("router.bgp.redistribute.kernel $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") kernel("Kernel routes") route-map("Route map reference") <string>("Pointer to route-map entries") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_set("router.bgp.redistribute.kernel $route_map $metric"), ADMIN;


no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") kernel("Kernel routes"),  cli_del("router.bgp.redistribute.kernel $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") kernel("Kernel routes") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_del("router.bgp.redistribute.kernel $metric"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") kernel("Kernel routes") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_del("router.bgp.redistribute.kernel $metric $route_map"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") kernel("Kernel routes") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_del("router.bgp.redistribute.kernel $route_map"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") kernel("Kernel routes") route-map("Route map reference") <string>("Pointer to route-map entries") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_del("router.bgp.redistribute.kernel $route_map $metric"), ADMIN;


/* REDISTRIBUTE OSPF */
redistribute("Redistribute information from another routing protocol") ospf("Open Shurtest Path First (OSPF)"), cli_set("router.bgp.redistribute.ospf $status=(int)1"), ADMIN;
redistribute("Redistribute information from another routing protocol") ospf("Open Shurtest Path First (OSPF)") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_set("router.bgp.redistribute.ospf $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") ospf("Open Shurtest Path First (OSPF)") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_set("router.bgp.redistribute.ospf $metric $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") ospf("Open Shurtest Path First (OSPF)") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_set("router.bgp.redistribute.ospf $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") ospf("Open Shurtest Path First (OSPF)") route-map("Route map reference") <string>("Pointer to route-map entries") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_set("router.bgp.redistribute.ospf $route_map $metric"), ADMIN;


no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") ospf("Open Shurtest Path First (OSPF)"),  cli_del("router.bgp.redistribute.ospf"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") ospf("Open Shurtest Path First (OSPF)") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_del("router.bgp.redistribute.ospf $metric"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") ospf("Open Shurtest Path First (OSPF)") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_del("router.bgp.redistribute.ospf $metric $route_map"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") ospf("Open Shurtest Path First (OSPF)") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_del("router.bgp.redistribute.ospf $route_map"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") ospf("Open Shurtest Path First (OSPF)") route-map("Route map reference") <string>("Pointer to route-map entries") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_del("router.bgp.redistribute.ospf $route_map $metric"), ADMIN;


/* REDISTRIBUTE RIP */
redistribute("Redistribute information from another routing protocol") rip("Routing Information Protocol (RIP)"), cli_set("router.bgp.redistribute.rip $status=(int)1"), ADMIN;
redistribute("Redistribute information from another routing protocol") rip("Routing Information Protocol (RIP)") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_set("router.bgp.redistribute.rip $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") rip("Routing Information Protocol (RIP)") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_set("router.bgp.redistribute.rip $metric $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") rip("Routing Information Protocol (RIP)") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_set("router.bgp.redistribute.rip $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") rip("Routing Information Protocol (RIP)") route-map("Route map reference") <string>("Pointer to route-map entries") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_set("router.bgp.redistribute.rip $route_map $metric"), ADMIN;
    
    
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") rip("Routing Information Protocol (RIP)"),  cli_del("router.bgp.redistribute.rip"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") rip("Routing Information Protocol (RIP)") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_del("router.bgp.redistribute.rip $metric"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") rip("Routing Information Protocol (RIP)") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_del("router.bgp.redistribute.rip $metric $route_map"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") rip("Routing Information Protocol (RIP)") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_del("router.bgp.redistribute.rip $route_map"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") rip("Routing Information Protocol (RIP)") route-map("Route map reference") <string>("Pointer to route-map entries") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_del("router.bgp.redistribute.rip $route_map $metric"), ADMIN;
    
    
/* REDISTRIBUTE STATIC */
redistribute("Redistribute information from another routing protocol") static("Static routes"), cli_set("router.bgp.redistribute.static $status=(int)1"), ADMIN;
redistribute("Redistribute information from another routing protocol") static("Static routes") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_set("router.bgp.redistribute.static $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") static("Static routes") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_set("router.bgp.redistribute.static $metric $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") static("Static routes") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_set("router.bgp.redistribute.static $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") static("Static routes") route-map("Route map reference") <string>("Pointer to route-map entries") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_set("router.bgp.redistribute.static $route_map $metric"), ADMIN;
    
    
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") static("Static routes"),  cli_del("router.bgp.redistribute.static $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") static("Static routes") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_del("router.bgp.redistribute.static $metric"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") static("Static routes") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_del("router.bgp.redistribute.static $metric $route_map"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") static("Static routes") route-map("Route map reference") <string>("Pointer to route-map entries"), cli_del("router.bgp.redistribute.static $route_map"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") static("Static routes") route-map("Route map reference") <string>("Pointer to route-map entries") metric("Metric for redistributed routes") <uint32 range[0:4294967295]>("Default metric"), cli_del("router.bgp.redistribute.static $route_map $metric"), ADMIN;
