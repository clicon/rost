/*
 * CVS Version: $Id: syslog.config.cpp,v 1.7 2014/01/10 14:08:26 olof Exp $
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
CLICON_PLUGIN="syslog";


    /* LOGGING TRAP */ 
logging("Modify message logging facilities") trap("Set syslog server logging level") <string choice:alerts|crit|err|warning|notice|info|debug>("Logging severity level"), cli_set("logging.trap $level"), ADMIN;
no("Negate a command or set its defaults") logging("Modify message logging facilities") trap("Set syslog server logging level"), cli_del("logging.trap $level=(string)\"notice\""), ADMIN;
no("Negate a command or set its defaults") logging("Modify message logging facilities") trap("Set syslog server logging level") <string choice:alerts|crit|err|warning|notice|info|debug>("Logging severity level"), cli_del("logging.trap $level"), ADMIN;


    /* LOGGING BUFFERED */
logging("Modify message logging facilities") buffered("Set buffered logging parameters"), cli_set("logging.buffered $rows=(int)128 $level=(string)\"notice\""), ADMIN;
logging("Modify message logging facilities") buffered("Set buffered logging parameters") <number range[10:4096]>("Logging buffer rows"), cli_set("logging.buffered $rows $level=(string)\"notice\""), ADMIN;
logging("Modify message logging facilities") buffered("Set buffered logging parameters") <string choice:alerts|crit|err|warning|notice|info|debug>("Logging severity level"), cli_set("logging.buffered $rows=(int)128 $level"), ADMIN;
logging("Modify message logging facilities") buffered("Set buffered logging parameters") <number range[10:4096]>("Logging buffer rows") <string choice:alerts|crit|err|warning|notice|info|debug>("Logging severity level"), cli_set("logging.buffered $rows $level"), ADMIN;
logging("Modify message logging facilities") buffered("Set buffered logging parameters") <string choice:alerts|crit|err|warning|notice|info|debug>("Logging severity level") <number range[10:4096]>("Logging buffer rows"), cli_set("logging.buffered $level $rows"), ADMIN;


no("Negate a command or set its defaults") logging("Modify message logging facilities") buffered("Set buffered logging parameters"), cli_del("logging.buffered $rows=(int)128 $level=(string)\"notice\""), ADMIN;
no("Negate a command or set its defaults") logging("Modify message logging facilities") buffered("Set buffered logging parameters") <number range[10:4096]>("Logging buffer rows"), cli_del("logging.buffered $rows $level=(string)\"notice\""), ADMIN;
no("Negate a command or set its defaults") logging("Modify message logging facilities") buffered("Set buffered logging parameters") <string choice:alerts|crit|err|warning|notice|info|debug>("Logging severity level"), cli_del("logging.buffered $rows=(int)128 $level"), ADMIN;
no("Negate a command or set its defaults") logging("Modify message logging facilities") buffered("Set buffered logging parameters") <number range[10:4096]>("Logging buffer rows") <string choice:alerts|crit|err|warning|notice|info|debug>("Logging severity level"), cli_del("logging.buffered $rows $level"), ADMIN;
no("Negate a command or set its defaults") logging("Modify message logging facilities") buffered("Set buffered logging parameters") <string choice:alerts|crit|err|warning|notice|info|debug>("Logging severity level") <number range[10:4096]>("Logging buffer rows"), cli_del("logging.buffered $level $rows"), ADMIN;

    /* LOGGING HOST */
logging("Modify message logging facilities") host("Set syslog server IP address and parameters") <ipv4addr>("IP address of the syslog server"), cli_set("logging.host[] $!host $protocol=(string)\"udp\" $port=(int)514"), ADMIN;
logging("Modify message logging facilities") host("Set syslog server IP address and parameters") <ipv4addr>("IP address of the syslog server") transport("Specify the transport protocol (default=UDP)") tcp("Transport Control Portocol") port("Specify the TCP port number") <number range[1:65535]>("Port number"), cli_set("logging.host[] $!host $protocol=(string)\"tcp\" $port"), ADMIN;
logging("Modify message logging facilities") host("Set syslog server IP address and parameters") <ipv4addr>("IP address of the syslog server") transport("Specify the transport protocol (default=UDP)") udp("User Datagram Protocol"), cli_set("logging.host[] $!host $protocol=(string)\"udp\" $port=(int)514"), ADMIN;
logging("Modify message logging facilities") host("Set syslog server IP address and parameters") <ipv4addr>("IP address of the syslog server") transport("Specify the transport protocol (default=UDP)") udp("User Datagram Protocol") port("Specify the UDP port number (default=514)") <number range[1:65535]>("Port number"), cli_set("logging.host[] $!host $protocol=(string)\"udp\" $port"), ADMIN;

no("Negate a command or set its defaults") logging("Modify message logging facilities") host("Set syslog server IP address and parameters") <ipv4addr>("IP address of the syslog server"), cli_del("logging.host[] $!host $protocol=(string)\"udp\" $port=(int)514"), ADMIN;
no("Negate a command or set its defaults") logging("Modify message logging facilities") host("Set syslog server IP address and parameters") <ipv4addr>("IP address of the syslog server") transport("Specify the transport protocol (default=UDP)") tcp("Transport Control Portocol") port("Specify the TCP port number") <number range[1:65535]>("Port number"), cli_del("logging.host[] $!host $protocol=(string)\"tcp\" $port"), ADMIN;
no("Negate a command or set its defaults") logging("Modify message logging facilities") host("Set syslog server IP address and parameters") <ipv4addr>("IP address of the syslog server") transport("Specify the transport protocol (default=UDP)") udp("User Datagram Protocol"), cli_del("logging.host[] $!host $protocol=(string)\"udp\" $port=(int)514"), ADMIN;
no("Negate a command or set its defaults") logging("Modify message logging facilities") host("Set syslog server IP address and parameters") <ipv4addr>("IP address of the syslog server") transport("Specify the transport protocol (default=UDP)") udp("User Datagram Protocol") port("Specify the UDP port number (default=514)") <number range[1:65535]>("Port number"), cli_del("logging.host[] $!host $protocol=(string)\"udp\" $port"), ADMIN;
