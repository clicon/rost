/*
 * CVS Version: $Id: quagga_rip.router_rip.cpp,v 1.11 2014/01/10 14:08:26 olof Exp $
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
CLICON_MODE=STRINGIFY(IOS_RIP);


    /* DEFAULT-INFORMATION ORIGINATE */
 default-information("Control distribution of default route") originate("Distribute a default route"), cli_set("router.rip.default-information $status=(int)1"), ADMIN;
no("Negate a command or set its defaults") default-information("Control distribution of default route") originate("Distribute a default route"), cli_del("router.rip.default-information $status=(int)1"), ADMIN;

    /* DEFAULT-METRIC */
default-metric("Set a metric of redistribute routes") <number range[1:16]>("Default metric"), cli_set("router.rip.default-metric $metric"), ADMIN;
no("Negate a command or set its defaults") default-metric("Set a metric of redistribute routes"), cli_del("router.rip.default-metric $metric"), ADMIN;
no("Negate a command or set its defaults") default-metric("Set a metric of redistribute routes") <number range[1:16]>("Default metric"), cli_del("router.rip.default-metric $metric"), ADMIN;

    /* DISTANCE */
distance("Administrative distance") <number range[1:255]>("Distance value"), cli_set("router.rip.distance $distance"), ADMIN;
no("Negate a command or set its defaults") distance("Administrative distance") <number range[1:255]>("Distance value"), cli_del("router.rip.distance $distance"), ADMIN;

distance("Administrative distance") <number range[1:255]>("Distance value") <ipv4prefix>("IP source prefix"), cli_set("router.rip.distance.prefix[] $distance $!prefix"), ADMIN;
distance("Administrative distance") <number range[1:255]>("Distance value") <ipv4prefix>("IP source prefix") <string>("Access list name"), cli_set("router.rip.distance.prefix[] $distance $!prefix $acl"), ADMIN;

no("Negate a command or set its defaults") distance("Administrative distance") <number range[1:255]>("Distance value") <ipv4prefix>("IP source prefix"), cli_del("router.rip.distance.prefix[] $distance $!prefix"), ADMIN;
no("Negate a command or set its defaults") distance("Administrative distance") <number range[1:255]>("Distance value") <ipv4prefix>("IP source prefix") <string>("Access list name"), cli_del("router.rip.distance.prefix[] $distance $!prefix $acl"), ADMIN;

    /* DISTRIBUTE-LIST ACL IN */
distribute-list("Filter networks in routing updates") <string expand_acl()>("Access-list name") in("Filter incoming routing updates"), cli_set("router.rip.distribute-list[] $acl $!direction=(string)\"in\" $!interface=(string)\"\"\n"), ADMIN;
distribute-list("Filter networks in routing updates") <string>("Access-list name") in("Filter incoming routing updates"), cli_set("router.rip.distribute-list[] $acl $!direction=(string)\"in\" $!interface=(string)\"\"\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") <string expand_acl()>("Access-list name") in("Filter incoming routing updates"), cli_del("router.rip.distribute-list[] $acl $!direction=(string)\"in\" $!interface=(string)\"\"\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") <string>("Access-list name") in("Filter incoming routing updates"), cli_del("router.rip.distribute-list[] $acl $!direction=(string)\"in\" $!interface=(string)\"\"\n"), ADMIN;

    /* DISTRIBUTE-LIST ACL OUT */
distribute-list("Filter networks in routing updates") <string expand_acl()>("Access-list name") out("Filter outgoing routing updates"), cli_set("router.rip.distribute-list[] $acl $!direction=(string)\"out\" $!interface=(string)\"\"\n"), ADMIN;
distribute-list("Filter networks in routing updates") <string>("Access-list name") out("Filter outgoing routing updates"), cli_set("router.rip.distribute-list[] $acl $!direction=(string)\"out\" $!interface=(string)\"\"\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") <string expand_acl()>("Access-list name") out("Filter outgoing routing updates"), cli_del("router.rip.distribute-list[] $acl $!direction=(string)\"out\" $!interface=(string)\"\"\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") <string>("Access-list name") out("Filter outgoing routing updates"), cli_del("router.rip.distribute-list[] $acl $!direction=(string)\"out\" $!interface=(string)\"\"\n"), ADMIN;

    /* DISTRIBUTE-LIST ACL IN INTERFACE */
