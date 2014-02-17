/*
 * CVS Version: $Id: linux-vlan.interface.cpp,v 1.2 2014/01/10 14:08:25 olof Exp $
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
CLICON_PLUGIN="linux-vlan";

/* INTERFACE */
encapsulation("Set encapsulation type for an interface") {
	dot1Q("IEEE 802.1Q Virtual LAN") {
	    <VID:number range[1:4094]>("IEEE 802.1Q VLAN ID"), vlan_encapsulation(), ADMIN;
	}
}

