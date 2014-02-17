/*
 * CVS Version: $Id: quagga_ospf.common.cpp,v 1.8 2011/12/14 20:30:24 olof Exp $
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
CLICON_MODE=STRINGIFY(IOS_BASE:IOS_ENABLE);


    /* SHOW DEBUGGING OSPF */
show("Show running system information") debugging("State of each debugging option") ospf("OSPF information"), cli_ospf_exec("show debugging ospf"), ADMIN;

    /* SHOW ROUTE-MAP */
show("Show running system information") route-map("route-map information") ospf("OSPF route-map information"), cli_ospf_exec("show route-map"), SHOW;

    /* SHOW IP OSPF */
show("Show running system information")  ip("IP information") ospf("OSPF information"), cli_ospf_exec("show ip ospf"), SHOW;

    /* SHOW IP OSPF BORDER-ROUTERS */
show("Show running system information")  ip("IP information") ospf("OSPF information") border-routers("Border routers for this area"), cli_ospf_exec("show ip ospf border-routers"), SHOW;

    /* SHOW IP OSPF DATABASE */
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary"), cli_ospf_exec("show ip ospf database"), SHOW;

show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") asbr-summary("ASBR summary link states"), cli_ospf_exec("show ip ospf database asbr-summary"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") asbr-summary("ASBR summary link states") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database asbr-summary self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") asbr-summary("ASBR summary link states") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database asbr-summary adv-router %a"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") asbr-summary("ASBR summary link states") <ipv4addr>("Link State ID (as an IP address)") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database asbr-summary %a self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") asbr-summary("ASBR summary link states") <ipv4addr>("Link State ID (as an IP address)") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database asbr-summary %a adv-router %a"), SHOW;

show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") external("External link states"), cli_ospf_exec("show ip ospf database external"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") external("External link states") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database external self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") external("External link states") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database external adv-router %a"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") external("External link states") <ipv4addr>("Link State ID (as an IP address)") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database external %a self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") external("External link states") <ipv4addr>("Link State ID (as an IP address)") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database external %a adv-router %a"), SHOW;

show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") network("Network link states"), cli_ospf_exec("show ip ospf database network"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") network("Network link states") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database network self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") network("Network link states") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database network adv-router %a"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") network("Network link states") <ipv4addr>("Link State ID (as an IP address)") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database network %a self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") network("Network link states") <ipv4addr>("Link State ID (as an IP address)") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database network %a adv-router %a"), SHOW;

show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") router("Router link states"), cli_ospf_exec("show ip ospf database router"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") router("Router link states") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database router self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") router("Router link states") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database router adv-router %a"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") router("Router link states") <ipv4addr>("Link State ID (as an IP address)") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database router %a self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") router("Router link states") <ipv4addr>("Link State ID (as an IP address)") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database router %a adv-router %a"), SHOW;

show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") summary("Network summary link states"), cli_ospf_exec("show ip ospf database summary"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") summary("Network summary link states") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database summary self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") summary("Network summary link states") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database summary adv-router %a"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") summary("Network summary link states") <ipv4addr>("Link State ID (as an IP address)") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database summary %a self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") summary("Network summary link states") <ipv4addr>("Link State ID (as an IP address)") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database summary %a adv-router %a"), SHOW;

show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") nssa-external("NSSA external link state"), cli_ospf_exec("show ip ospf database nssa-external"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") nssa-external("NSSA external link state") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database nssa-external self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") nssa-external("NSSA external link state") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database nssa-external adv-router %a"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") nssa-external("NSSA external link state") <ipv4addr>("Link State ID (as an IP address)") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database nssa-external %a self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") nssa-external("NSSA external link state") <ipv4addr>("Link State ID (as an IP address)") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database nssa-external %a adv-router %a"), SHOW;

show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-link("Link local Opaque-LSA"), cli_ospf_exec("show ip ospf database opaque-link"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-link("Link local Opaque-LSA") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database opaque-link self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-link("Link local Opaque-LSA") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database opaque-link adv-router %a"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-link("Link local Opaque-LSA") <ipv4addr>("Link State ID (as an IP address)") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database opaque-link %a self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-link("Link local Opaque-LSA") <ipv4addr>("Link State ID (as an IP address)") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database opaque-link %a adv-router %a"), SHOW;

show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-area("Link area Opaque-LSA"), cli_ospf_exec("show ip ospf database opaque-area"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-area("Link area Opaque-LSA") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database opaque-area self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-area("Link area Opaque-LSA") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database opaque-area adv-router %a"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-area("Link area Opaque-LSA") <ipv4addr>("Link State ID (as an IP address)") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database opaque-area %a self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-area("Link area Opaque-LSA") <ipv4addr>("Link State ID (as an IP address)") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database opaque-area %a adv-router %a"), SHOW;

show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-as("Link AS Opaque-LSA"), cli_ospf_exec("show ip ospf database opaque-as"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-as("Link AS Opaque-LSA") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database opaque-as self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-as("Link AS Opaque-LSA") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database opaque-as adv-router %a"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-as("Link AS Opaque-LSA") <ipv4addr>("Link State ID (as an IP address)") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database opaque-as %a self-originate"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") opaque-as("Link AS Opaque-LSA") <ipv4addr>("Link State ID (as an IP address)") adv-router("Advertising Router link states") <ipv4addr>("Advertising Router (as an IP address)"), cli_ospf_exec("show ip ospf database opaque-as %a adv-router %a"), SHOW;

show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") max-age("LSAs in MaxAge list"), cli_ospf_exec("show ip ospf database max-age"), SHOW;

show("Show running system information")  ip("IP information") ospf("OSPF information") database("Database summary") self-originate("Self-originated link states"), cli_ospf_exec("show ip ospf database self-originate"), SHOW;

    /* SHOW IP OSPF INTERFACE */
show("Show running system information")  ip("IP information") ospf("OSPF information") interface("Interface information"), cli_ospf_exec("show ip ospf interface"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") interface("Interface information") <interface expand_interface()>("Interface name"), cli_ospf_exec("show ip ospf interface %i"), SHOW;

    /* SHOW IP OSPF NEIGHBOR */
show("Show running system information")  ip("IP information") ospf("OSPF information") neighbor("Neighbor list"), cli_ospf_exec("show ip ospf neighbor"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") neighbor("Neighbor list") <ipv4addr>("Neighbor ID"), cli_ospf_exec("show ip ospf neighbor %a"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") neighbor("Neighbor list") all("Include down status neighbor"), cli_ospf_exec("show ip ospf neighbor all"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") neighbor("Neighbor list") detail("Detail of all neighbors"), cli_ospf_exec("show ip ospf neighbor detail"), SHOW;
show("Show running system information")  ip("IP information") ospf("OSPF information") neighbor("Neighbor list") detail("Detail of all neighbors") all("Include down status neighbor"), cli_ospf_exec("show ip ospf neighbor detail all"), SHOW;

    /* SHOW IP OSPF ROUTE */
show("Show running system information") ip("IP information") ospf("OSPF information") route("OSPF routing table"), cli_ospf_exec("show ip ospf route"), SHOW;

