/*
 * CVS Version: $Id: quagga.config.cpp,v 1.10 2014/01/10 14:08:25 olof Exp $
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
CLICON_MODE=STRINGIFY(IOS_CONFIG);

/* DEBUG */
debug("Debugging functions (see also 'undebug')") {

    /* DEBUG ZEBRA */
    zebra("Debug zebra operation") {
        
        /* DEBUG ZEBRA EVENTS */
        events("Debug option set for zebra events"), cli_zebra_exec("debug zebra events"), ADMIN;
        
        /* DEBUG ZEBRA KERNEL */
        kernel("Debug option set for zebra between kernel interface"), cli_zebra_exec("debug zebra kernel"), ADMIN;

        /* DEBUG ZEBRA PACKETS */
        packets("Debug option set for zebra packets"), cli_zebra_exec("debug zebra packet"), ADMIN;
        packets("Debug option set for zebra packets") {

        /* DEBUG ZEBRA PACKET SEND */
            send("Packets sent"), cli_zebra_exec("debug zebra packet send"), ADMIN;
            send("Packets sent") detail("Detailed information"), cli_zebra_exec("debug zebra packet send detail"), ADMIN;
            
            /* DEBUG ZEBRA PACKET RECV */
            recv("Packets received"), cli_zebra_exec("debug zebra packet recv"), ADMIN;
            recv("Packets received") detail("Detailed information"), cli_zebra_exec("debug zebra packet recv detail"), ADMIN;
        } /* DEBUG ZEBRA PACKETS */

        /* DEBUG ZEBRA RIB */
        rib("Debug RIB events"), cli_zebra_exec("debug zebra rib"), ADMIN;
        rib("Debug RIB events") queue("Debug RIB queueing"), cli_zebra_exec("debug zebra rib queue"), ADMIN;
        
    } /* DEBUG ZEBRA */

} /* DEBUG */

/* UNDEBUG */
undebug("Disable debugging functions (see also 'debug')") {

    /* UNDEBUG ZEBRA */
    zebra("Debug zebra operation") {
        
        /* UNDEBUG ZEBRA EVENTS */
        events("Debug option set for zebra events"), cli_zebra_exec("no debug zebra events"), ADMIN;
        
        /* UNDEBUG ZEBRA KERNEL */
        kernel("Debug option set for zebra between kernel interface"), cli_zebra_exec("no debug zebra kernel"), ADMIN;
        
        /* UNDEBUG ZEBRA PACKETS */
        packets("Debug option set for zebra packets"), cli_zebra_exec("no debug zebra packet"), ADMIN;
        packets("Debug option set for zebra packets") {
            
            /* UNDEBUG ZEBRA PACKET SEND */        
            send("Packets sent"), cli_zebra_exec("no debug zebra packet"), ADMIN
;
            send("Packets sent") detail("Detailed information"), cli_zebra_exec("no debug zebra packet"), ADMIN;

            /* UNDEBUG ZEBRA PACKET RECV */        
            recv("Packets received"), cli_zebra_exec("no debug zebra packet"), ADMIN;
            recv("Packets renceived") detail("Detailed information"), cli_zebra_exec("no debug zebra packet"), ADMIN;

        } /* UNDEBUG ZEBRA PACKETS */

        /* UNDEBUG ZEBRA RIB */
        rib("Debug RIB events"), cli_zebra_exec("no debug zebra rib"), ADMIN;
        rib("Debug RIB events") queue("Debug RIB queueing"), cli_zebra_exec("no debug zebra rib queue"), ADMIN;

    } /* UNDEBUG ZEBRA */

} /* UNDEBUG */


