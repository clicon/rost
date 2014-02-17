/*
 *  CVS Version: $Id: linux-vlan.h,v 1.2 2012/02/08 12:11:20 benny Exp $
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

#ifndef _LINUX_VLAN_H_
#define _LINUX_VLAN_H_

/* CPP Stringify */
#ifndef STRINGIFY
#define STRINGIFY(s) __str(s)
#define __str(s) #s
#endif

#define MIN_VID		0
#define MAX_VID		4094

#define IFRX		 eth(-[0-9]+-|)[0-9]+\\.[0-9]+
#define IFRX_FULL	^eth(-[0-9]+-|)[0-9]+\\.[0-9]+$

#define LINUX_VLAN_IFRX		STRINGIFY(IFRX)
#define LINUX_VLAN_IFRX_FULL		STRINGIFY(IFRX_FULL)

#endif /* _LINUX_VLAN_H_ */

