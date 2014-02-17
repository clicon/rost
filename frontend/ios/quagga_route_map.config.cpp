/*
 * CVS Version: $Id: quagga_route_map.config.cpp,v 1.10 2014/01/10 14:08:26 olof Exp $
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
#include "ios_macros.h"
CLICON_MODE=STRINGIFY(IOS_CONFIG);

  /* ROUTE-MAP */
route-map("Create route-map or enter route-map command mode") <name:string expand_routemap()>("Route map name") deny("Route map denies set operations") <number range[1:65535]>("Sequence to insert to/delete from existing route-map entry"), cli_ios_mode((int)IOS_MODE_ROUTE_MAP), ADMIN;
route-map("Create route-map or enter route-map command mode") <name:string>("Route map name") deny("Route map denies set operations") <number range[1:65535]>("Sequence to insert to/delete from existing route-map entry"), cli_ios_mode((int)IOS_MODE_ROUTE_MAP), ADMIN;
route-map("Create route-map or enter route-map command mode") <name:string expand_routemap()>("Route map name") permit("Route map permits set operations") <number range[1:65535]>("Sequence to insert to/delete from existing route-map entry"), cli_ios_mode((int)IOS_MODE_ROUTE_MAP), ADMIN;
route-map("Create route-map or enter route-map command mode") <name:string>("Route map name") permit("Route map permits set operations") <number range[1:65535]>("Sequence to insert to/delete from existing route-map entry"), cli_ios_mode((int)IOS_MODE_ROUTE_MAP), ADMIN;
  
    /* XXXX Delete the whole sub-tree */
no("Negate a command or set its defaults") route-map("Create route-map or enter route-map command mode") <name:string expand_routemap()>("Route map name"), cli_del("route-map[] $!name"), ADMIN;
no("Negate a command or set its defaults") route-map("Create route-map or enter route-map command mode") <name:string>("Route map name"), cli_del("route-map[] $!name"), ADMIN;
no("Negate a command or set its defaults") route-map("Create route-map or enter route-map command mode") <name:string expand_routemap()>("Route map name") deny("Route map denies set operations") <number range[1:65535]>("Sequence to insert to/delete from existing route-map entry"), cli_del("route-map[].line[] $!name $!line"), ADMIN;
no("Negate a command or set its defaults") route-map("Create route-map or enter route-map command mode") <name:string>("Route map name") deny("Route map denies set operations") <number range[1:65535]>("Sequence to insert to/delete from existing route-map entry"), cli_del("route-map[].line[] $!name $!line"), ADMIN;
no("Negate a command or set its defaults") route-map("Create route-map or enter route-map command mode") <name:string expand_routemap()>("Route map name") permit("Route map permits set operations") <number range[1:65535]>("Sequence to insert to/delete from existing route-map entry"), cli_del("route-map[].line[] $!name $!line"), ADMIN;
no("Negate a command or set its defaults") route-map("Create route-map or enter route-map command mode") <name:string>("Route map name") permot("Route map permits set operations") <number range[1:65535]>("Sequence to insert to/delete from existing route-map entry"), cli_del("route-map[].line[] $!name $!line"), ADMIN;
