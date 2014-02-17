/*
 * CVS Version: $Id: quagga_rip.config.cpp,v 1.7 2013/02/23 00:30:05 benny Exp $
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

    /* ROUTER RIP */
router("Enable a routing process") rip("Routing Information Protocol (RIP)"),  cli_ios_mode((int)IOS_MODE_RIP), ADMIN;
no("Negate a command or set its defaults") router("Enable a routing process") rip("Routing Information Protocol (RIP)"), cli_del_modetree("router.rip $dummy=(int)1"), ADMIN;
