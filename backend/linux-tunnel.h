/*
 *  CVS Version: $Id: linux-tunnel.h,v 1.1 2012/01/13 03:44:18 benny Exp $
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

#ifndef _LINUX_TUNNEL_H_
#define _LINUX_TUNNEL_H_

/* CPP Stringify */
#ifndef STRINGIFY
#define STRINGIFY(s) __str(s)
#define __str(s) #s
#endif

#define TUNIFRX		 tunnel[0-9]+
#define TUNIFRX_FULL	^tunnel[0-9]+$

#define LINUX_TUNNEL_IFRX		STRINGIFY(TUNIFRX)
#define LINUX_TUNNEL_IFRX_FULL		STRINGIFY(TUNIFRX_FULL)

#endif /* _LINUX_TUNNEL_H_ */

