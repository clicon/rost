/*
 * CVS Version: $Id: ios-config.enable.cpp,v 1.1 2012/01/11 05:35:51 benny Exp $
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

CLICON_MODE=STRINGIFY(IOS_ENABLE);
CLICON_PLUGIN="ios-config";

/* IP DNS */
show("Show running system information") {
	running-config("Current operating configuration"), ios_show_running(), ADMIN;
	startup-config("Contents of startup configuration"), ios_show_startup(), ADMIN;
	archive("Archive of the running configuration information"), cli_show_archive((int)0), ADMIN; {
		config("Compare two IOS configuration files") differences("Display the differences between two config files") <string expand_snapshot()>("Rollback number"), ios_show_archive_diff(), ADMIN;
	}
}
