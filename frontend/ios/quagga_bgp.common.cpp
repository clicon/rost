/*
 * CVS Version: $Id: quagga_bgp.common.cpp,v 1.6 2011/10/30 05:46:42 benny Exp $
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

/* SHOW */
show("Show running system information") {

    /* SHOW BGP */
    bgp("BGP information"), cli_bgp_exec("show bgp"), SHOW; {
  
	/* SHOW BGP IPv4 */
	ipv4("Address family") {
	
	    /* SHOW BGP IPv4 UNICAST STATISTICS */
	    unicast("Address Family modifier") statistics("BGP RIB advertisement statistics"), cli_bgp_exec("show bgp ipv4 unicast statistics"), SHOW;
	    /* SHOW BGP IPv4 MULTICAST STATISTICS */
	    multicast("Address Family modifier") statistics("BGP RIB advertisement statistics"), cli_bgp_exec("show bgp ipv4 multicast statistics"), SHOW;
	} /* SHOW BGP IPv4 */

	/* SHOW BGP MEMORY */
	memory("Global BGP memory statistics"), cli_bgp_exec("show bgp memory"), SHOW;

	/* SHOW BGP NEIGHBORS */
	neighbors("Detailed information on TCP and BGP neighbor connections"), cli_bgp_exec("show bgp neighbors"), SHOW; {

	    /* SHOW BGP NEIGHBORS <ipv4addr> */
	    <ipv4addr>("Neighbor to display information about"), cli_bgp_exec("show bgp neighbors %a"), SHOW; {
		advertised-routes("Display the routes advertised to a BGP neighbor"), cli_bgp_exec("show bgp neighbors %a advertised-routes"), SHOW;
		dampened-routes("Display the dampened routes received from neighbor"), cli_bgp_exec("show bgp neighbors %a dampened-routes"), SHOW;
		flap-statistics("Display flap statistics of the routes learned from neighbor"), cli_bgp_exec("show bgp neighbors %a flap-statistics"), SHOW;
		received("Display information received from a BGP neighbor") prefix-filter("Display the prefixlist filter"), cli_bgp_exec("show bgp neighbors %a received received prefix-filter"), SHOW;
		received-routes("Display the received routes from neighbor"), cli_bgp_exec("show bgp neighbors %a received-routes"), SHOW;
		routes("Display routes learned from neighbor"), cli_bgp_exec("show bgp neighbors %a routes"), SHOW;
	    } /* SHOW BGP NEIGHBORS <ipv4addr> */

	} /* SHOW BGP NEIGHBORS */
    
	/* SHOW BGP REGEXP */
	regexp("Display routes matching the AS path regular expression") <rest>("A regular-expression to match the BGP AS paths"), cli_bgp_exec("show bgp regexp %r"), SHOW;

	/* SHOW BGP ROUTE-MAP */
	route-map("Display routes matching the route-map") <string>("A route-map to match on"), cli_bgp_exec("show bgp route-map %s"), SHOW;
    
    
	/* SHOW BGP SUMMARY */
	summary("Summary of BGP neighbor status"), cli_bgp_exec("show bgp summary"), SHOW;

    } /* SHOW BGP */
    
    /* SHOW IP */
    ip("IP information") {

	/* SHOW IP AS-PATH-ACCESS-LIST */
	as-path-access-list("List AS path access lists"), cli_bgp_exec("show ip as-path-access-list"), SHOW;
	as-path-access-list("List AS path access lists") <string>("AS path access list name"), cli_bgp_exec("show ip as-path-access-list %s"), SHOW;


	/* SHOW IP BGP */
	bgp("BGP information"), cli_bgp_exec("show ip bgp"), SHOW; {


	    /* SHOW IP BGP <ipv4prefix> */
	    <ipv4prefix>("IP prefix <network>/<length>,  e.g.,  35.0.0.0/8"), cli_bgp_exec("show ip bgp %p"), SHOW;

	    /* SHOW IP BGP ATTRIBUTE-INFO */
	    attribute-info("List all bgp attribute information"), cli_bgp_exec("show ip bgp attribute-info"), SHOW;

	    /* SHOW IP BGP CIDR-ONLY */
	    cidr-only("Display only routes with non-natural netmasks"), cli_bgp_exec("show ip bgp cidr-only"), SHOW;

	    /* SHOW IP BGP DAMPENED-PATHS */
	    dampened-paths("Display paths suppressed due to dampening"), cli_bgp_exec("show ip bgp dampened-paths"), SHOW;


	    /* SHOW IP BGP FLAP-STATISTICS */
	    flap-statistics("Display flap statistics of routes"), cli_bgp_exec("show ip bgp flap-statistics"), SHOW; {
		<ipv4prefix>("IP prefix <network>/<length,  e.g.,  35.0.0.0/8"), cli_bgp_exec("show ip bgp flap-statistics %p"), SHOW;
		<ipv4prefix>("IP prefix <network>/<length,  e.g.,  35.0.0.0/8") longer-prefixes("Display route and more specific routes"), cli_bgp_exec("show ip bgp flap-statistics %p longer-prefixes"), SHOW;
		prefix-list("Display routes conforming to the prefix-list") <string>("IP prefix-list name"), cli_bgp_exec("show ip bgp flap-statistics prefix-list %s"), SHOW;
		regexp("Display routes matching the AS path regular expression") <rest>("A regular-expression to match the BGP AS paths"), cli_bgp_exec("show ip bgp flap-statistics regexp %r"), SHOW;
		route-map("Display routes matching the route-map") <string>("A route-map to match on"), cli_bgp_exec("show ip bgp flap-statistics route-map %s"), SHOW;
	    } /* SHOW IP BGP FLAP-STATISTICS */

	    /* SHOW IP BGP IPV4 */
	    ipv4("Address family") {
		unicast("Address Family modifier") statistics("BGP RIB advertisement statistics"), cli_bgp_exec("show bgp ipv4 unicast statistics"), SHOW;
		multicast("Address Family modifier") statistics("BGP RIB advertisement statistics"), cli_bgp_exec("show bgp ipv4 multicast statistics"), SHOW;
	    } /* SHOW IP BGP IPV4 */

	    /* SHOW IP BGP NEIGHBORS */
	    neighbors("Detailed information on TCP and BGP neighbor connections"), cli_bgp_exec("show ip bgp neighbors"), SHOW; {

		/* SHOW IP BGP NEIGHBORS <ipv4addr> */
		<ipv4addr>("Neighbor to display information about"), cli_bgp_exec("show ip bgp neighbors %a"), SHOW; {
		    advertised-routes("Display the routes advertised to a BGP neighbor"), cli_bgp_exec("show ip bgp neighbors %a advertised-routes"), SHOW;
		    dampened-routes("Display the dampened routes received from neighbor"), cli_bgp_exec("show ip bgp neighbors %a dampened-routes"), SHOW;
		    flap-statistics("Display flap statistics of the routes learned from neighbor"), cli_bgp_exec("show ip bgp neighbors %a flap-statistics"), SHOW;
		    prefix-counts("Display detailed prefix count information"), cli_bgp_exec("show ip bgp neighbors %a prefix-counts"), SHOW;
		    received-routes("Display the received routes from neighbor"), cli_bgp_exec("show ip bgp neighbors %a received-routes"), SHOW;
		    routes("Display routes learned from neighbor"), cli_bgp_exec("show ip bgp neighbors %a routes"), SHOW;
		} /* SHOW IP BGP NEIGHBORS <ipv4addr> */

	    } /* SHOW IP BGP NEIGHBORS */

	    
	    /* SHOW IP BGP PATHS */
	    paths("Path information"), cli_bgp_exec("show ip bgp paths"), SHOW;

	    /* SHOW IP BGP PREFIX-LIST */
	    prefix-list("Display routes conforming to the prefix-list") <string>("IP prefix-list name"), cli_bgp_exec("show ip bgp prefix-list %s"), SHOW;

	    /* SHOW IP BGP REGEXP */
	    regexp("Display routes matching the AS path regular expression") <rest>("A regular-expression to match the BGP AS paths"), cli_bgp_exec("show ip bgp regexp %r"), SHOW;

	    /* SHOW IP BGP ROUTE-MAP */
	    route-map("Display routes matching the route-map") <string>("A route-map to match on"), cli_bgp_exec("show ip bgp route-map %s"), SHOW;

	    /* SHOW IP BGP SCAN */
	    scan("BGP scan status"), cli_bgp_exec("show ip bgp scan"), SHOW;

	    /* SHOW IP BGP SUMMARY */
	    summary("Summary of BGP neighbor status"), cli_bgp_exec("show ip bgp summary"), SHOW;
	} /* SHOW IP BGP */
	
    } /* SHOW IP */
    
} /* SHOW */
