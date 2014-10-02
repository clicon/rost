/*
 * CVS Version: $Id: system.config.cpp,v 1.14 2013/04/23 14:00:32 olof Exp $
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
CLICON_PLUGIN="system";

no("Negate a command or set its defaults") username("Establish User Name Authentication") <user:string expand_user()>("User name"), cli_del_tree("system.login.user[] $!user"), ADMIN;

username("Establish User Name Authentication") <user:string>("User name") password("Specify the password for the user") cleartext("Specify cleartext password"), cli_passwd_cleartext("system.login.user[].authentication.password $!user $password"),ADMIN;
username("Establish User Name Authentication") <user:string expand_user()>("User name") password("Specify the password for the user") cleartext("Specify cleartext password"), cli_passwd_cleartext("system.login.user[].authentication.password $!user $password"), ADMIN;

username("Establish User Name Authentication") <user:string>("User name") password("Specify the password for the user") <string>("Hidden password"), cli_set("system.login.user[].authentication.password $!user $password"),ADMIN;
username("Establish User Name Authentication") <user:string expand_user()>("User name") password("Specify the password for the user") <string>("Hidden password"), cli_set("system.login.user[].authentication.password $!user $password"),ADMIN;
   
no("Negate a command or set its defaults") username("Establish User Name Authentication") <user:string expand_user()>("User name") password("Specify the password for the user") <string>("Hidden password"), cli_del("system.login.user[].authentication.password $!user $password"),ADMIN;

/* username class */
username("Establish User Name Authentication") <user:string>("User name") class("Login class") <string choice:none|readonly|superuser>("Login class"), cli_set("system.login.user[].class $!user $class"),ADMIN;
username("Establish User Name Authentication") <user:string expand_user()>("User name") class("Login class") <string choice:none|readonly|superuser>("Login class"), cli_set("system.login.user[].class $!user $class"),ADMIN;

no("Negate a command or set its defaults") username("Establish User Name Authentication") <user:string expand_user()>("User name") class("Login class") <string choice:none|readonly|superuser>("Login class"), cli_del("system.login.user[].class $!user $class"),ADMIN;

/* username uid */
username("Establish User Name Authentication") <user:string>("User name") uid("User identifier") <uid:number>, cli_set("system.login.user[].uid $!user $uid"),ADMIN;
username("Establish User Name Authentication") <user:string expand_user()>("User name") uid("User identifier") <uid:number>, cli_set("system.login.user[].uid $!user $uid"),ADMIN;

no("Negate a command or set its defaults") username("Establish User Name Authentication") <user:string>("User name") uid("User identifier") <uid:number>, cli_del("system.login.user[].uid $!user $uid"),ADMIN;

/* ARP */
arp("Set a static ARP entry") <ipv4addr>("IP address of ARP entry") <macaddr>("48-bit hardware address of ARP entry"), cli_set("ipv4.arp[] $!address $!mac"), ADMIN;
no("Negate a command or set its defaults") arp("Set a static ARP entry") <ipv4addr>("IP address of ARP entry") <macaddr>("48-bit hardware address of ARP entry"), cli_del("ipv4.arp[] $!address $!mac"), ADMIN;

/* HOSTNAME */
hostname("Set system host name") <string>("Name of system"), cli_set("system.hostname $hostname"), ADMIN;

no("Negate a command or set its defaults") hostname("Set system host name"), cli_del("system.hostname $hostname=(string)Router"), ADMIN;
no("Negate a command or set its defaults") hostname("Set system host name") <string>("Name of system"), cli_del("system.hostname $hostname=(string)Router"), ADMIN;

/* INTERFACE <interface> */
interface("Select an interface to configure") <name:string expand_interface()>("Interface's name"), cli_ios_mode((int)IOS_MODE_INTERFACE), ADMIN;

interface("Select an interface to configure") <name:string>("Interface name"), system_interface((int)IOS_MODE_INTERFACE), ADMIN;

#ifdef notyet
no("Negate a command or set its defaults") interface("Select an interface to configure") <interface expand_interface()>("Interface name"), cli_del_interface("interface[].unit[]"), ADMIN;
#endif
