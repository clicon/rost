/*
 * CVS Version: $Id: quagga.interface.cpp,v 1.10 2014/01/10 14:08:25 olof Exp $
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
CLICON_MODE=STRINGIFY(IOS_INTERFACE);

/* BANDWIDTH */
bandwidth("Set bandwidth informational parameter") <number range[1:10000000]>("Bandwidth in kilobits"), cli_set("interface[].unit[].bandwidth $!name=ios_interface_cb() $!unit=ios_interface_cb() $bandwidth"), ADMIN;
no("Negate a command or set its defaults") bandwidth("Set bandwidth informational parameter") [<number range[1:10000000]>("Bandwidth in kilobits")], cli_del("interface[].unit[].bandwidth $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;


/* DESCRIPTION */
description("Interface specific description") <rest>("Characters describing this interface"), cli_set("interface[].unit[].description $!name=ios_interface_cb() $!unit=ios_interface_cb() $description"), ADMIN;
no("Negate a command or set its defaults") description("Interface specific description") [<rest>("Characters describing this interface")], cli_del("interface[].unit[].description $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;

/* IP ADDRESS */
ip("Interface Internet Protocol config commands") address("Set the IP address of an interface") <ipv4prefix>("IP address"), cli_set("interface[].unit[].inet.address[] $!name=ios_interface_cb() $!unit=ios_interface_cb() $!prefix"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") address("Set the IP address of an interface") <ipv4prefix>("IP address"), cli_del("interface[].unit[].inet.address[] $!name=ios_interface_cb() $!unit=ios_interface_cb() $!prefix"), ADMIN;

/* LINK-DETECT */
link-detect("Enable link detection on interface"), cli_set("interface[].unit[].link-detect $!name=ios_interface_cb() $!unit=ios_interface_cb() $link_detect=(int)1"), ADMIN;
no("Negate a command or set its defaults") link-detect("Enable link detection on interface"), cli_del("interface[].unit[].link-detect $!name=ios_interface_cb() $!unit=ios_interface_cb() $link_detect=(int)0"), ADMIN;

/* SHUTDOWN */
shutdown("Shutdown the selected interface"), cli_set("interface[].unit[].shutdown $!name=ios_interface_cb() $!unit=ios_interface_cb() $shutdown=(int)1"), ADMIN;
no("Negate a command or set its defaults") shutdown("Shutdown the selected interface"), cli_del("interface[].unit[].shutdown $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;

#ifdef ROST_IPV6_SUPPORT
/* IPv6 ADDRESS */
ipv6("IPv6 interface subcommands") address("Configure IPv6 address on interface  address") <ipv6prefix>("IPv6 prefix"), cli_set("interface[].unit[].ipv6.address[] $!name=ios_interface_cb() $!unit=ios_interface_cb() $!prefix"), ADMIN;
no("Negate a command or set its defaults") ipv6("IPv6 interface subcommands") address("Configure IPv6 address on interface  address") <ipv6prefix>("IPv6 prefix"), cli_del("interface[].unit[].ipv6.address[] $!name=ios_interface_cb() $!unit=ios_interface_cb() $!prefix"), ADMIN;

/* IPv6 ND ADV-INTERVAL-OPTION */
ipv6("IPv6 interface subcommands") nd("Neighbor discovery") adv-interval-option("Advertisement Interval Option"), cli_set("interface[].unit[].ipv6.nd.adv-interval-option $!name=ios_interface_cb() $!unit=ios_interface_cb() $advint_option"), ADMIN;
no("Negate a command or set its defaults") ipv6("IPv6 interface subcommands") nd("Neighbor discovery") adv-interval-option("Advertisement Interval Option"), cli_del("interface[].unit[].ipv6.nd.adv-interval-option $!name=ios_interface_cb() $!unit=ios_interface_cb() $advint_option"), ADMIN;

/* IPv6 ND HOME-AGENT-CONFIG-FLAG */
ipv6("IPv6 interface subcommands") nd("Neighbor discovery") home-agent-config-flag("Home Agent configuration flag"), cli_set("interface[].unit[].ipv6.home-agent-config-flag $!name=ios_interface_cb() $!unit=ios_interface_cb() $home_agent_config_flag"), ADMIN;
no("Negate a command or set its defaults") ipv6("IPv6 interface subcommands") nd("Neighbor discovery") home-agent-config-flag("Home Agent configuration flag"), cli_del("interface[].unit[].ipv6.nd.home-agent-config-flag $!name=ios_interface_cb() $!unit=ios_interface_cb() $home_agent_config_flag"), ADMIN;

/* IPv6 ND HOME-AGENT-LIFETIME */
ipv6("IPv6 interface subcommands") nd("Neighbor discovery") home-agent-lifetime("Home Agent lifetime") <SECONDS:number >("Home Agent lifetime in seconds"), cli_set("interface[].unit[].ipv6.nd.home-agent-lifetime $!name=ios_interface_cb() $!unit=ios_interface_cb() $home_agent_lifetime"), ADMIN;

no("Negate a command or set its defaults") ipv6("IPv6 interface subcommands") nd("Neighbor discovery") home-agent-lifetime("Home Agent lifetime"), cli_del("interface[].unit[].ipv6.nd.home-agent-lifetime $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ipv6("IPv6 interface subcommands") nd("Neighbor discovery") home-agent-lifetime("Home Agent lifetime") <SECONDS:number >("Home Agent lifetime in seconds"), cli_del("interface[].unit[].ipv6.nd.home-agent-lifetime $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;

/* IPv6 ND HOME-AGENT-PREFERENCE */
ipv6("IPv6 interface subcommands") nd("Neighbor discovery") home-agent-preference("Home Agent preference") <PREFERENCE:number >("Home Agent preference value 0..65535"), cli_set("interface[].unit[].ipv6.nd.home-agent-preference $!name=ios_interface_cb() $!unit=ios_interface_cb() $home_agent_preference"), ADMIN;

no("Negate a command or set its defaults") ipv6("IPv6 interface subcommands") nd("Neighbor discovery") home-agent-preference("Home Agent preference"), cli_del("interface[].unit[].ipv6.nd.home-agent-preference $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ipv6("IPv6 interface subcommands") nd("Neighbor discovery") home-agent-preference("Home Agent preference") <PREFERENCE:number >("Home Agent preference value 0..65535"), cli_del("interface[].unit[].ipv6.nd.home-agent-preference $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;

/* IPv6 ND MANAGED-CONFIG-FLAG */
ipv6("IPv6 interface subcommands") nd("Neighbor discovery") managed-config-flag("Managed address configuration flag"), cli_set("interface[].unit[].ipv6.managed-config-flag $!name=ios_interface_cb() $!unit=ios_interface_cb() managed_config_flag"), ADMIN;
no("Negate a command or set its defaults") ipv6("IPv6 interface subcommands") nd("Neighbor discovery") managed-config-flag("Managed address configuration flag"), cli_del("interface[].unit[].ipv6.nd.managed-config-flag $!name=ios_interface_cb() $!unit=ios_interface_cb() $managed_config_flag"), ADMIN;


/* IPv6 ND OTHER-CONFIG-FLAG  */
ipv6("IPv6 interface subcommands") nd("Neighbor discovery") other-config-flag("Other stateful configuration flag"), cli_set("interface[].unit[].ipv6.other-config-flag $!name=ios_interface_cb() $!unit=ios_interface_cb() other_config_flag"), ADMIN;
no("Negate a command or set its defaults") ipv6("IPv6 interface subcommands") nd("Neighbor discovery") other-config-flag("Other stateful configuration flag"), cli_del("interface[].unit[].ipv6.nd.other-config-flag $!name=ios_interface_cb() $!unit=ios_interface_cb() $other_config_flag"), ADMIN;
  
#endif /* ROST_IPV6_SUPPORT */
