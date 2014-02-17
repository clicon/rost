/*
 * CVS Version: $Id: grub.config.cpp,v 1.8 2013/04/14 20:38:25 olof Exp $
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
CLICON_PLUGIN="grub";

boot("Modify system boot parameters") system("System image file") flash("Boot from flash memory") <file:rest expand_flash()>("System image filename"), cli_add_boot("FLASH"), ADMIN;
no("Negate a command or set its defaults") boot("Modify system boot parameters") system("System image file") flash("Boot from flash memory") <rest>("System image filename"), cli_del_boot(), ADMIN;