/* ACCESS-LIST */
access-list("Add an access list entry") {

    /* ACCESS-LIST 1-99, 1300-1999 */
    (<1-99:int32 range[1:99]>("IP standard access list") |<1300-1999:int32 range[1300:1999]>  ("IP standard access list (expanded range)")) {

        /* ACCESS-LIST 1-99, 1300-1999 DENY|PERMIT */
	(<action:string  keyword:deny>("Specify packets to reject")|<action:string  keyword:permit>("Specify packets to forward")) {
	    
	    any("Any source host"), cli_set("access-list[] $!id $!action $!srcaddr=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $_SEQ=(sequence)10"),ADMIN;
	    any("Any source host"), cli_set("access-list[] $!id $!action $!srcaddr=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $_SEQ=(sequence)10"),ADMIN;
	    
	    <ipv4addr>("Address to match") <ipv4addr>("Wildcard bits"), cli_set("access-list[] $!id $!action $!srcaddr $!srcmask $_SEQ=(sequence)10"),ADMIN;
	    <ipv4addr>("Address to match") <ipv4addr>("Wildcard bits"), cli_set("access-list[] $!id $!action $!srcaddr $!srcmask $_SEQ=(sequence)10"),ADMIN;
        
	    host("A single host address") <ipv4addr>("Host address"), cli_set("access-list[] $!id $!action $!srcaddr $!srcmask=(ipv4addr)0.0.0.0 $_SEQ=(sequence)10"),ADMIN;
	    host("A single host address") <ipv4addr>("Host address"), cli_set("access-list[] $!id $!action $!srcaddr $!srcmask=(ipv4addr)0.0.0.0 $_SEQ=(sequence)10"),ADMIN;
	}
	
	/* ACCESS-LIST 1-99, 1300-1999 REMARK */
	remark("Access list entry comment") <rest>("Comment up to 100 characters"), cli_set("access-list[] $!id $!action=(string)\"remark\" $!remark"), ADMIN;


    }  /* ACCESS-LIST 1-99, 1300-1999 */

    /* ACCESS-LIST 100-199, 2000-2699  */
    (<100-199:int32 range[100:199]>("IP extended access list")|<2000-2699:int32 range[2000:2699]>("IP extended access list (expanded range)")) {

	/* ACCESS-LIST 100-199, 2000-2699 DENY|PERMIT IP */
	(<action:string  keyword:deny>("Specify packets to reject")|<action:string  keyword:permit>("Specify packets to forward")) ip("Any Internet Protocol") {
	    
	    any("Any source host") any("Any destination host"), cli_set("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $!dstaddr=(ipv4addr)0.0.0.0 $!dstmask=(ipv4addr)255.255.255.255"), ADMIN;
	    any("Any source host") <ipv4addr>("Destination address") <ipv4addr>("Destination Wildcard bits"), cli_set("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $!dstaddr $!dstmask"), ADMIN;
	    any("Any source host") host("A single destination host") <ipv4addr>("Destination address"), cli_set("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $!dstaddr $!dstmask=(ipv4addr)0.0.0.0"), ADMIN;

	    <ipv4addr>("Source address") <ipv4addr>("Source wildcard bits") any("Any destination host"), cli_set("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr $!srcmask $!dstaddr=(ipv4addr)0.0.0.0 $!dstmask=(ipv4addr)255.255.255.255"), ADMIN;
	    <ipv4addr>("Source address") <ipv4addr>("Source wildcard bits") <ipv4addr>("Destination address") <ipv4addr>("Destination Wildcard bits"), cli_set("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr $!srcmask $!dstaddr $!dstmask"), ADMIN;
	    <ipv4addr>("Source address") <ipv4addr>("Source wildcard bits") host("A single destination host") <ipv4addr>("Destination address"), cli_set("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr $!srcmask $!dstaddr $!dstmask=(ipv4addr)0.0.0.0"), ADMIN;

	    host("A single source host") <ipv4addr>("Source address") any("Any destination host"), cli_set("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr $!srcmask=(ipv4addr)0.0.0.0 $!dstaddr=(ipv4addr)0.0.0.0 $!dstmask=(ipv4addr)255.255.255.255"), ADMIN;
	    host("A single source host") <ipv4addr>("Source address") <ipv4addr>("Destination address") <ipv4addr>("Destination Wildcard bits"), cli_set("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr $!srcmask=(ipv4addr)0.0.0.0 $!dstaddr $!dstmask"), ADMIN;
	    host("A single source host") <ipv4addr>("Source address") host("A single destination host") <ipv4addr>("Destination address"), cli_set("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr $!srcmask=(ipv4addr)0.0.0.0 $!dstaddr $!dstmask=(ipv4addr)0.0.0.0"), ADMIN;
	} /* ACCESS-LIST 100-199, 2000-2699 DENY|PERMIT IP */

	/* ACCESS-LIST 100-199, 2000-2699 REMARK */
	remark("Access list entry comment") <rest>("Comment up to 100 characters"), cli_set("access-list[] $!id $!action=(string)\"remark\" $!remark"), ADMIN;
	
    } /* ACCESS-LIST 100-199, 2000-2699 */
    
} /* ACCESS-LIST */


