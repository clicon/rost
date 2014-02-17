/*
 * CVS Version: $Id: snmp.config.cpp,v 1.6 2011/10/30 05:46:43 benny Exp $
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
CLICON_MODE=MODE_CONFIG;

/* SNMP-SERVER */
snmp-server("Modify SNMP engine parameters") community("Enable SNMP; set community string and access privs") <string>("SNMP community string") ro("Read-only access with this community string"), cli_set("snmp.community.ro[] $!community"), ADMIN;
#if notyet /* No RW access yet */
snmp-server("Modify SNMP engine parameters") community("Enable SNMP; set community string and access privs") <string>("SNMP community string") rw("Read-write access with this community string"), cli_set("snmp.community.rw[] $!community"), ADMIN;
#endif
snmp-server("Modify SNMP engine parameters") contact("Text for mib object sysContact") <rest>("identification of the contact person for this managed node"), cli_set("snmp.contact $contact"), ADMIN;
snmp-server("Modify SNMP engine parameters") location("Text for mib object sysLocation") <rest>("The physical location of this node"), cli_set("snmp.location $location"), ADMIN;

no("Negate a command or set its defaults") snmp-server("Modify SNMP engine parameters") community("Enable SNMP; set community string and access privs") <string>("SNMP community string") ro("Read-only access with this community string"), cli_del("snmp.community.ro[] $!community"), ADMIN;
#if 0 /* No RW access yet */
no("Negate a command or set its defaults") snmp-server("Modify SNMP engine parameters") community("Enable SNMP; set community string and access privs") <string>("SNMP community string") rw("Read-write access with this community string"), cli_del("snmp.community.rw[] $!community"), ADMIN;
#endif
no("Negate a command or set its defaults") snmp-server("Modify SNMP engine parameters") contact("Text for mib object sysContact") <rest>("identification of the contact person for this managed node"), cli_del("snmp.contact $contact"), ADMIN;
no("Negate a command or set its defaults") snmp-server("Modify SNMP engine parameters") location("Text for mib object sysLocation") <rest>("The physical location of this node"), cli_del("snmp.location $location"), ADMIN;
