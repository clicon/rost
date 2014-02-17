/*
 * CVS Version: $Id: linux-tunnel.config.cpp,v 1.3 2013/02/23 00:30:05 benny Exp $
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

#define TUNNEL_IFRX	"tunnel[0-9]+"

CLICON_MODE=STRINGIFY(IOS_CONFIG);
CLICON_PLUGIN="linux-tunnel";

/* INTERFACE */
interface("Select an interface to configure") {
	<name:string regexp:TUNNEL_IFRX>("Interface's name"), tunnel_add_interface("gre"), ADMIN; {
		mode("tunnel encapsulation method") {
			gre("generic route encapsulation protocol"), tunnel_add_interface("gre"), ADMIN;
			ipip("IP over IP encapsulation"), tunnel_add_interface("ipip"), ADMIN;
		}
	}
}

no("Negate a command or set its defaults") {
	interface("Select an interface to configure") {
		<name:string expand_interface()>("Interface's name"), cli_del_tree("interface[] $!name $!unit=(int)0"), ADMIN; {
			mode("tunnel encapsulation method") {
				gre("generic route encapsulation protocol"), cli_del_tree("interface[] $!name $!unit=(int)0"), ADMIN;
				ipip("IP over IP encapsulation"), cli_del_tree("interface[] $!name $!unit=(int)0"), ADMIN;
			}
		}
	}	
}