/* NO */
no("Negate a command or set its defaults") {
    
    /* NO ACCESS-LIST */
    access-list("Add an access list entry") {
	
	/* NO ACCESS-LIST 1-99, 1300-1999 */
        (<1-99:int32 range[1:99]>("IP standard access list") |<1300-1999:int32 range[1300:1999]>  ("IP standard access list (expanded range)")), cli_del("access-list[] $!id $!action=* $!srcaddr=* $!srcmask=*"), ADMIN; {
	    
	    /* NO ACCESS-LIST 1-99, 1300-1999 DENY|PERMIT */
	    (<action:string  keyword:deny>("Specify packets to reject")|<action:string  keyword:permit>("Specify packets to forward")) {

		any("Any source host"), cli_del("access-list[] $!id $!action $!srcaddr=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255"), ADMIN;
		<ipv4addr>("Address to match") <ipv4addr>("Wildcard bits"), cli_del("access-list[] $!id $!action $!srcaddr $!srcmask"), ADMIN;
		host("A single host address") <ipv4addr>("Host address"), cli_del("access-list[] $!id $!action $!srcaddr $!srcmask=(ipv4addr)0.0.0.0"), ADMIN;
	    } /* NO ACCESS-LIST 1-99, 1300-1999 DENY|PERMIT */
	    
	    /* NO ACCESS-LIST 1-99, 1300-1999 REMARK */

	    remark("Access list entry comment") <rest>("Comment up to 100 characters"), cli_del("access-list[] $!id $!action=(string)\"remark\" $!remark"), ADMIN;
	
	} /* NO ACCESS-LIST 1-99, 1300-1999 */


	/* NO ACCESS-LIST 100-199, 2000-2699 */
	(<100-199:int32 range[100:199]>("IP extended access list")|<200-2699:int32 range[2000:2699]>("IP extended access list (expanded range)")), cli_del("access-list[] $!id $!action=* $!remark=* $!proto=* $!srcaddr=* $!srcmask=* $!dstaddr=* $!dstmask=*"), ADMIN; {
	    
	    /* NO ACCESS-LIST 100-199, 2000-2699 DENY|PERMIT IP */
	    (<action:string  keyword:deny>("Specify packets to reject")|<action:string  keyword:permit>("Specify packets to forward")) ip("Any Internet Protocol") {
		
		any("Any source host") any("Any destination host"), cli_del("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $!dstaddr=(ipv4addr)0.0.0.0 $!dstmask=(ipv4addr)255.255.255.255"), ADMIN;
		any("Any source host") <ipv4addr>("Destination address") <ipv4addr>("Destination Wildcard bits"), cli_del("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $!dstaddr $!dstmask"), ADMIN;
		any("Any source host") host("A single destination host") <ipv4addr>("Destination address"), cli_del("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $!dstaddr $!dstmask=(ipv4addr)0.0.0.0"), ADMIN;
		
		<ipv4addr>("Source address") <ipv4addr>("Source wildcard bits") any("Any destination host"), cli_del("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr $!srcmask $!dstaddr=(ipv4addr)0.0.0.0 $!dstmask=(ipv4addr)255.255.255.255"), ADMIN;
		<ipv4addr>("Source address") <ipv4addr>("Source wildcard bits") <ipv4addr>("Destination address") <ipv4addr>("Destination Wildcard bits"), cli_del("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr $!srcmask $!dstaddr $!dstmask"), ADMIN;
		<ipv4addr>("Source address") <ipv4addr>("Source wildcard bits") host("A single destination host") <ipv4addr>("Destination address"), cli_del("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr $!srcmask $!dstaddr $!dstmask=(ipv4addr)0.0.0.0"), ADMIN;

		host("A single source host") <ipv4addr>("Source address") any("Any destination host"), cli_del("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr $!srcmask=(ipv4addr)0.0.0.0 $!dstaddr=(ipv4addr)0.0.0.0 $!dstmask=(ipv4addr)255.255.255.255"), ADMIN;
		host("A single source host") <ipv4addr>("Source address") <ipv4addr>("Destination address") <ipv4addr>("Destination Wildcard bits"), cli_del("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr $!srcmask=(ipv4addr)0.0.0.0 $!dstaddr $!dstmask"), ADMIN;
		host("A single source host") <ipv4addr>("Source address") host("A single destination host") <ipv4addr>("Destination address"), cli_del("access-list[] $!id $!action $!proto=(string)\"ip\" $!srcaddr $!srcmask=(ipv4addr)0.0.0.0 $!dstaddr $!dstmask=(ipv4addr)0.0.0.0"), ADMIN;
	    } /* NO ACCESS-LIST 100-199, 2000-2699 DENY|PERMIT IP */

	    /* NO ACCESS-LIST 100-199, 2000-2699 REMARK */
	    remark("Access list entry comment") <rest>("Comment up to 100 characters"), cli_del("access-list[] $!id $!action=(string)\"remark\" $!remark"), ADMIN;
	    
	} /* NO ACCESS-LIST 100-199, 2000-2699 */


    } /* NO ACCESS-LIST */

} /* NO */



