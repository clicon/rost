/*
 *  CVS Version: $Id: auth.h,v 1.3 2012/01/03 10:35:10 olof Exp $
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

#ifndef _AUTH_H_
#define _AUTH_H_

/*
 * Constants
 */
/* Group ids: _Dont_ need to be same as in /etc/groups! */
enum rost_gid{
    SHOW_GID = 111,  /* View system status */
    PING_GID,	     /* Allowed to do ping, traceroute */
    ADMIN_GID,	     /* Full rights: configure, reload, etc */
    QUAGGA_GID,
    WHEEL_GID
};

/* Login classes: implicit in code (configurable). Predefined:
   none
   readonly (show)
   superuser(*)
 */

#endif /* _AUTH_H_ */
