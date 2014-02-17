/*
 * CVS Version: $Id: quagga_rip.enable.cpp,v 1.6 2011/10/30 05:46:43 benny Exp $
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

    /* SHOW DEBUGGING */
show("Show running system information") debugging("State of each debugging option") rip("RIP information"), cli_rip_exec("show debugging rip"), ADMIN ;
    
    /* DEBUG IP RIP EVENTS */
debug("Debugging functions (see also 'undebug')") ip("IP information") rip("RIP information") events("RIP events"), cli_rip_exec("debug rip events"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") rip("RIP information") events("RIP events"), cli_rip_exec("no debug rip events"), ADMIN;

    /* DEBUG IP RIP PACKET */
debug("Debugging functions (see also 'undebug')") ip("IP information") rip("RIP information") packet("RIP packets"), cli_rip_exec("debug rip packet"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") rip("RIP information") packet("RIP packets") send("Packets sent"), cli_rip_exec("debug rip packet send"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") rip("RIP information") packet("RIP packets") send("Packets sent") detail("Detailed information"), cli_rip_exec("debug rip packet send detail"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") rip("RIP information") packet("RIP packets") recv("Packets received"), cli_rip_exec("debug rip packet recv"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") rip("RIP information") packet("RIP packets") recv("Packets received") detail("Detailed information"), cli_rip_exec("debug rip packet recv detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") rip("RIP information") packet("RIP packets"), cli_rip_exec("no debug rip packet"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") rip("RIP information") packet("RIP packets") send("Packets sent"), cli_rip_exec("no debug rip packet send"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") rip("RIP information") packet("RIP packets") send("Packets sent") detail("Detailed information"), cli_rip_exec("no debug rip packet send"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") rip("RIP information") packet("RIP packets") recv("Packets received"), cli_rip_exec("no debug rip packet recv"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") rip("RIP information") packet("RIP packets") recv("Packets renceived") detail("Detailed information"), cli_rip_exec("no debug rip packet recv"), ADMIN;

    /* DEBUG IP RIP ZEBRA */
debug("Debugging functions (see also 'undebug')") ip("IP information") rip("RIP information") zebra("Zebra communication"), cli_rip_exec("debug rip zebra"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") rip("RIP information") zebra("Zebra communication"), cli_rip_exec("no debug rip zebra"), ADMIN;
