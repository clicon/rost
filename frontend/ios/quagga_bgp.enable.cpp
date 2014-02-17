/*
 * CVS Version: $Id: quagga_bgp.enable.cpp,v 1.6 2011/10/30 05:46:42 benny Exp $
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

/* DEBUG IP BGP */
debug("Debugging functions (see also 'undebug')") ip("IP information") bgp("BGP information"), cli_bgp_exec("debug bgp"), ADMIN; {


    /* DEBUG IP BGP AS4 */
    as4("BGP AS4 actions"), cli_bgp_exec("debug bgp as4"), ADMIN;
    as4("BGP AS4 actions") segment("Segment debugging"), cli_bgp_exec("debug bgp as4 segment"), ADMIN;

    /* DEBUG IP BGP EVENTS */
    events("BGP events"), cli_bgp_exec("debug bgp events"), ADMIN;


    /* DEBUG IP BGP FILTERS */
    filters("BGP filters"), cli_bgp_exec("debug bgp filters"), ADMIN;


    /* DEBUG IP BGP FSM */
    fsm("BGP Finite State Machine"), cli_bgp_exec("debug bgp fsm"), ADMIN;


    /* DEBUG IP BGP KEEPALIVES */
    keepalives("BGP keepalives"), cli_bgp_exec("debug bgp keepalives"), ADMIN;

    /* DEBUG IP BGP UPDATES */
    updates("BGP updates"), cli_bgp_exec("debug bgp updates"), ADMIN;
    updates("BGP updates") in("Inbound updates"), cli_bgp_exec("debug bgp updates in"), ADMIN;
    updates("BGP updates") out("Outbound updates"), cli_bgp_exec("debug bgp updates out"), ADMIN;
	

    /* DEBUG IP BGP ZEBRA */
    zebra("BGP zebra messages"), cli_bgp_exec("debug bgp zebra"), ADMIN;

} /* DEBUG IP BGP */




/* UNDEBUG IP BGP */
undebug("Disable debugging functions (see also 'debug')") ip("IP information") bgp("BGP information"), cli_bgp_exec("undebug bgp"), ADMIN; {

    /* UNDEBUG IP BGP AS4 */
    as4("BGP AS4 actions"), cli_bgp_exec("undebug bgp as4"), ADMIN;
    as4("BGP AS4 actions") segment("Segment debugging"), cli_bgp_exec("undebug bgp as4 segment"), ADMIN;

    /* UNDEBUG IP BGP EVENTS */
    events("BGP events"), cli_bgp_exec("undebug bgp events"), ADMIN;


    /* UNDEBUG IP BGP FILTERS */
    filters("BGP filters"), cli_bgp_exec("undebug bgp filters"), ADMIN;


    /* UNDEBUG IP BGP FSM */
    fsm("BGP Finite State Machine"), cli_bgp_exec("undebug bgp fsm"), ADMIN;


    /* UNDEBUG IP BGP KEEPALIVES */
    keepalives("BGP keepalives"), cli_bgp_exec("undebug bgp keepalives"), ADMIN;

    /* UNDEBUG IP BGP UPDATES */
    updates("BGP updates"), cli_bgp_exec("undebug bgp updates"), ADMIN;
	

    /* UNDEBUG IP BGP ZEBRA */
    zebra("BGP zebra messages"), cli_bgp_exec("undebug bgp zebra"), ADMIN;

} /* UNDEBUG IP BGP */




