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
CLICON_MODE=STRINGIFY(IOS_CONFIG);


/* IP ACCESS-LIST */
ip("Global IP configuration") access-list("IP access-list") {

    /* ACCESS-LIST STANDARD 1-99, 1300-1999 */
    standard("Standard Access List") (<1-99:int32 range[1:99]>("Standard IP access-list number") |<1300-1999:int32 range[1300:1999]>  ("Standard IP access-list number (expanded range)")), cli_ios_mode((int)IOS_MODE_ACLSTD), ADMIN;
	      
    /* ACCESS-LIST EXTEBNDED 100/199, 2000-2699 */
    extended("Extended Access List") (<100-199:int32 range[100:199]>("Extended IP access-list number")|<2000-2699:int32 range[2000:2699]>("Extended IP access-list number (expanded range)")),  cli_ios_mode((int)IOS_MODE_ACLEXT), ADMIN;
    
    /* ACCESS-LIST STANDARD <name> */
    standard("Standard Access List") <name:string>("IP zebra access-list name"), cli_ios_mode((int)IOS_MODE_ACLNSTD), ADMIN;
	      
} /* IP ACCESS-LIST */


/* NO IP ACCESS-LIST */
no("Negate a command or set its defaults") ip("Global IP configuration") access-list("IP access-list") {

    /* ACCESS-LIST STANDARD 1-99, 1300-1999 */
    standard("Standard Access List") (<1-99:int32 range[1:99]>("Standard IP access-list number") |<1300-1999:int32 range[1300:1999]>  ("Standard IP access-list number (expanded range)")), cli_del_tree("ipv4.access-list.standard[] $!id=$1"), ADMIN;
	      
    /* ACCESS-LIST EXTEBNDED 100/199, 2000-2699 */
    extended("Extended Access List") (<100-199:int32 range[100:199]>("Extended IP access-list number")|<2000-2699:int32 range[2000:2699]>("Extended IP access-list number (expanded range)")), cli_del_tree("ipv4.access-list.extended[] $!id=$1"), ADMIN;
    
    /* ACCESS-LIST STANDARD <name> */
    standard("Standard Access List") <name:string>("IP zebra access-list name"), cli_del_tree("ipv4.access-list.standard.named[] $!name=$name"), ADMIN;

} /* IP ACCESS-LIST */
