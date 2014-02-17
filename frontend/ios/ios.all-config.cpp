/*
 * CVS Version: $Id: ios.all-config.cpp,v 1.5 2013/04/14 20:38:25 olof Exp $
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
CLICON_MODE=MODE_ALL_CONFIG;

end("Exit configuration mode"), cli_ios_mode((int)IOS_MODE_ENABLE), ADMIN;
exit("Exit to previous mode"), cli_ios_mode_up(), ADMIN;
do("To run exec commands in config mode") <LINE:rest>("Exec Command"), cli_ios_do(), ADMIN;