#ifdef notyet  /* cligen get's confused having both number and strings */
/* ACCESS-LIST <string> DENY */
access-list("Add an access list entry") <string>("IP zebra access list") deny("Specify packets to reject") any("Match any prefix"), cli_set("access-list[] $!id $!action=(string)\"deny\" $!srcaddr=(string)\"any\""), ADMIN;


access-list("Add an access list entry") <string>("IP zebra access list") deny("Specify packets to reject") <ipv4prefix>("Prefix to match"), cli_set("access-list[] $!id $!action=(string)\"deny\" $!srcaddr"), ADMIN;

access-list("Add an access list entry") <string>("IP zebra access list") deny("Specify packets to reject") <ipv4prefix>("Prefix to match") exact-match("Exact match of the prefix"), cli_set("access-list[] $!id $!action=(string)\"deny\" $!srcaddr $exact_match=(string)\"exact-match\""), ADMIN;

#ifdef notyet
no("Negate a command or set its defaults") access-list("Add an access list entry") <string>("IP zebra access list"), cli_del("access-list[] $!id $!action=* $!srcaddr=* $!srcmask=*"), ADMIN;
#endif

no("Negate a command or set its defaults") access-list("Add an access list entry") <string>("IP zebra access list") deny("Specify packets to reject") any("Match any prefix"), cli_del("access-list[] $!id $!action=(string)\"deny\" $!srcaddr=(string)\"any\""), ADMIN;


no("Negate a command or set its defaults") access-list("Add an access list entry") <string>("IP zebra access list") deny("Specify packets to reject") <ipv4prefix>("Prefix to match"), cli_del("access-list[] $!id $!action=(string)\"deny\" $!srcaddr"), ADMIN;

no("Negate a command or set its defaults") access-list("Add an access list entry") <string>("IP zebra access list") deny("Specify packets to reject") <ipv4prefix>("Prefix to match") exact-match("Exact match of the prefix"), cli_del("access-list[] $!id $!action=(string)\"deny\" $!srcaddr $exact_match=(string)\"exact-match\""), ADMIN;

  /* ACCESS-LIST <string> PERMIT */
access-list("Add an access list entry") <string>("IP zebra access list") permit("Specify packets to reject") any("Match any prefix"), cli_set("access-list[] $!id $!action=(string)\"permit\" $!srcaddr=(string)\"any\""), ADMIN;


access-list("Add an access list entry") <string>("IP zebra access list") permit("Specify packets to reject") <ipv4prefix>("Prefix to match"), cli_set("access-list[] $!id $!action=(string)\"permit\" $!srcaddr"), ADMIN;