distribute-list("Filter networks in routing updates") <string expand_acl()>("Access-list name") in("Filter incoming routing updates") <interface expand_interface()>("Interface name"), cli_set("router.rip.distribute-list[] $acl $!direction=(string)\"in\" $!interface\n"), ADMIN;
distribute-list("Filter networks in routing updates") <string expand_acl()>("Access-list name") in("Filter incoming routing updates") <interface>("Interface name"), cli_set("router.rip.distribute-list[] $acl $!direction=(string)\"in\" $!interface\n"), ADMIN;
distribute-list("Filter networks in routing updates") <string>("Access-list name") in("Filter incoming routing updates") <interface expand_interface()>("Interface name"), cli_set("router.rip.distribute-list[] $acl $!direction=(string)\"in\" $!interface\n"), ADMIN;
distribute-list("Filter networks in routing updates") <string>("Access-list name") in("Filter incoming routing updates") <interface>("Interface name"), cli_set("router.rip.distribute-list[] $acl $!direction=(string)\"in\" $!interface\n"), ADMIN;

no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") <string expand_acl()>("Access-list name") in("Filter incoming routing updates") <interface expand_interface()>("Interface name"), cli_del("router.rip.distribute-list[] $acl $!direction=(string)\"in\" $!interface\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") <string expand_acl()>("Access-list name") in("Filter incoming routing updates") <interface>("Interface name"), cli_del("router.rip.distribute-list[] $acl $!direction=(string)\"in\" $!interface\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") <string>("Access-list name") in("Filter incoming routing updates") <interface expand_interface()>("Interface name"), cli_del("router.rip.distribute-list[] $acl $!direction=(string)\"in\" $!interface\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") <string>("Access-list name") in("Filter incoming routing updates") <interface>("Interface name"), cli_del("router.rip.distribute-list[] $acl $!direction=(string)\"in\" $!interface\n"), ADMIN;

    /* DISTRIBUTE-LIST ACL OUT INTERFACE */
distribute-list("Filter networks in routing updates") <string expand_acl()>("Access-list name") out("Filter outgoing routing updates") <interface expand_interface()>("Interface name"), cli_set("router.rip.distribute-list[] $acl $!direction=(string)\"out\" $!interface\n"), ADMIN;
distribute-list("Filter networks in routing updates") <string expand_acl()>("Access-list name") out("Filter outgoing routing updates") <interface>("Interface name"), cli_set("router.rip.distribute-list[] $acl $!direction=(string)\"out\" $!interface\n"), ADMIN;
distribute-list("Filter networks in routing updates") <string>("Access-list name") out("Filter outgoing routing updates") <interface expand_interface()>("Interface name"), cli_set("router.rip.distribute-list[] $acl $!direction=(string)\"out\" $!interface\n"), ADMIN;
distribute-list("Filter networks in routing updates") <string>("Access-list name") out("Filter outgoing routing updates") <interface>("Interface name"), cli_set("router.rip.distribute-list[] $acl $!direction=(string)\"out\" $!interface\n"), ADMIN;

no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") <string expand_acl()>("Access-list name") out("Filter outgoing routing updates") <interface expand_interface()>("Interface name"), cli_del("router.rip.distribute-list[] $acl $!direction=(string)\"out\" $!interface\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") <string expand_acl()>("Access-list name") out("Filter outgoing routing updates") <interface>("Interface name"), cli_del("router.rip.distribute-list[] $acl $!direction=(string)\"out\" $!interface\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") <string>("Access-list name") out("Filter outgoing routing updates") <interface expand_interface()>("Interface name"), cli_del("router.rip.distribute-list[] $acl $!direction=(string)\"out\" $!interface\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") <string>("Access-list name") out("Filter outgoing routing updates") <interface>("Interface name"), cli_del("router.rip.distribute-list[] $acl $!direction=(string)\"out\" $!interface\n"), ADMIN;

    /* DISTRIBUTE-LIST PREFIX IN */
distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string expand_prefixlist()>("Name of an IP prefix-list") in("Filter incoming routing updates"), cli_set("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"in\" $!interface=(string)\"\"\n"), ADMIN;
distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string>("Name of an IP prefix-list") in("Filter incoming routing updates"), cli_set("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"in\" $!interface=(string)\"\"\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string expand_prefixlist()>("Name of an IP prefix-list") in("Filter incoming routing updates"), cli_del("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"in\" $!interface=(string)\"\"\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string>("Name of an IP prefix-list") in("Filter incoming routing updates"), cli_del("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"in\" $!interface=(string)\"\"\n"), ADMIN;

    /* DISTRIBUTE-LIST PREFIX OUT */
distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string expand_prefixlist()>("Name of an IP prefix-list") out("Filter outgoing routing updates"), cli_set("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"out\" $!interface=(string)\"\"\n"), ADMIN;
distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string>("Name of an IP prefix-list") out("Filter outgoing routing updates"), cli_set("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"out\" $!interface=(string)\"\"\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string expand_prefixlist()>("Name of an IP prefix-list") out("Filter outgoing routing updates"), cli_del("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"out\" $!interface=(string)\"\"\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string>("Name of an IP prefix-list") out("Filter outgoing routing updates"), cli_del("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"out\" $!interface=(string)\"\"\n"), ADMIN;

    /* DISTRIBUTE-LIST PREFIX IN INTERFACE */
distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string expand_prefixlist()>("Name of an IP prefix-list") in("Filter incoming routing updates") <interface expand_interface()>("Interface name"), cli_set("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"in\" $!interface\n"), ADMIN;
distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string expand_prefixlist()>("Name of an IP prefix-list") in("Filter incoming routing updates") <interface>("Interface name"), cli_set("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"in\" $!interface\n"), ADMIN;
distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string>("Name of an IP prefix-list") in("Filter incoming routing updates") <interface expand_interface()>("Interface name"), cli_set("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"in\" $!interface\n"), ADMIN;
distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string>("Name of an IP prefix-list") in("Filter incoming routing updates") <interface>("Interface name"), cli_set("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"in\" $!interface\n"), ADMIN;

no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string expand_prefixlist()>("Name of an IP prefix-list") in("Filter incoming routing updates") <interface expand_interface()>("Interface name"), cli_del("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"in\" $!interface\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string expand_prefixlist()>("Name of an IP prefix-list") in("Filter incoming routing updates") <interface>("Interface name"), cli_del("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"in\" $!interface\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string>("Name of an IP prefix-list") in("Filter incoming routing updates") <interface expand_interface()>("Interface name"), cli_del("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"in\" $!interface\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string>("Name of an IP prefix-list") in("Filter incoming routing updates") <interface>("Interface name"), cli_del("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"in\" $!interface\n"), ADMIN;

    /* DISTRIBUTE-LIST PREFIX OUT INTERFACE */
distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string expand_prefixlist()>("Name of an IP prefix-list") out("Filter outgoing routing updates") <interface expand_interface()>("Interface name"), cli_set("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"out\" $!interface\n"), ADMIN;
distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string expand_prefixlist()>("Name of an IP prefix-list") out("Filter outgoing routing updates") <interface>("Interface name"), cli_set("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"out\" $!interface\n"), ADMIN;
distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string>("Name of an IP prefix-list") out("Filter outgoing routing updates") <interface expand_interface()>("Interface name"), cli_set("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"out\" $!interface\n"), ADMIN;
distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string>("Name of an IP prefix-list") out("Filter outgoing routing updates") <interface>("Interface name"), cli_set("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"out\" $!interface\n"), ADMIN;

no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string expand_prefixlist()>("Name of an IP prefix-list") out("Filter outgoing routing updates") <interface expand_interface()>("Interface name"), cli_del("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"out\" $!interface\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string expand_prefixlist()>("Name of an IP prefix-list") out("Filter outgoing routing updates") <interface>("Interface name"), cli_del("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"out\" $!interface\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string>("Name of an IP prefix-list") out("Filter outgoing routing updates") <interface expand_interface()>("Interface name"), cli_del("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"out\" $!interface\n"), ADMIN;
no("Negate a command or set its defaults") distribute-list("Filter networks in routing updates") prefix("Filter prefixes in routing updates") <string>("Name of an IP prefix-list") out("Filter outgoing routing updates") <interface>("Interface name"), cli_del("router.rip.distribute-list.prefix[] $prefix $!direction=(string)\"out\" $!interface\n"), ADMIN;


    /* NEIGHBOR */
neighbor("Specify a neighbor router") <ipv4addr>("Neighbor address"), cli_set("router.rip.neighbor[] $!neighbor"), ADMIN;
no("Negate a command or set its defaults") neighbor("Specify a neighbor router") <ipv4addr>("Neighbor address"), cli_del("router.rip.neighbor[] $!neighbor"), ADMIN;

    /* NETWORK */
network("Enable routing on an IP network") <ipv4prefix>("IP prefix <network>/<length>,  e.g.,  35.0.0.0/8"), cli_set("router.rip.network.prefix[] $!prefix"), ADMIN;
network("Enable routing on an IP network") <interface expand_interface()>("Interface name"), cli_set("router.rip.network.interface[] $!interface"), ADMIN;

no("Negate a command or set its defaults") network("Enable routing on an IP network") <ipv4prefix>("IP prefix <network>/<length>,  e.g.,  35.0.0.0/8"), cli_del("router.rip.network.prefix[] $!prefix"), ADMIN;
no("Negate a command or set its defaults") network("Enable routing on an IP network") <interface expand_interface()>("Interface name"), cli_del("router.rip.network.interface[] $!interface"), ADMIN;

    /* OFFSET-LIST */
