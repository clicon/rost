/*
 * CVS Version: $Id: system.enable.cpp,v 1.12 2013/04/14 20:38:26 olof Exp $
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

#include <rost_config.h>
#include "ios_macros.h"
CLICON_MODE=STRINGIFY(IOS_ENABLE);


/* ROST */
start("Start shell") shell("Start local BASH shell"), cli_start_shell((int)0), ADMIN;
start("Start shell") shell("Start local BASH shell") <rest>("Command line"), cli_start_shell((int)0), ADMIN;


/* CLI Debug */
debug("Debugging functions (see also 'undebug')") system("CLI and operating system"), cli_debug((int)1), ADMIN;
debug("Debugging functions (see also 'undebug')") system("CLI and operating system") record("Record commands in /tmp/cli.debug.XXX file"), cli_record((int)1), ADMIN;
undebug("Disable debugging functions (see also 'debug')") system("CLI and operating system"), cli_debug((int)0), ADMIN;
undebug("Disable debugging functions (see also 'debug')") system("CLI and operating system") record("Record commands"), cli_record((int)0), ADMIN;

#if 0
change("Make a change operation") user("Change user") <user:string>("User name"), cli_change_user((int)0), SHOW;
#endif
change("Make a change operation") user("Change user") <user:string expand_user()>("User name"), cli_change_user((int)0), SHOW;

archive("Manage archive files") config("Archive the running config"), ios_cli_config_archive((int)0), ADMIN;
configure("Enter configuration mode") replace("Replace the running-config with a new config file") <string expand_snapshot()>("Rollback number"), ios_cli_config_replace((int)0), ADMIN;
configure("Enter configuration mode") terminal("Configure from the terminal"), cli_ios_mode((int)IOS_MODE_CONFIG), ADMIN;

copy("Copy from one file to another") <url>("Source URL") <url>("Destination URL"), cli_copy_url_url((int)0), ADMIN;


copy("Copy from one file to another") <url>("Source URL") running-config("Update (merge with) current system configuration"), cli_copy_url_running((int)0), ADMIN;
copy("Copy from one file to another") <url>("Source URL") startup-config("Copy to startup configuration"), cli_copy_url_startup((int)0), ADMIN;

copy("Copy from one file to another") running-config("Copy current system configuration") <url>("Destination URL"), cli_copy_running_url((int)0), ADMIN;
copy("Copy from one file to another") startup-config("Copy startup configuration") <url>("Destination URL"), cli_copy_startup_url((int)0), ADMIN;

copy("Copy from one file to another") running-config("Copy current system configuration") startup-config("Copy to startup configuration"), cli_copy_running_startup((int)0), ADMIN;
copy("Copy from one file to another") startup-config("Copy startup configuration") running-config("Update (merge with) current system configuration"), cli_copy_startup_running((int)0), ADMIN;

delete("Delete file") file:("Home directory") <file:string expand_home()>, cli_file_del("~/"), ADMIN;
delete("Delete file") flash:("Boot image directory") <file:string expand_flash()>, cli_file_del(ROST_IMAGE_DIR), ADMIN;
/* DIR */
dir("List files on a filesystem"), cli_dir("FLASH"), ADMIN;
dir("List files on a filesystem") flash:("Boot image directory"), cli_dir("FLASH"), ADMIN;
dir("List files on a filesystem") flash:("Boot image directory") <file:string expand_flash()>, cli_dir("FLASH"), ADMIN;
dir("List files on a filesystem") file:("Home directory"), cli_dir("HOME"), ADMIN;
dir("List files on a filesystem") file:("Home directory") <file:string expand_home()>, cli_dir("HOME"), ADMIN;

more("Display the contents of a file") file:("Home directory") <file:string expand_home()>, cli_more("HOME"), ADMIN;
more("Display the contents of a file") flash:("Boot image directory") <file:string expand_flash()>, cli_more("FLASH"), ADMIN;

