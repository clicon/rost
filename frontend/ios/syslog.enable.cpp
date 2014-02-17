/*
 * CVS Version: $Id: syslog.enable.cpp,v 1.4 2011/10/30 05:46:43 benny Exp $
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
CLICON_PLUGIN="syslog";

terminal("Set terminal line parameters") monitor("Copy debug output to the current terminal line"), cli_monitor((int)1), ADMIN;
terminal("Set terminal line parameters") no("Negate a command or set its defaults") monitor("Copy debug output to the current terminal line"), cli_monitor(), ADMIN;
