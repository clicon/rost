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
CLICON_MODE=STRINGIFY(IOS_ACLEXT);


/* DENY|PERMIT */
(<action:string  keyword:deny>("Specify packets to reject")|<action:string  keyword:permit>("Specify packets to forward")) ip("Any Internet Protocol") {
	
    any("Any source host") any("Any destination host"), cli_set("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $_SEQ=(sequence)10 $!action=$action $!protocol=(string)ip $!src=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $!dst=(ipv4addr)0.0.0.0 $!dstmask=(ipv4addr)255.255.255.255"), ADMIN;

    any("Any source host") <dstaddr:ipv4addr>("Destination address") <dstmask:ipv4addr>("Destination wildcard bits"), cli_set("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $_SEQ=(sequence)10  $!action=$action $!protocol=(string)ip $!src=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $!dst=$dstaddr $!dstmask=$dstmask"), ADMIN;

    any("Any source host") host("A single destination host") <dstaddr:ipv4addr>("Destination address"), cli_set("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $!dst=$dstaddr $!dstmask=(ipv4addr)0.0.0.0"), ADMIN;

    <srcaddr:ipv4addr>("Source address") <srcmask:ipv4addr>("Source wildcard bits") any("Any destination host"), cli_set("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $_SEQ=(sequence)10  $!action=$action $!protocol=(string)ip $!src=$srcaddr $!srcmask=$srcmask $!dst=(ipv4addr)0.0.0.0 $!dstmask=(ipv4addr)255.255.255.255"), ADMIN;

   <srcaddr:ipv4addr>("Source address") <srcmask:ipv4addr>("Source wildcard bits") <dstaddr:ipv4addr>("Destination address") <dstmask:ipv4addr>("Destination wildcard bits"), cli_set("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $_SEQ=(sequence)10  $!action=$action $!protocol=(string)ip $!src=$srcaddr $!srcmask=$srcmask $!dst=$dstaddr $!dstmask=$dstmask"), ADMIN;

        <srcaddr:ipv4addr>("Source address") <srcmask:ipv4addr>("Source wildcard bits") host("A single destination host") <dstaddr:ipv4addr>("Destination address"), cli_set("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=$srcaddr $!srcmask=$srcmask $!dst=$dstaddr $!dstmask=(ipv4addr)0.0.0.0"), ADMIN;


        host("A single source host") <srcaddr:ipv4addr>("Source address") any("Any source host"), cli_set("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=$srcaddr $!srcmask=(ipv4addr)0.0.0.0 $!dst=(ipv4addr)0.0.0.0 $!dstmask=(ipv4addr)255.255.255.255"), ADMIN;
        host("A single source host") <srcaddr:ipv4addr>("Source address") <dstaddr:ipv4addr>("Destination address") <dstmask:ipv4addr>("Destination wildcard bits"), cli_set("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=$srcaddr $!srcmask=(ipv4addr)0.0.0.0 $!dst=$dstaddr $!dstmask=$dstmask"), ADMIN;
        host("A single source host") <srcaddr:ipv4addr>("Source address") host("A single destination host") <dstaddr:ipv4addr>("Destination address"), cli_set("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=$srcaddr $!srcmask=(ipv4addr)0.0.0.0 $!dst=$dstaddr $dstmask=(ipv4addr)0.0.0.0"), ADMIN;
}

remark("Access list entry comment") <rest>("Comment up to 100 characters"), cli_set("ipv4.access-list.extended[].remark $!id=quagga::quagga_acl_cb() $remark"), ADMIN;




/* NO DENY|PERMIT */
no("Negate a command or set its defaults") {
    (<action:string  keyword:deny>("Specify packets to reject")|<action:string  keyword:permit>("Specify packets to forward")) ip("Any Internet Protocol") {

        any("Any source host") any("Any destination host"), cli_del("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $!dst=(ipv4addr)0.0.0.0 $!dstmask=(ipv4addr)255.255.255.255"), ADMIN;
    
        any("Any source host") <dstaddr:ipv4addr>("Destination address") <dstmask:ipv4addr>("Destination wildcard bits"), cli_del("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $!dst=$dstaddr $!dstmask=$dstmask"), ADMIN;

        any("Any source host") host("A single destination host") <srcaddr:ipv4addr>("Destination address"), cli_del("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=(ipv4addr)0.0.0.0 $!srcmask=(ipv4addr)255.255.255.255 $!dst=$dstaddr $!dstmask=(ipv4addr)0.0.0.0"), ADMIN;

       <srcaddr:ipv4addr>("Source address") <srcmask:ipv4addr>("Source wildcard bits") any("Any destination host"), cli_del("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=$srcaddr $!srcmask=$srcmask $!dst=(ipv4addr)0.0.0.0 $!dstmask=(ipv4addr)255.255.255.255"), ADMIN;

       <srcaddr:ipv4addr>("Source address") <srcmask:ipv4addr>("Source wildcard bits") <dstaddr:ipv4addr>("Destination address") <dstmask:ipv4addr>("Destination wildcard bits"), cli_del("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=$srcaddr $!srcmask=$srcmask $!dst=$dstaddr $!dstmask=$dstmask"), ADMIN;

        <srcaddr:ipv4addr>("Source address") <srcmask:ipv4addr>("Source wildcard bits") host("A single destination host") <dstaddr:ipv4addr>("Destination address"), cli_del("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=$srcaddr $!srcmask=$srcmask $!dst=$dstaddr $!dstmask=(ipv4addr)0.0.0.0"), ADMIN;

        host("A single source host") <srcaddr:ipv4addr>("Source address") any("Any source host"), cli_del("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=$srcaddr $!srcmask=(ipv4addr)0.0.0.0 $!dst=(ipv4addr)0.0.0.0 $!dstmask=(ipv4addr)255.255.255.255"), ADMIN;
        host("A single source host") <srcaddr:ipv4addr>("Source address") <dstaddr:ipv4addr>("Destination address") <dstmask:ipv4addr>("Destination wildcard bits"), cli_del("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=$srcaddr $!srcmask=(ipv4addr)0.0.0.0 $!dst=$dstaddr $!dstmask=$dstmask"), ADMIN;
        host("A single source host") <srcaddr:ipv4addr>("Source address") host("A single destination host") <dstaddr:ipv4addr>("Destination address"), cli_del("ipv4.access-list.extended[].line[] $!id=quagga::quagga_acl_cb() $!action=$action $!protocol=(string)ip $!src=$srcaddr $!srcmask=(ipv4addr)0.0.0.0 $!dst=$dstaddr $dstmask=(ipv4addr)0.0.0.0"), ADMIN;
    }

   remark("Access list entry comment"), cli_del("ipv4.access-list.extended[].remark $!id=quagga::quagga_acl_cb()"), ADMIN;
   remark("Access list entry comment") <rest>("Comment up to 100 characters"), cli_del("ipv4.access-list.extended[].remark $!id=quagga::quagga_acl_cb()"), ADMIN;
}
 