offset-list("Modify RIP metric") <string expand_acl()>("Access-list name") in("For incoming updates") <number range[0:16]>("Metric value"), cli_set("router.rip.offset-list[] $acl $!direction=(string)\"in\" $metric $!interface=(string)\"\""), ADMIN;
offset-list("Modify RIP metric") <string>("Access-list name") in("For incoming updates") <number range[0:16]>("Metric value"), cli_set("router.rip.offset-list[] $acl $!direction=(string)\"in\" $metric $!interface=(string)\"\""), ADMIN;

offset-list("Modify RIP metric") <string expand_acl()>("Access-list name") in("For incoming updates") <number range[0:16]>("Metric value") <interface expand_interface()>("Interface name"), cli_set("router.rip.offset-list[] $acl $!direction=(string)\"in\" $metric $!interface"), ADMIN;
offset-list("Modify RIP metric") <string>("Access-list name") in("For incoming updates") <number range[0:16]>("Metric value") <interface expand_interface()>("Interface name"), cli_set("router.rip.offset-list[] $acl $!direction=(string)\"in\" $metric $!interface"), ADMIN;
offset-list("Modify RIP metric") <string expand_acl()>("Access-list name") in("For incoming updates") <number range[0:16]>("Metric value") <interface>("Interface name"), cli_set("router.rip.offset-list[] $acl $!direction=(string)\"in\" $metric $!interface"), ADMIN;
offset-list("Modify RIP metric") <string>("Access-list name") in("For incoming updates") <number range[0:16]>("Metric value") <interface>("Interface name"), cli_set("router.rip.offset-list[] $acl $!direction=(string)\"in\" $metric $!interface"), ADMIN;

offset-list("Modify RIP metric") <string expand_acl()>("Access-list name") out("For outgoing updates") <number range[0:16]>, cli_set("router.rip.offset-list[] $acl $!direction=(string)\"out\" $metric $!interface=(string)\"\""), ADMIN;
offset-list("Modify RIP metric") <string>("Access-list name") out("For outgoing updates") <number range[0:16]>, cli_set("router.rip.offset-list[] $acl $!direction=(string)\"out\" $metric $!interface=(string)\"\""), ADMIN;

offset-list("Modify RIP metric") <string expand_acl()>("Access-list name") out("For outgoing updates") <number range[0:16]>("Metric value") <interface expand_interface()>("Interface name"), cli_set("router.rip.offset-list[] $acl $!direction=(string)\"out\" $metric $!interface"), ADMIN;
offset-list("Modify RIP metric") <string>("Access-list name") out("For outgoing updates") <number range[0:16]>("Metric value") <interface expand_interface()>("Interface name"), cli_set("router.rip.offset-list[] $acl $!direction=(string)\"out\" $metric $!interface"), ADMIN;
offset-list("Modify RIP metric") <string expand_acl()>("Access-list name") out("For outgoing updates") <number range[0:16]>("Metric value") <interface>("Interface name"), cli_set("router.rip.offset-list[] $acl $!direction=(string)\"out\" $metric $!interface"), ADMIN;
offset-list("Modify RIP metric") <string>("Access-list name") out("For outgoing updates") <number range[0:16]>("Metric value") <interface>("Interface name"), cli_set("router.rip.offset-list[] $acl $!direction=(string)\"out\" $metric $!interface"), ADMIN;

no("Negate a command or set its defaults") offset-list("Modify RIP metric") <string expand_acl()>("Access-list name") in("For incoming updates") <number range[0:16]>, cli_del("router.rip.offset-list[] $acl $!direction=(string)\"in\" $metric $!interface=(string)\"\""), ADMIN;
no("Negate a command or set its defaults") offset-list("Modify RIP metric") <string>("Access-list name") in("For incoming updates") <number range[0:16]>, cli_del("router.rip.offset-list[] $acl $!direction=(string)\"in\" $metric $!interface=(string)\"\""), ADMIN;

no("Negate a command or set its defaults") offset-list("Modify RIP metric") <string expand_acl()>("Access-list name") in("For incoming updates") <number range[0:16]>("Metric value") <interface expand_interface()>("Interface name"), cli_del("router.rip.offset-list[] $acl $!direction=(string)\"in\" $metric $!interface"), ADMIN;
no("Negate a command or set its defaults") offset-list("Modify RIP metric") <string>("Access-list name") in("For incoming updates") <number range[0:16]>("Metric value") <interface expand_interface()>("Interface name"), cli_del("router.rip.offset-list[] $acl $!direction=(string)\"in\" $metric $!interface"), ADMIN;
no("Negate a command or set its defaults") offset-list("Modify RIP metric") <string expand_acl()>("Access-list name") in("For incoming updates") <number range[0:16]>("Metric value") <interface>("Interface name"), cli_del("router.rip.offset-list[] $acl $!direction=(string)\"in\" $metric $!interface"), ADMIN;
no("Negate a command or set its defaults") offset-list("Modify RIP metric") <string>("Access-list name") in("For incoming updates") <number range[0:16]>("Metric value") <interface>("Interface name"), cli_del("router.rip.offset-list[] $acl $!direction=(string)\"in\" $metric $!interface"), ADMIN;

