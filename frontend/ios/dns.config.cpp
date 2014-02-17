/*
 * CVS Version: $Id: dns.config.cpp,v 1.7 2013/02/23 00:30:05 benny Exp $
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

/* IP DNS */
ip("Global IP configuration") {
  domain("IP DNS resolver") {
    name("Define default domain name") {
      <string>("Default domain name"), cli_set("ipv4.domain $domain"), ADMIN;
    }
  }
  name-server("Specify address of name server") {
    <ipv4addr>("Domain server IP address"), cli_set("ipv4.name-server[] $!address"), ADMIN;
  }
}
no("Negate a command or set its defaults") {
  ip("Global IP configuration") {
    domain("IP DNS resolver") name("Define default domain name") <string>("Default domain name"), cli_del("ipv4.domain $domain"), ADMIN;
    name-server("Specify address of name server") <ipv4addr>("Domain server IP address"), cli_del("ipv4.name-server[] $!address"), ADMIN;
  }
}
