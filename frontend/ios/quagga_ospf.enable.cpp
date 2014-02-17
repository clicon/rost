/*
 * CVS Version: $Id: quagga_ospf.enable.cpp,v 1.6 2011/10/30 05:46:42 benny Exp $
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


    /* DEBUG IP OSPF EVENT */
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") event("OSPF event information"), cli_ospf_exec("debug ospf event"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") event("OSPF event information"), cli_ospf_exec("no debug ospf event"), ADMIN;

    /* DEBUG IP OSPF ISM */
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") ism("OSPF Interace State Machine"), cli_ospf_exec("debug ospf ism"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") ism("OSPF Interace State Machine") events("ISM Event Information"), cli_ospf_exec("debug ospf ism events"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") ism("OSPF Interace State Machine") status("ISM Status Information"), cli_ospf_exec("debug ospf ism status"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") ism("OSPF Interace State Machine") timers("ISM Timer Information"), cli_ospf_exec("debug ospf ism timers"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") ism("OSPF Interace State Machine"), cli_ospf_exec("no debug ospf ism"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") ism("OSPF Interace State Machine") events("ISM Event Information"), cli_ospf_exec("no debug ospf ism events"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") ism("OSPF Interace State Machine") status("ISM Status Information"), cli_ospf_exec("no debug ospf ism status"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") ism("OSPF Interace State Machine") timers("ISM Timer Information"), cli_ospf_exec("no debug ospf ism timers"), ADMIN;

    /* DEBUG IP OSPF LSM */
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") lsa("OSPF Link State Advertisement"), cli_ospf_exec("debug ospf lsa"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") lsa("OSPF Link State Advertisement") flooding("LSA flooding"), cli_ospf_exec("debug ospf lsa flooding"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") lsa("OSPF Link State Advertisement") generate("LSA generation"), cli_ospf_exec("debug ospf lsa generate"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") lsa("OSPF Link State Advertisement") install("LSA install/delete"), cli_ospf_exec("debug ospf lsa install"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") lsa("OSPF Link State Advertisement") refresh("LSA refresh"), cli_ospf_exec("debug ospf lsa refresh"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") lsa("OSPF Link State Advertisement"), cli_ospf_exec("no debug ospf lsa"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") lsa("OSPF Link State Advertisement") flooding("LSA flooding"), cli_ospf_exec("no debug ospf lsa flooding"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") lsa("OSPF Link State Advertisement") generate("LSA generation"), cli_ospf_exec("no debug ospf lsa generate"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") lsa("OSPF Link State Advertisement") install("LSA install/delete"), cli_ospf_exec("no debug ospf lsa install"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") lsa("OSPF Link State Advertisement") refresh("LSA refresh"), cli_ospf_exec("no debug ospf lsa refresh"), ADMIN;


    /* DEBUG IP OSPF NSM */
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") nsm("OSPF Neighbor State Machine"), cli_ospf_exec("debug ospf nsm"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") nsm("OSPF Neighbor State Machine") events("NSM event information"), cli_ospf_exec("debug ospf nsm events"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") nsm("OSPF Neighbor State Machine") status("NSM status information"), cli_ospf_exec("debug ospf nsm status"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") nsm("OSPF Neighbor State Machine") timers("NSM timer information"), cli_ospf_exec("debug ospf nsm timer"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") nsm("OSPF Neighbor State Machine"), cli_ospf_exec("no debug ospf nsm"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") nsm("OSPF Neighbor State Machine") events("NSM event information"), cli_ospf_exec("no debug ospf nsm events"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") nsm("OSPF Neighbor State Machine") status("NSM status information"), cli_ospf_exec("no debug ospf nsm status"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") nsm("OSPF Neighbor State Machine") timers("NSM timer information"), cli_ospf_exec("no debug ospf nsm timer"), ADMIN;

    /* DEBUG IP OSPF NSSA */
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") nssa("OSPF NSSA information"), cli_ospf_exec("debug ospf nssa"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") nssa("OSPF NSSA information"), cli_ospf_exec("no debug ospf nssa"), ADMIN;


    /* DEBUG IP OSPF PACKET ALL */
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") all("OSPF all packets"), cli_ospf_exec("debug ospf packet all"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") all("OSPF all packets") detail("Detailed information"), cli_ospf_exec("debug ospf packet all detail"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") all("OSPF all packets") send("Packets sent"), cli_ospf_exec("debug ospf packet all send"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") all("OSPF all packets") send("Packets sent") detail("Detailed information"), cli_ospf_exec("debug ospf packet all send detail"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") all("OSPF all packets") recv("Packets received"), cli_ospf_exec("debug ospf packet all recv"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") all("OSPF all packets") recv("Packets received") detail("Detailed information"), cli_ospf_exec("debug ospf packet all recv detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") all("OSPF all packets"), cli_ospf_exec("no debug ospf packet all"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") all("OSPF all packets") detail("Detailed information"), cli_ospf_exec("no debug ospf packet all detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") all("OSPF all packets") send("Packets sent"), cli_ospf_exec("no debug ospf packet all send"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") all("OSPF all packets") send("Packets sent") detail("Detailed information"), cli_ospf_exec("no debug ospf packet all send detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") all("OSPF all packets") recv("Packets received"), cli_ospf_exec("no debug ospf packet all recv"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") all("OSPF all packets") recv("Packets renceived") detail("Detailed information"), cli_ospf_exec("no debug ospf packet all recv detail"), ADMIN;


    /* DEBUG IP OSPF PACKET DD */
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") dd("OSPF Database Description"), cli_ospf_exec("debug ospf packet dd"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") dd("OSPF Database Description") detail("Detailed information"), cli_ospf_exec("debug ospf packet dd detail"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") dd("OSPF Database Description") send("Packets sent"), cli_ospf_exec("debug ospf packet dd send"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") dd("OSPF Database Description") send("Packets sent") detail("Detailed information"), cli_ospf_exec("debug ospf packet dd send detail"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") dd("OSPF Database Description") recv("Packets received"), cli_ospf_exec("debug ospf packet dd recv"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") dd("OSPF Database Description") recv("Packets received") detail("Detailed information"), cli_ospf_exec("debug ospf packet dd recv detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") dd("OSPF Database Description"), cli_ospf_exec("no debug ospf packet dd"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") dd("OSPF Database Description") detail("Detailed information"), cli_ospf_exec("no debug ospf packet dd detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") dd("OSPF Database Description") send("Packets sent"), cli_ospf_exec("no debug ospf packet dd send"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") dd("OSPF Database Description") send("Packets sent") detail("Detailed information"), cli_ospf_exec("no debug ospf packet dd send detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") dd("OSPF Database Description") recv("Packets received"), cli_ospf_exec("no debug ospf packet dd recv"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") dd("OSPF Database Description") recv("Packets renceived") detail("Detailed information"), cli_ospf_exec("no debug ospf packet dd recv detail"), ADMIN;

    /* DEBUG IP OSPF PACKET HELLO */
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") hello("OSPF hello packets"), cli_ospf_exec("debug ospf packet hello"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") hello("OSPF hello packets") detail("Detailed information"), cli_ospf_exec("debug ospf packet hello detail"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") hello("OSPF hello packets") send("Packets sent"), cli_ospf_exec("debug ospf packet hello send"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") hello("OSPF hello packets") send("Packets sent") detail("Detailed information"), cli_ospf_exec("debug ospf packet hello send detail"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") hello("OSPF hello packets") recv("Packets received"), cli_ospf_exec("debug ospf packet hello recv"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") hello("OSPF hello packets") recv("Packets received") detail("Detailed information"), cli_ospf_exec("debug ospf packet hello recv detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") hello("OSPF hello packets"), cli_ospf_exec("no debug ospf packet hello"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") hello("OSPF hello packets") detail("Detailed information"), cli_ospf_exec("no debug ospf packet hello detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") hello("OSPF hello packets") send("Packets sent"), cli_ospf_exec("no debug ospf packet hello send"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") hello("OSPF hello packets") send("Packets sent") detail("Detailed information"), cli_ospf_exec("no debug ospf packet hello send detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") hello("OSPF hello packets") recv("Packets received"), cli_ospf_exec("no debug ospf packet hello recv"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") hello("OSPF hello packets") recv("Packets renceived") detail("Detailed information"), cli_ospf_exec("no debug ospf packet hello recv detail"), ADMIN;

    /* DEBUG IP OSPF PACKET LS-ACK */
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-ack("OSPF Link State Acknowledgment"), cli_ospf_exec("debug ospf packet ls-ack"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-ack("OSPF Link State Acknowledgment") detail("Detailed information"), cli_ospf_exec("debug ospf packet ls-ack detail"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-ack("OSPF Link State Acknowledgment") send("Packets sent"), cli_ospf_exec("debug ospf packet ls-ack send"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-ack("OSPF Link State Acknowledgment") send("Packets sent") detail("Detailed information"), cli_ospf_exec("debug ospf packet ls-ack send detail"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-ack("OSPF Link State Acknowledgment") recv("Packets received"), cli_ospf_exec("debug ospf packet ls-ack recv"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-ack("OSPF Link State Acknowledgment") recv("Packets received") detail("Detailed information"), cli_ospf_exec("debug ospf packet ls-ack recv detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-ack("OSPF Link State Acknowledgment"), cli_ospf_exec("no debug ospf packet ls-ack"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-ack("OSPF Link State Acknowledgment") detail("Detailed information"), cli_ospf_exec("no debug ospf packet ls-ack detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-ack("OSPF Link State Acknowledgment") send("Packets sent"), cli_ospf_exec("no debug ospf packet ls-ack send"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-ack("OSPF Link State Acknowledgment") send("Packets sent") detail("Detailed information"), cli_ospf_exec("no debug ospf packet ls-ack send detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-ack("OSPF Link State Acknowledgment") recv("Packets received"), cli_ospf_exec("no debug ospf packet ls-ack recv"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-ack("OSPF Link State Acknowledgment") recv("Packets renceived") detail("Detailed information"), cli_ospf_exec("no debug ospf packet ls-ack recv detail"), ADMIN;


    /* DEBUG IP OSPF PACKET LS-REQUEST */
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-request("OSPF Link State Request"), cli_ospf_exec("debug ospf packet ls-request"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-request("OSPF Link State Request") detail("Detailed information"), cli_ospf_exec("debug ospf packet ls-request detail"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-request("OSPF Link State Request") send("Packets sent"), cli_ospf_exec("debug ospf packet ls-request send"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-request("OSPF Link State Request") send("Packets sent") detail("Detailed information"), cli_ospf_exec("debug ospf packet ls-request send detail"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-request("OSPF Link State Request") recv("Packets received"), cli_ospf_exec("debug ospf packet ls-request recv"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-request("OSPF Link State Request") recv("Packets received") detail("Detailed information"), cli_ospf_exec("debug ospf packet ls-request recv detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-request("OSPF Link State Request"), cli_ospf_exec("no debug ospf packet ls-request"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-request("OSPF Link State Request") detail("Detailed information"), cli_ospf_exec("no debug ospf packet ls-request detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-request("OSPF Link State Request") send("Packets sent"), cli_ospf_exec("no debug ospf packet ls-request send"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-request("OSPF Link State Request") send("Packets sent") detail("Detailed information"), cli_ospf_exec("no debug ospf packet ls-request send detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-request("OSPF Link State Request") recv("Packets received"), cli_ospf_exec("no debug ospf packet ls-request recv"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-request("OSPF Link State Request") recv("Packets renceived") detail("Detailed information"), cli_ospf_exec("no debug ospf packet ls-request recv detail"), ADMIN;

    /* DEBUG IP OSPF PACKET LS-UPDATE */
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-update("OSPF Link State Update"), cli_ospf_exec("debug ospf packet ls-update"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-update("OSPF Link State Update") detail("Detailed information"), cli_ospf_exec("debug ospf packet ls-update detail"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-update("OSPF Link State Update") send("Packets sent"), cli_ospf_exec("debug ospf packet ls-update send"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-update("OSPF Link State Update") send("Packets sent") detail("Detailed information"), cli_ospf_exec("debug ospf packet ls-update send detail"), ADMIN;

debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-update("OSPF Link State Update") recv("Packets received"), cli_ospf_exec("debug ospf packet ls-update recv"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-update("OSPF Link State Update") recv("Packets received") detail("Detailed information"), cli_ospf_exec("debug ospf packet ls-update recv detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-update("OSPF Link State Update"), cli_ospf_exec("no debug ospf packet ls-update"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-update("OSPF Link State Update") detail("Detailed information"), cli_ospf_exec("no debug ospf packet ls-update detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-update("OSPF Link State Update") send("Packets sent"), cli_ospf_exec("no debug ospf packet ls-update send"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-update("OSPF Link State Update") send("Packets sent") detail("Detailed information"), cli_ospf_exec("no debug ospf packet ls-update send detail"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-update("OSPF Link State Update") recv("Packets received"), cli_ospf_exec("no debug ospf packet ls-update recv"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") packet("OSPF packets") ls-update("OSPF Link State Update") recv("Packets renceived") detail("Detailed information"), cli_ospf_exec("no debug ospf packet ls-update recv detail"), ADMIN;

    /* DEBUG IP OSPF ZEBRA */
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") zebra("OSPF zebra information"), cli_ospf_exec("debug ospf zebra"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") zebra("OSPF zebra information") interface("Zebra interface"), cli_ospf_exec("debug ospf zebra interface"), ADMIN;
debug("Debugging functions (see also 'undebug')") ip("IP information") ospf("OSPF information") zebra("OSPF zebra information") redistribute("Zebra redistribute"), cli_ospf_exec("debug ospf zebra redistribute"), ADMIN;

undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") zebra("OSPF zebra information"), cli_ospf_exec("no debug ospf zebra"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") zebra("OSPF zebra information") interface("Zebra interface"), cli_ospf_exec("no debug ospf zebra interface"), ADMIN;
undebug("Disable debugging functions (see also 'debug')") ip("IP information") ospf("OSPF information") zebra("OSPF zebra information") redistribute("Zebra redistribute"), cli_ospf_exec("no debug ospf zebra redistribute"), ADMIN;