no("Negate a command or set its defaults") offset-list("Modify RIP metric") <string expand_acl()>("Access-list name") out("For outgoing updates") <number range[0:16]>, cli_del("router.rip.offset-list[] $acl $!direction=(string)\"out\" $metric $!interface=(string)\"\""), ADMIN;
no("Negate a command or set its defaults") offset-list("Modify RIP metric") <string>("Access-list name") out("For outgoing updates") <number range[0:16]>, cli_del("router.rip.offset-list[] $acl $!direction=(string)\"out\" $metric $!interface=(string)\"\""), ADMIN;

no("Negate a command or set its defaults") offset-list("Modify RIP metric") <string expand_acl()>("Access-list name") out("For outgoing updates") <number range[0:16]>("Metric value") <interface expand_interface()>("Interface name"), cli_del("router.rip.offset-list[] $acl $!direction=(string)\"out\" $metric $!interface"), ADMIN;
no("Negate a command or set its defaults") offset-list("Modify RIP metric") <string>("Access-list name") out("For outgoing updates") <number range[0:16]>("Metric value") <interface expand_interface()>("Interface name"), cli_del("router.rip.offset-list[] $acl $!direction=(string)\"out\" $metric $!interface"), ADMIN;
no("Negate a command or set its defaults") offset-list("Modify RIP metric") <string expand_acl()>("Access-list name") out("For outgoing updates") <number range[0:16]>("Metric value") <interface>("Interface name"), cli_del("router.rip.offset-list[] $acl $!direction=(string)\"out\" $metric $!interface"), ADMIN;
no("Negate a command or set its defaults") offset-list("Modify RIP metric") <string>("Access-list name") out("For outgoing updates") <number range[0:16]>("Metric value") <interface>("Interface name"), cli_del("router.rip.offset-list[] $acl $!direction=(string)\"out\" $metric $!interface"), ADMIN;

    /* PASSIVE-INTERFACE */
passive-interface("Suppress routing updates on an interface") <interface expand_interface()>("Interface name"), cli_set("router.rip.passive-interface[] $!interface"), ADMIN;
passive-interface("Suppress routing updates on an interface") <interface>("Interface name"), cli_set("router.rip.passive-interface[] $!interface"), ADMIN;
#ifdef notyet
    /* XXX "passive-interface default" need to override all other 
       passive-interface statements */
passive-interface("Suppress routing updates on an interface") default("default for all interfaces"), cli_set("router.rip.passive-interface[] $!interface=(string)\"default\""), ADMIN;
#endif

no("Negate a command or set its defaults") passive-interface("Suppress routing updates on an interface") <interface expand_interface()>("Interface name"), cli_del("router.rip.passive-interface[] $!interface"), ADMIN;
no("Negate a command or set its defaults") passive-interface("Suppress routing updates on an interface") <interface>("Interface name"), cli_del("router.rip.passive-interface[] $!interface"), ADMIN;
#ifdef notyet
no("Negate a command or set its defaults") passive-interface("Suppress routing updates on an interface") default("default for all interfaces"), cli_del("router.rip.passive-interface[] $!interface=(string)\"default\""), ADMIN;
#endif

    /* REDISTRIBUTE BGP */
redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)"), cli_set("router.rip.redistribute[] $!protocol=(string)\"bgp\""), ADMIN;
redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute[] $!protocol=(string)\"bgp\" $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string>("Route map name"), cli_set("router.rip.redistribute[] $!protocol=(string)\"bgp\" $metric $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_set("router.rip.redistribute[] $!protocol=(string)\"bgp\" $metric $route_map"), ADMIN;

redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") route-map("Route map reference") <string>("Route map name"), cli_set("router.rip.redistribute[] $!protocol=(string)\"bgp\" $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_set("router.rip.redistribute[] $!protocol=(string)\"bgp\" $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") route-map("Route map reference") <string>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute[] $!protocol=(string)\"bgp\" $route_map $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") route-map("Route map reference") <string expand_routemap()>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute[] $!protocol=(string)\"bgp\" $route_map $metric"), ADMIN;