/* RELOAD */
reload("Halt and perform a cold restart"), cli_reload("/usr/bin/sudo /sbin/shutdown -r now"), ADMIN;
reload("Halt and perform a cold restart") <LINE:rest>("Reason for reload"), cli_reload("/usr/bin/sudo /sbin/shutdown -r now %r"), ADMIN;

reload("Halt and perform a cold restart") halt("Halt system"), cli_reload("/usr/bin/sudo /sbin/shutdown -h now"), ADMIN;
reload("Halt and perform a cold restart") halt("Halt system") <LINE:rest>("Reason for reload"), cli_reload("/usr/bin/sudo /sbin/shutdown -h now %r"), ADMIN;

reload("Halt and perform a cold restart") at("Reload at a specific time/date") <time:string>("Time to reload (hh:mm)"), cli_reload("/usr/bin/sudo /sbin/shutdown -r %s"), ADMIN;
reload("Halt and perform a cold restart") at("Reload at a specific time/date") <time:string>("Time to reload (hh:mm)") <LINE:rest>("Reason for reload"), cli_reload("/usr/bin/sudo /sbin/shutdown -r %s %r"), ADMIN;

reload("Halt and perform a cold restart") at("Reload at a specific time/date") <time:string>("Time to reload (hh:mm)") halt("Halt system"), cli_reload("/usr/bin/sudo /sbin/shutdown -h %s"), ADMIN;
reload("Halt and perform a cold restart") at("Reload at a specific time/date") <time:string>("Time to reload (hh:mm)") halt("Halt system") <LINE:rest>("Reason for reload"), cli_reload("/usr/bin/sudo /sbin/shutdown -h %s %r"), ADMIN;

reload("Halt and perform a cold restart") halt("Halt system") at("Reload at a specific time/date") <time:string>("Time to reload (hh:mm)"), cli_reload("/usr/bin/sudo /sbin/shutdown -h %s"), ADMIN;
reload("Halt and perform a cold restart") halt("Halt system") at("Reload at a specific time/date") <time:string>("Time to reload (hh:mm)") <LINE:rest>("Reason for reload"), cli_reload("/usr/bin/sudo /sbin/shutdown -h %s %r"), ADMIN;


reload("Halt and perform a cold restart") in("Reload after a time interval") <minutes:number>("Delay before reload"), cli_reload("/usr/bin/sudo /sbin/shutdown -r +%n"), ADMIN;
reload("Halt and perform a cold restart") in("Reload after a time interval") <minutes:number>("Delay before reload") <LINE:rest>("Reason for reload"), cli_reload("/usr/bin/sudo /sbin/shutdown -r +%n %r"), ADMIN;

reload("Halt and perform a cold restart") in("Reload after a time interval") <minutes:number>("Delay before reload") halt("Halt system"), cli_reload("/usr/bin/sudo /sbin/shutdown -h +%n"), ADMIN;
reload("Halt and perform a cold restart") in("Reload after a time interval") <minutes:number>("Delay before reload") halt("Halt system") <LINE:rest>("Reason for reload"), cli_reload("/usr/bin/sudo /sbin/shutdown -h +%n %r"), ADMIN;

reload("Halt and perform a cold restart") halt("Halt system") in("Reload after a time interval") <minutes:number>("Delay before reload"), cli_reload("/usr/bin/sudo /sbin/shutdown -h +%n"), ADMIN;
reload("Halt and perform a cold restart") halt("Halt system") in("Reload after a time interval") <minutes:number>("Delay before reload") <LINE:rest>("Reason for reload"), cli_reload("/usr/bin/sudo /sbin/shutdown -h +%n %r"), ADMIN;
reload("Halt and perform a cold restart") cancel("Cancel pending reload"), cli_reload("cancel(/usr/bin/sudo /sbin/shutdown -c"), ADMIN;
reload("Halt and perform a cold restart") cancel("Cancel pending reload") <LINE:rest>("Reason for cancel"), cli_reload("cancel(/usr/bin/sudo /sbin/shutdown -c %r"), ADMIN;

