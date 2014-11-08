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
CLICON_MODE=STRINGIFY(IOS_ACLNSTD);


/* DENY|PERMIT */
(<action:string  keyword:deny>("Specify packets to reject")|<action:string  keyword:permit>("Specify packets to forward")) {
	
    any("Any source host"), cli_set("ipv4.access-list.standard.named[].line[] $!name=quagga::quagga_acl_cb() $_SEQ=(sequence)10 $!action=$action $!src=(ipv4prefix)0.0.0.0/0 $!exact_match=(bool)false"), ADMIN;
    
    <prefix:ipv4prefix show:A.B.C.D/M>("Prefix to match. e.g. 10.0.0.0/8"), cli_set("ipv4.access-list.standard.named[].line[] $!name=quagga::quagga_acl_cb() $_SEQ=(sequence)10 $!action=$action $!src=$prefix $!exact_match=(bool)false"), ADMIN;
    <prefix:ipv4prefix show:A.B.C.D/M>("Prefix to match. e.g. 10.0.0.0/8") exact-match("Exact match of the prefixes"), cli_set("ipv4.access-list.standard.named[].line[] $!name=quagga::quagga_acl_cb() $_SEQ=(sequence)10 $!action=$action $!src=$prefix $!exact_match=(bool)true"), ADMIN;
  
}
remark("Access list entry comment") <rest>("Comment up to 100 characters"), cli_set("ipv4.access-list.standard.named[].remark $!name=quagga::quagga_acl_cb() $remark"), ADMIN;





/* NO DENY|PERMIT */
no("Negate a command or set its defaults") {
    (<action:string  keyword:deny>("Specify packets to reject")|<action:string  keyword:permit>("Specify packets to forward")) {
	
        any("Any source host"), cli_del("ipv4.access-list.standard.named[].line[] $!name=quagga::quagga_acl_cb() $_SEQ=(sequence)10 $!action=$1 $!src=(ipv4prefix)0.0.0.0/0 $!exact_match=(bool)false"), ADMIN;
    
        <prefix:ipv4prefix show:A.B.C.D/M>("Prefix to match. e.g. 10.0.0.0/8"), cli_del("ipv4.access-list.standard.named[].line[] $!name=quagga::quagga_acl_cb() $_SEQ=(sequence)10 $!action=$action $!src=$prefix $!exact_match=(bool)true"), ADMIN;
        <prefix:ipv4prefix show:A.B.C.D/M>("Prefix to match. e.g. 10.0.0.0/8") exact-match("Exact match of the prefixes"), cli_del("ipv4.access-list.standard.named[].line[] $!name=quagga::quagga_acl_cb() $_SEQ=(sequence)10 $!action=$action $!src=$prefix $!exact_match=(bool)true"), ADMIN;
  

    }

    remark("Access list entry comment"), cli_del("ipv4.access-list.standard.named[].remark $!name=quagga::quagga_acl_cb()"), ADMIN;
    remark("Access list entry comment") <rest>("Comment up to 100 characters"), cli_del("ipv4.access-list.standard.named[].remark $!name=quagga::quagga_acl_cb()"), ADMIN;

}