access-list("Add an access list entry") <string>("IP zebra access list") permit("Specify packets to reject") <ipv4prefix>("Prefix to match") exact-match("Exact match of the prefix"), cli_set("access-list[] $!id $!action=(string)\"permit\" $!srcaddr $exact_match=(string)\"exact-match\""), ADMIN;

#ifdef notyet
no("Negate a command or set its defaults") access-list("Add an access list entry") <string>("IP zebra access list"), cli_del("access-list[] $!id $!action=* $!srcaddr=* $!srcmask=*"), ADMIN;
#endif

no("Negate a command or set its defaults") access-list("Add an access list entry") <string>("IP zebra access list") permit("Specify packets to reject") any("Match any prefix"), cli_del("access-list[] $!id $!action=(string)\"permit\" $!srcaddr=(string)\"any\""), ADMIN;


no("Negate a command or set its defaults") access-list("Add an access list entry") <string>("IP zebra access list") permit("Specify packets to reject") <ipv4prefix>("Prefix to match"), cli_del("access-list[] $!id $!action=(string)\"permit\" $!srcaddr"), ADMIN;

no("Negate a command or set its defaults") access-list("Add an access list entry") <string>("IP zebra access list") permit("Specify packets to reject") <ipv4prefix>("Prefix to match") exact-match("Exact match of the prefix"), cli_del("access-list[] $!id $!action=(string)\"permit\" $!srcaddr $exact_match=(string)\"exact-match\""), ADMIN;


  /* ACCESS-LIST <string> REMARK */
access-list("Add an access list entry") <string>("IP zebra access list") remark("Access list entry comment") <rest>("Comment up to 100 characters"), cli_set("access-list[] $!id $!action=(string)\"remark\" $!remark"), ADMIN;

no("Negate a command or set its defaults") access-list("Add an access list entry") <string>("IP zebra access list") remark("Access list entry comment") <rest>("Comment up to 100 characters"), cli_del("access-list[] $!id $!action=(string)\"remark\" $!remark"), ADMIN;
#endif /* notyet */