no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)"), cli_del("router.rip.redistribute[] $!protocol=(string)\"bgp\""), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute[] $!protocol=(string)\"bgp\""), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string>("Route map name"), cli_del("router.rip.redistribute[] $!protocol=(string)\"bgp\""), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_del("router.rip.redistribute[] $!protocol=(string)\"bgp\""), ADMIN;

no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") route-map("Route map reference") <string>("Route map name"), cli_del("router.rip.redistribute[] $!protocol=(string)\"bgp\""), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_del("router.rip.redistribute[] $!protocol=(string)\"bgp\""), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") route-map("Route map reference") <string>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute[] $!protocol=(string)\"bgp\""), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") bgp("Border Gateway Protocol (BGP)") route-map("Route map reference") <string expand_routemap()>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute[] $!protocol=(string)\"bgp\""), ADMIN;



redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)"), cli_set("router.rip.redistribute.connected $dummy=(int)1"), ADMIN;
redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.connected $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string>("Route map name"), cli_set("router.rip.redistribute.connected $metric $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_set("router.rip.redistribute.connected $metric $route_map"), ADMIN;

redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") route-map("Route map reference") <string>("Route map name"), cli_set("router.rip.redistribute.connected $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_set("router.rip.redistribute.connected $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") route-map("Route map reference") <string>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.connected $route_map $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") route-map("Route map reference") <string expand_routemap()>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.connected $route_map $metric"), ADMIN;




no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)"), cli_del("router.rip.redistribute.connected $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.connected $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string>("Route map name"), cli_del("router.rip.redistribute.connected $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_del("router.rip.redistribute.connected $dummy=(int)1"), ADMIN;

no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") route-map("Route map reference") <string>("Route map name"), cli_del("router.rip.redistribute.connected $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_del("router.rip.redistribute.connected $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") route-map("Route map reference") <string>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.connected $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") connected("Connected routes (directly attached subnet or host)") route-map("Route map reference") <string expand_routemap()>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.connected $dummy=(int)1"), ADMIN;



#ifdef OSR_ISIS_SUPPORT
    /* REDISTRIBUTE ISIS */
redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)"), cli_set("router.rip.redistribute.isis $dummy=(int)1"), ADMIN;
redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.isis $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string>("Route map name"), cli_set("router.rip.redistribute.isis $metric $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_set("router.rip.redistribute.isis $metric $route_map"), ADMIN;

redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") route-map("Route map reference") <string>("Route map name"), cli_set("router.rip.redistribute.isis $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_set("router.rip.redistribute.isis $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") route-map("Route map reference") <string>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.isis $route_map $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") route-map("Route map reference") <string expand_routemap()>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.isis $route_map $metric"), ADMIN;




no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)"), cli_del("router.rip.redistribute.isis $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.isis $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string>("Route map name"), cli_del("router.rip.redistribute.isis $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_del("router.rip.redistribute.isis $dummy=(int)1"), ADMIN;

no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") route-map("Route map reference") <string>("Route map name"), cli_del("router.rip.redistribute.isis $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_del("router.rip.redistribute.isis $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") route-map("Route map reference") <string>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.isis $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") isis("Intermediate System to Intermediate System (IS-IS)") route-map("Route map reference") <string expand_routemap()>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.isis $dummy=(int)1"), ADMIN;


#endif /* OSR_ISIS_SUPPORT */

    /* REDISTRIBUTE KERNEL */
redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)"), cli_set("router.rip.redistribute.kernel $dummy=(int)1"), ADMIN;
redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.kernel $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string>("Route map name"), cli_set("router.rip.redistribute.kernel $metric $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_set("router.rip.redistribute.kernel $metric $route_map"), ADMIN;

redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") route-map("Route map reference") <string>("Route map name"), cli_set("router.rip.redistribute.kernel $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_set("router.rip.redistribute.kernel $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") route-map("Route map reference") <string>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.kernel $route_map $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") route-map("Route map reference") <string expand_routemap()>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.kernel $route_map $metric"), ADMIN;




no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)"), cli_del("router.rip.redistribute.kernel $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.kernel $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string>("Route map name"), cli_del("router.rip.redistribute.kernel $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_del("router.rip.redistribute.kernel $dummy=(int)1"), ADMIN;

no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") route-map("Route map reference") <string>("Route map name"), cli_del("router.rip.redistribute.kernel $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_del("router.rip.redistribute.kernel $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") route-map("Route map reference") <string>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.kernel $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") kernel("Kernel routes (not installed via the zebra RIB)") route-map("Route map reference") <string expand_routemap()>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.kernel $dummy=(int)1"), ADMIN;



    /* REDISTRIBUTE OSPF */
redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)"), cli_set("router.rip.redistribute.ospf $dummy=(int)1"), ADMIN;
redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.ospf $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string>("Route map name"), cli_set("router.rip.redistribute.ospf $metric $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_set("router.rip.redistribute.ospf $metric $route_map"), ADMIN;

redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") route-map("Route map reference") <string>("Route map name"), cli_set("router.rip.redistribute.ospf $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_set("router.rip.redistribute.ospf $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") route-map("Route map reference") <string>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.ospf $route_map $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") route-map("Route map reference") <string expand_routemap()>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.ospf $route_map $metric"), ADMIN;




no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)"), cli_del("router.rip.redistribute.ospf $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.ospf $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string>("Route map name"), cli_del("router.rip.redistribute.ospf $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_del("router.rip.redistribute.ospf $dummy=(int)1"), ADMIN;

no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") route-map("Route map reference") <string>("Route map name"), cli_del("router.rip.redistribute.ospf $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_del("router.rip.redistribute.ospf $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") route-map("Route map reference") <string>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.ospf $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") ospf("Open Shortest Path First (OSPFv2)") route-map("Route map reference") <string expand_routemap()>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.ospf $dummy=(int)1"), ADMIN;



    /* REDISTRIBUTE STATIC */
redistribute("Redistribute information from another routing protocol") static("Statically configured routes"), cli_set("router.rip.redistribute.static $dummy=(int)1"), ADMIN;
redistribute("Redistribute information from another routing protocol") static("Statically configured routes") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.static $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") static("Statically configured routes") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string>("Route map name"), cli_set("router.rip.redistribute.static $metric $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") static("Statically configured routes") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_set("router.rip.redistribute.static $metric $route_map"), ADMIN;

redistribute("Redistribute information from another routing protocol") static("Statically configured routes") route-map("Route map reference") <string>("Route map name"), cli_set("router.rip.redistribute.static $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") static("Statically configured routes") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_set("router.rip.redistribute.static $route_map"), ADMIN;
redistribute("Redistribute information from another routing protocol") static("Statically configured routes") route-map("Route map reference") <string>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.static $route_map $metric"), ADMIN;
redistribute("Redistribute information from another routing protocol") static("Statically configured routes") route-map("Route map reference") <string expand_routemap()>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_set("router.rip.redistribute.static $route_map $metric"), ADMIN;




no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") static("Statically configured routes"), cli_del("router.rip.redistribute.static $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") static("Statically configured routes") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.static $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") static("Statically configured routes") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string>("Route map name"), cli_del("router.rip.redistribute.static $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") static("Statically configured routes") metric("Metric for redistributed routes") <number range[0:16]>("Metric value") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_del("router.rip.redistribute.static $dummy=(int)1"), ADMIN;

no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") static("Statically configured routes") route-map("Route map reference") <string>("Route map name"), cli_del("router.rip.redistribute.static $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") static("Statically configured routes") route-map("Route map reference") <string expand_routemap()>("Route map name"), cli_del("router.rip.redistribute.static $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") static("Statically configured routes") route-map("Route map reference") <string>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.static $dummy=(int)1"), ADMIN;
no("Negate a command or set its defaults") redistribute("Redistribute information from another routing protocol") static("Statically configured routes") route-map("Route map reference") <string expand_routemap()>("Route map name") metric("Metric for redistributed routes") <number range[0:16]>("Metric value"), cli_del("router.rip.redistribute.static $dummy=(int)1"), ADMIN;


    /* ROUTE */
route("RIP static route configuration") <ipv4prefix>("IP prefix <network>/<length>"), cli_set("router.rip.route[] $!prefix"), ADMIN;
no("Negate a command or set its defaults") route("RIP static route configuration") <ipv4prefix>("IP prefix <network>/<length>"), cli_del("router.rip.route[] $!prefix"), ADMIN;

    /* ROUTEMAP */
route-map("Route map set") <string expand_routemap()>("Route map name") in("Route map set for input filtering") <interface expand_interface()>("Interface name"), cli_set("router.rip.route-map[] $route_map $!direction=(string)\"in\" $!interface"), ADMIN;
route-map("Route map set") <string>("Route map name") in("Route map set for input filtering") <interface expand_interface()>("Interface name"), cli_set("router.rip.route-map[] $route_map $!direction=(string)\"in\" $!interface"), ADMIN;
route-map("Route map set") <string expand_routemap()>("Route map name") in("Route map set for input filtering") <interface>("Interface name"), cli_set("router.rip.route-map[] $route_map $!direction=(string)\"in\" $!interface"), ADMIN;
route-map("Route map set") <string>("Route map name") in("Route map set for input filtering") <interface>("Interface name"), cli_set("router.rip.route-map[] $route_map $!direction=(string)\"in\" $!interface"), ADMIN;

