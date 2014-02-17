/*
 *  CVS Version: $Id: interface.h,v 1.7 2012/01/13 03:42:17 benny Exp $
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

#ifndef _INTERFACE_H_
#define _INTERFACE_H_



/*
 * Macros
 */
#define OSR_ETH_PFX "eth"
#define OSR_LO_PFX "lo"
#define OSR_TUN_PFX "tunnel"

#define OSR_IFTYPES	{OSR_ETH_PFX, OSR_LO_PFX, OSR_TUN_PFX, NULL}
#define isether(ifname) (strncmp((ifname), OSR_ETH_PFX, strlen(OSR_ETH_PFX)) == 0)

/*
 * Types
 */ 
struct clicon_if{
    struct clicon_if *ci_next;
    char           ci_name[IFNAMSIZ];
    unsigned int   ci_flags; /* Flags from SIOCGIFFLAGS: see man 7 netdevice */
};

/*
 * Prototypes
 */

int clicon_iflist_get(char *prefix, const char *label, 
		      struct clicon_if **iflist0, int *len);


#endif	/* _INTERFACE_H_ */
