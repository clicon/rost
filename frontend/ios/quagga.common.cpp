/*
 * CVS Version: $Id: quagga.common.cpp,v 1.10 2014/01/10 14:08:25 olof Exp $
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
    
    /* SHOW INTERFACE */
    /* XXX Should probably be in "system" instead, but it uses quagga outpot partly */
    interfaces("Interface status and configuration") {
        [<brief:string  keyword:brief>("Summary status for each interface")], cli_show_interfaces(), SHOW;
        <interface expand_interface()>("Interface name"), cli_show_interfaces(), SHOW;
        <interface expand_interface()>("Interface name") statistics("Show interface statistics"), cli_show_iface_stats(), SHOW;
        counters("Show interface counters"), cli_run("netstat -i"), SHOW;
    }

    /* SHOW DEBUGGING ZEBRA */
    debugging("State of each debugging option") zebra("Zebra information"), cli_zebra_exec("show debugging zebra"), ADMIN;

    /* SHOW IP */
    ip("IP information") {

        /* SHOW IP FORWARDING */
        forwarding("IP forwarding status"), cli_zebra_exec("show ip forwarding"), SHOW;

        /* SHOW IP ROUTE */
        route("Routing table"), cli_zebra_exec("show ip route"), SHOW; {
            <ipv4prefix>("IP prefix"), cli_zebra_exec("show ip route %p"), SHOW;
            <ipv4prefix>("IP prefix") longer-prefixes("Show matching routes with equal of longer prefix"), cli_zebra_exec("show ip route %p longer-prefixes"), SHOW;
            kernel("Show kernel routes"), cli_zebra_exec("show ip route kernel"), SHOW;
            connected("Show connected routes"),  cli_zebra_exec("show ip route connected"), SHOW;
            static("Show static routes"),  cli_zebra_exec("show ip route static"), SHOW;
            rip("Show RIP routes"),  cli_zebra_exec("show ip route rip"), SHOW;
            ospf("Show ospf routes"), cli_zebra_exec("show ip route ospf"), SHOW;
            bgp("Show BGP routes"), cli_zebra_exec("show ip route bgp"), SHOW;
        }
        
        /* SHOW IP PREFIX-LIST */
        prefix-list("List IP prefix lists"), cli_zebra_exec("show ip prefix-list"), SHOW; {
            detail("Detail of prefix lists"), cli_zebra_exec("show ip prefix-list detail"), SHOW;
	    detail("Detail of prefix lists") <string>("Name of prefix list"), cli_zebra_exec("show ip prefix-list detail %s"), SHOW;
            summary("Summary of prefix lists"), cli_zebra_exec("show ip prefix-list summary"), SHOW;
	    summary("Summary of prefix lists") <string>("Name of prefix list"), cli_zebra_exec("show ip prefix-list summary %s"), SHOW;
            <string>("Name of a prefix list"), cli_zebra_exec("show ip prefix-list %s"), SHOW;
	    <string>("Name of a prefix list") <ipv4prefix>("IP prefix <network>/<length>,  e.g.,  35.0.0.0/8"), cli_zebra_exec("show ip prefix-list %s %p"), SHOW;
	    <string>("Name of a prefix list") <ipv4prefix>("IP prefix <network>/<length>,  e.g.,  35.0.0.0/8") first-match("First matched prefix"), cli_zebra_exec("show ip prefix-list %s %p first-match"), SHOW; 
	    <string>("Name of a prefix list") <ipv4prefix>("IP prefix <network>/<length>,  e.g.,  35.0.0.0/8") longer("Lookup longer prefix"), cli_zebra_exec("show ip prefix-list %s %p longer"), SHOW;
            seq("sequence number of an entry") <uint32 range[1:4294967295]>("Sequence number"), cli_zebra_exec("show ip prefix-list %s seq %n"), SHOW;
        } /* SHOW IP PREFIX-LIST */
        
        /* SHOW IP ACCESS-LIST */
        access-list("List IP access lists"), cli_zebra_exec("show ip access-list"), SHOW; {
	    (<number range[1:99]>("IP standard access list")|<number range[1300:1999]>("IP standard access list (expanded range)")), cli_zebra_exec("show ip access-list %n"), SHOW;
            (<number range[100:199]>("IP extended access list")|<number range[2000:2699]>("IP extended access list (expanded range)")), cli_zebra_exec("show ip access-list %n"), SHOW;
            <string>("IP zebra access-list"), cli_zebra_exec("show ip access-list %s"), SHOW;
        } /* SHOW IP ACCESS-LIST */
	
    } /* SHOW IP */

} /* SHOW */