no("Negate a command or set its defaults") route-map("Route map set") <string expand_routemap()>("Route map name") in("Route map set for input filtering") <interface expand_interface()>("Interface name"), cli_del("router.rip.route-map[] $route_map $!direction=(string)\"in\" $!interface"), ADMIN;
no("Negate a command or set its defaults") route-map("Route map set") <string>("Route map name") in("Route map set for input filtering") <interface expand_interface()>("Interface name"), cli_del("router.rip.route-map[] $route_map $!direction=(string)\"in\" $!interface"), ADMIN;
no("Negate a command or set its defaults") route-map("Route map set") <string expand_routemap()>("Route map name") in("Route map set for input filtering") <interface>("Interface name"), cli_del("router.rip.route-map[] $route_map $!direction=(string)\"in\" $!interface"), ADMIN;
no("Negate a command or set its defaults") route-map("Route map set") <string>("Route map name") in("Route map set for input filtering") <interface>("Interface name"), cli_del("router.rip.route-map[] $route_map $!direction=(string)\"in\" $!interface"), ADMIN;

route-map("Route map set") <string expand_routemap()>("Route map name") out("Route map set for output filtering") <interface expand_interface()>("Interface name"), cli_set("router.rip.route-map[] $route_map $!direction=(string)\"out\" $!interface"), ADMIN;
route-map("Route map set") <string>("Route map name") out("Route map set for output filtering") <interface expand_interface()>("Interface name"), cli_set("router.rip.route-map[] $route_map $!direction=(string)\"out\" $!interface"), ADMIN;
route-map("Route map set") <string expand_routemap()>("Route map name") out("Route map set for output filtering") <interface>("Interface name"), cli_set("router.rip.route-map[] $route_map $!direction=(string)\"out\" $!interface"), ADMIN;
route-map("Route map set") <string>("Route map name") out("Route map set for output filtering") <interface>("Interface name"), cli_set("router.rip.route-map[] $route_map $!direction=(string)\"out\" $!interface"), ADMIN;

no("Negate a command or set its defaults") route-map("Route map set") <string expand_routemap()>("Route map name") out("Route map set for output filtering") <interface expand_interface()>("Interface name"), cli_del("router.rip.route-map[] $route_map $!direction=(string)\"out\" $!interface"), ADMIN;
no("Negate a command or set its defaults") route-map("Route map set") <string>("Route map name") out("Route map set for output filtering") <interface expand_interface()>("Interface name"), cli_del("router.rip.route-map[] $route_map $!direction=(string)\"out\" $!interface"), ADMIN;
no("Negate a command or set its defaults") route-map("Route map set") <string expand_routemap()>("Route map name") out("Route map set for output filtering") <interface>("Interface name"), cli_del("router.rip.route-map[] $route_map $!direction=(string)\"out\" $!interface"), ADMIN;
no("Negate a command or set its defaults") route-map("Route map set") <string>("Route map name") out("Route map set for output filtering") <interface>("Interface name"), cli_del("router.rip.route-map[] $route_map $!direction=(string)\"out\" $!interface"), ADMIN;

    /* TIMERS BASIC */
timers("Adjust routing timers") basic("Basic routing protocol update timers") <number range[5:2147483647]>("Routing table update timer value in second. Default is 30") <number range[5:2147483647]>("Routing information timeout timer. Default is 180") <number range[5:2147483647]>("Garbage collection timer. Default is 120"), cli_set("router.rip.timers.basic $update $timeout $garbage"), ADMIN;
no("Negate a command or set its defaults") timers("Adjust routing timers") basic("Basic routing protocol update timers"), cli_del("router.rip.timers.basic $dummy=(int)0"), ADMIN;
no("Negate a command or set its defaults") timers("Adjust routing timers") basic("Basic routing protocol update timers") <number range[5:2147483647]>("Routing table update timer value in second. Default is 30") <number range[5:2147483647]>("Routing information timeout timer. Default is 180") <number range[5:2147483647]>("Garbage collection timer. Default is 120"), cli_del("router.rip.timers.basic $dummy=(int)0"), ADMIN;

    /* VERSION */
version("Set routing protocol version") <number range[1:2]>("RIP version"), cli_set("router.rip.version $version"), ADMIN;
no("Negate a command or set its defaults") version("Set routing protocol version"), cli_del("router.rip.version $version=(int)1"), ADMIN;
no("Negate a command or set its defaults") version("Set routing protocol version") <number range[1:2]>("RIP version"), cli_del("router.rip.version $version"), ADMIN;

#ifdef notyet
list("List commands in mode"), cli_ios_list;
#endif

