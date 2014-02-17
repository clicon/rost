/*
 * CVS Version: $Id: quagga_rip.interface.cpp,v 1.7 2013/02/23 00:30:05 benny Exp $
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


#ifdef notyet
    /* IP RIP AUTHENTICATION */
ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") authentication("Authentication control") authentication("Authentication control") ..., cli_set(... )},;
#endif

    /* IP RIP RECEIVE */
ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") receive("Advertisement reception") version("Version control") 1("RIP version 1"), cli_set("interface[].unit[].rip.receive $!name=ios_interface_cb() $!unit=ios_interface_cb() $version=(string)1"), ADMIN;
ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") receive("Advertisement reception") version("Version control") 2("RIP version 2"), cli_set("interface[].unit[].rip.receive $!name=ios_interface_cb() $!unit=ios_interface_cb() $version=(string)2"), ADMIN;
ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") receive("Advertisement reception") version("Version control") 1("RIP version 1") 2("RIP version 2"), cli_set("interface[].unit[].rip.receive $!name=ios_interface_cb() $!unit=ios_interface_cb() $version=(string)\"1 2\""), ADMIN;
ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") receive("Advertisement reception") version("Version control") 2("RIP version 2") 1("RIP version 1"), cli_set("interface[].unit[].rip.receive $version=(string)\"1 2\""), ADMIN;

no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") receive("Advertisement reception") version("Version control"), cli_del("interface[].unit[].rip.receive $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") receive("Advertisement reception") version("Version control") 1("RIP version 1"), cli_del("interface[].unit[].rip.receive $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") receive("Advertisement reception") version("Version control") 2("RIP version 2"), cli_del("interface[].unit[].rip.receive $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") receive("Advertisement reception") version("Version control") 1("RIP version 1") 2("RIP version 2"), cli_del("interface[].unit[].rip.receive $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") receive("Advertisement reception") version("Version control") 2("RIP version 2") 1("RIP version 1"), cli_del("interface[].unit[].rip.receive $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;

    /* IP RIP SEND */
ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") send("Advertisement transmission") version("Version control") 1("RIP version 1"), cli_set("interface[].unit[].rip.send $!name=ios_interface_cb() $!unit=ios_interface_cb() $version=(string)\"1\""), ADMIN;
ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") send("Advertisement transmission") version("Version control") 2("RIP version 2"), cli_set("interface[].unit[].rip.send $!name=ios_interface_cb() $!unit=ios_interface_cb() $version=(string)\"2\""), ADMIN;
ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") send("Advertisement transmission") version("Version control") 1("RIP version 1") 2("RIP version 2"), cli_set("interface[].unit[].rip.send $!name=ios_interface_cb() $!unit=ios_interface_cb() $version=(string)\"1 2\""), ADMIN;
ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") send("Advertisement transmission") version("Version control") 2("RIP version 2") 1("RIP version 1"), cli_set("interface[].unit[].rip.send $!name=ios_interface_cb() $!unit=ios_interface_cb() $version=(string)\"1 2\""), ADMIN;

no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") send("Advertisement transmission") version("Version control"), cli_del("interface[].unit[].rip.send $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") send("Advertisement transmission") version("Version control") 1("RIP version 1"), cli_del("interface[].unit[].rip.send $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") send("Advertisement transmission") version("Version control") 2("RIP version 2"), cli_del("interface[].unit[].rip.send $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") send("Advertisement transmission") version("Version control") 1("RIP version 1") 2("RIP version 2"), cli_del("interface[].unit[].rip.send $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") send("Advertisement transmission") version("Version control") 2("RIP version 2") 1("RIP version 1"), cli_del("interface[].unit[].rip.send $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;


    /* IP RIP SPLIT-HORIZON */
ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") split-horizon("Perform split horizon"), cli_del("interface[].unit[].rip.split-horizon $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") split-horizon("Perform split horizon") poisoned-reverse("With poisoned-reverse"), cli_set("interface[].unit[].rip.split-horizon $!name=ios_interface_cb() $!unit=ios_interface_cb() $poisoned_reverse=(string)\"poisoned-reverse\""), ADMIN;


no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") split-horizon("Perform split horizon"), cli_set("interface[].unit[].rip.split-horizon $!name=ios_interface_cb() $!unit=ios_interface_cb() $no=(string)\"no\""), ADMIN;
no("Negate a command or set its defaults") ip("Interface Internet Protocol config commands") rip("Routing Information Protocol") split-horizon("Perform split horizon") poisoned-reverse("With poisoned-reverse"), cli_del("interface[].unit[].rip.split-horizon $!name=ios_interface_cb() $!unit=ios_interface_cb()"), ADMIN;
