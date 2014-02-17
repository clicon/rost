/*
 * CVS Version: $Id: quagga_bgp.config.cpp,v 1.8 2014/01/10 14:08:25 olof Exp $
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
CLICON_MODE=STRINGIFY(IOS_CONFIG);

#include "ios_macros.h"

/* ROUTER BGP */
/* XXX: Kludge: 4294967295 gives -1 in cligen. Put 294967295 there for now */
router("Enable a routing process") bgp("Border Gateway Protocol (BGP)") <number range[1:294967295]>("Autonomous system number"), cli_ios_mode((int)IOS_MODE_BGP), ADMIN;
no("Negate a command or set its defaults") router("Enable a routing process") bgp("Border Gateway Protocol (BGP)") <number range[1:294967295]>("Autonomous system number"), cli_del_modetree("router.bgp $as"), ADMIN;
    

/* IP AS-PATH */
ip("Global IP configuration") as-path("BGP autonomous system path filter") access-list("Specify an access list name") <string>("Regular expression access list name") (<action:string  keyword:deny>("Specify packets to reject")|<action:string  keyword:deny>("Specify packets to forward")) <rest>("A regular-expression to match BGP AS paths"), cli_set("ipv4.as-path.access-list[] $!name $!action $!regexp"), ADMIN;

no("Negate a command or set its defaults") ip("Global IP configuration") as-path("BGP autonomous system path filter") access-list("Specify an access list number") <string>("Regular expression access list name"), cli_del("ipv4.as-path.access-list[] $!name $!action=* $!regexp=*"), ADMIN;
no("Negate a command or set its defaults") ip("Global IP configuration") as-path("BGP autonomous system path filter") access-list("Specify an access list number") <string>("Regular expression access list name") (<action:string  keyword:deny>("Specify packets to reject")|<action:string  keyword:deny>("Specify packets to forward")) <rest>("A regular-expression to match BGP AS paths"), cli_del("ipv4.as-path.access-list[] $!name $!action $!regexp"), ADMIN;