/* IP */
ip("Global IP configuration") {

    /* IP ROUTING */
    routing("Enable IP routing"), cli_set("ipv4.forwarding $status=(int)1"), ADMIN;

    /* IP PREFIX-LIST <string> */
    prefix-list("Build a prefix list") <string>("Name of a prefix list") {
	
    /* IP PREFIX-LIST <string> DENY|PERMIT */
	(<action:string  keyword:deny>("Specify packets to reject")|<action:string  keyword:permit>("Specify packets to forward")) {
	    any("Any prefix match"), cli_set("ipv4.prefix-list[].line[] $!name $_SEQ=(sequence)10 $!action $!prefix=(ipv4prefix)0.0.0.0/0"), ADMIN;
	    <ipv4prefix>("IP prefix <network>/<length>, e.g., 35.0.0.0/8"), cli_set("ipv4.prefix-list[].line[] $!name $_SEQ=(sequence)10 $!action $!prefix"), ADMIN;
	    <ipv4prefix>("IP prefix <network>/<length>, e.g., 35.0.0.0/8") ge("Minimum prefix length to be matched") <1-32:int32 range[1:32]>("Minimum prefix length"), cli_set("ipv4.prefix-list[].line[] $!name $_SEQ=(sequence)10 $!action $!prefix $ge"), ADMIN;
	    <ipv4prefix>("IP prefix <network>/<length>, e.g., 35.0.0.0/8") ge("Minimum prefix length to be matched") <1-32:int32 range[1:32]>("Minimum prefix length") le("Maximum prefix length to be matched") <1-32:int32 range[1:32]>("Maximum prefix length"), cli_set("ipv4.prefix-list[].line[] $!name $_SEQ=(sequence)10 $!action $!prefix $ge $le"), ADMIN;
	    <ipv4prefix>("IP prefix <network>/<length>, e.g., 35.0.0.0/8") le("Maximum prefix length to be matched") <1-32:int32 range[1:32]>("Maximum prefix length"), cli_set("ipv4.prefix-list[].line[] $!name $_SEQ=(sequence)10 $!action $!prefix $le"), ADMIN;
	    <ipv4prefix>("IP prefix <network>/<length>, e.g., 35.0.0.0/8") le("Maximum prefix length to be matched") <1-32:int32 range[1:32]>("Maximum prefix length") ge("Minimum prefix length to be matched") <1-32:int32 range[1:32]>("Minimum prefix length"), cli_set("ipv4.prefix-list[].line[] $!name $_SEQ=(sequence)10 $!action $!prefix $le $ge"), ADMIN;
	}  /* IP PREFIX-LIST <string> DENY|PERMIT */

	/* IP PREFIX-LIST <string> DESCRIPTION */
	description("Prefix-list specific description") <rest>("Up to 80 characters describing this prefix-list"), cli_set("ipv4.prefix-list[].description $!name $description"), ADMIN;
	
    } /* IP PREFIX-LIST <string> */


    /* IP ROUTE */
    route("Set static routes") {
	
	<destination:ipv4prefix>("Destination prefix") <nexthop:ipv4addr>("Gateway IP address"), cli_set("ipv4.route.static[] $!prefix $!nexthop"), ADMIN;
	<destination:ipv4prefix>("Destination prefix") <nexthop:ipv4addr>("Gateway IP address") <1-255:int32 range[1:255]>("Distance value for this route"), cli_set("ipv4.route.static[] $!prefix $!nexthop $distance"), ADMIN;
	<destination:ipv4prefix>("Destination prefix") blackhole("Silently discard pkts when matched"), cli_set("ipv4.route.static.null[] $!prefix $blackhole=(string)\"blackhole\""), ADMIN;
	<destination:ipv4prefix>("Destination prefix") blackhole("Silently discard pkts when matched") <1-255:int32 range[1:255]>("Distance value for this route"), cli_set("ipv4.route.static.null[] $!prefix $distance $blackhole=(string)\"blackhole\""), ADMIN;
	<destination:ipv4prefix>("Destination prefix") reject("Send ICMP unreachable when matched"), cli_set("ipv4.route.static.null[] $!prefix $reject=(string)\"reject\""), ADMIN;
	<destination:ipv4prefix>("Destination prefix") reject("Send ICMP unreachable when matched") <1-255:int32 range[1:255]>("Distance value for this route"), cli_set("ipv4.route.static[] $!prefix $distance $reject=(string)\"reject\""), ADMIN;
	<destination:ipv4prefix>("Destination prefix") <interface>("IP gateway interface name"),  cli_set("ipv4.route.static[] $!prefix $!nexthop"), ADMIN;
	<destination:ipv4prefix>("Destination prefix") <interface>("IP gateway interface name") <1-255:int32 range[1:255]>("Distance value for this route"), cli_set("ipv4.route.static[] $!prefix $!nexthop $distance"), ADMIN;
    } /* IP ROUTE */
	
	
} /* IP */



