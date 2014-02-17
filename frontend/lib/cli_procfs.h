/*
 *  CVS Version: $Id: cli_procfs.h,v 1.1 2013/04/14 16:20:40 olof Exp $
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
 *   ROST is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along wth ROST; see the file COPYING.  If not, see
 *  <http://www.gnu.org/licenses/>.
 *
 */

#ifndef _CLICON_PROCFS_H_
#define _CLICON_PROCFS_H_

#define PROCFS_NETDEV	"/proc/net/dev"
#define PROCFS_CPUINFO	"/proc/cpuinfo"

struct clicon_procfs_ifstats {
    char	pi_ifname[IFNAMSIZ+1];
    /* RX */
    uint64_t	pi_rxpkt;
    uint64_t	pi_rxbyte;
    uint64_t	pi_rxerr;
    uint64_t	pi_rxdrop;
    uint64_t	pi_rxfifo;
    uint64_t	pi_rxframe;
    uint64_t	pi_rxcompressed;
    uint64_t	pi_rxmcast;
    /* TX */
    uint64_t	pi_txpkt;
    uint64_t	pi_txbyte;
    uint64_t	pi_txerr;
    uint64_t	pi_txdrop;
    uint64_t	pi_txfifo;
    uint64_t	pi_txcolls;
    uint64_t	pi_txcarrier;
    uint64_t	pi_txcompressed;
};

struct clicon_procfs_cpu {
    uint16_t	  cif_ninfo;
    char	**cif_name;
    char	**cif_value;
};

/*
 * Prototypes
 */ 

struct clicon_procfs_ifstats *clicon_procfs_ifstats(int *nstat, const char *label);

struct clicon_procfs_ifstats *clicon_procfs_ifstat(const char *ifname, 
					     const char *label);

struct clicon_procfs_cpu *clicon_procfs_cpuinfo(int *ncpu,  const char *label);

char *clicon_procfs_cpuinfo_value(struct clicon_procfs_cpu *cpu, const char *name);

#endif  /* _CLICON_PROCFS_H_ */