/* NO IP */
no("Negate a command or set its defaults") ip("Global IP configuration") {

    /* NO IP ROUTING */
    routing("Enable IP routing"), cli_del("ipv4.forwarding $status=(int)0"), ADMIN;

    /* NO IP PREFIX-LIST <string> */
#if 0 /* Broken */
    prefix-list("Build a prefix list") <string>("Name of a prefix list"), cli_del("ipv4.prefix-list[].line[] $!name $_SEQ=* $!action=* $!prefix=* $description=*"), ADMIN; {
#else /* Broken */
    prefix-list("Build a prefix list") <string>("Name of a prefix list") {
#endif /* Broken */

	/* NO IP PREFIX-LIST <string> DENY|PERMIT */
	(<action:string  keyword:deny>("Specify packets to reject")|<action:string  keyword:permit>("Specify packets to forward")) {
	    
	    any("Any prefix match"), cli_del("ipv4.prefix-list[].line[] $!name $!action $!prefix=(ipv4prefix)0.0.0.0/0"), ADMIN;
	    <ipv4prefix>("IP prefix <network>/<length>, e.g., 35.0.0.0/8"), cli_del("ipv4.prefix-list[].line[] $!name $!action $!prefix"), ADMIN;
	    <ipv4prefix>("IP prefix <network>/<length>, e.g., 35.0.0.0/8") ge("Minimum prefix length to be matched") <1-32:int32 range[1:32]>("Minimum prefix length"), cli_del("ipv4.prefix-list[].line[] $!name $!action $!prefix $ge"), ADMIN;
	    <ipv4prefix>("IP prefix <network>/<length>, e.g., 35.0.0.0/8") ge("Minimum prefix length to be matched") <1-32:int32 range[1:32]>("Minimum prefix length") le("Maximum prefix length to be matched") <1-32:int32 range[1:32]>("Maximum prefix length"), cli_del("ipv4.prefix-list[].line[] $!name $!action $!prefix $ge $le"), ADMIN;
	    <ipv4prefix>("IP prefix <network>/<length>, e.g., 35.0.0.0/8") le("Maximum prefix length to be matched") <1-32:int32 range[1:32]>("Maximum prefix length"), cli_del("ipv4.prefix-list[].line[] $!name $!action $!prefix $le"), ADMIN;
	    <ipv4prefix>("IP prefix <network>/<length>, e.g., 35.0.0.0/8") le("Maximum prefix length to be matched") <1-32:int32 range[1:32]>("Maximum prefix length") ge("Minimum prefix length to be matched") <1-32:int32 range[1:32]>("Minimum prefix length"), cli_del("ipv4.prefix-list[].line[] $!name $!action $!prefix $le $ge"), ADMIN;
	} /* NO IP PREFIX-LIST <string> DENY|PERMOT */
	
	/* NO IP PREFIX-LIST <string> DESCRIPTION */
	description("Prefix-list specific description") [<rest>("Up to 80 characters describing this prefix-list")], cli_del("ipv4.prefix-list[].description $!name $description"), ADMIN;

    } /* NO IP PREFIX-LIST <string> */

    /* NO IP ROUTE */
    route("Set static routes") {
	<destination:ipv4prefix>("Destination prefix") <nexthop:ipv4addr>("Gateway IP address"), cli_del("ipv4.route.static[] $!prefix $!nexthop"), ADMIN;
	<destination:ipv4prefix>("Destination prefix") <nexthop:ipv4addr>("Gateway IP address") <1-255:int32 range[1:255]>("Distance value for this route"), cli_del("ipv4.route.static[] $!prefix $!nexthop $distance"), ADMIN;
	<destination:ipv4prefix>("Destination prefix") blackhole("Silently discard pkts when matched"), cli_del("ipv4.route.static.null[] $!prefix $blackhole=(string)\"blackhole\""), ADMIN;
	<destination:ipv4prefix>("Destination prefix") blackhole("Silently discard pkts when matched") <1-255:int32 range[1:255]>("Distance value for this route"), cli_del("ipv4.route.static.null[] $!prefix $distance $blackhole=(string)\"blackhole\""), ADMIN;
	<destination:ipv4prefix>("Destination prefix") reject("Send ICMP unreachable when matched"), cli_del("ipv4.route.static.null[] $!prefix $reject=(string)\"reject\""), ADMIN;
	<destination:ipv4prefix>("Destination prefix") reject("Send ICMP unreachable when matched") <1-255:int32 range[1:255]>("Distance value for this route"), cli_del("ipv4.route.static[] $!prefix $distance $reject=(string)\"reject\""), ADMIN;
	<destination:ipv4prefix>("Destination prefix") <interface>("IP gateway interface name"),  cli_del("ipv4.route.static[] $!prefix $!nexthop"), ADMIN;
	<destination:ipv4prefix>("Destination prefix") <interface>("IP gateway interface name") <1-255:int32 range[1:255]>("Distance value for this route"), cli_del("ipv4.route.static[] $!prefix $!nexthop $distance"), ADMIN;
    } /* NO IP ROUTE */

} /* NO IP */
    	

/* ROUTER-ID */
router-id("Manually set the router-id") <ipv4addr>("IP address to use for router-id"), cli_set("router.router-id $routerid"), ADMIN;

#ifdef XXXX
[no("Negate a command or set its defaults")] test("Test") {
    (<action:string  keyword:permit>("Permit")|<action:string  keyword:deny>("Deny")) <arg:string>("argumentet"), cli_zebra_exec("%s test $arg"), ADMIN;
}
#endif
