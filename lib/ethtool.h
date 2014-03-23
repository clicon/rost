/*
 *  CVS Version: $Id: ethtool.h,v 1.3 2011/08/24 11:24:12 olof Exp $
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

#ifndef _ROST_ETHTOOL_H_
#define _ROST_ETHTOOL_H_

#include <sys/param.h>
#ifdef HAVE_ENDIAN_H
#include <endian.h>
#endif
#if __BYTE_ORDER == __LITTLE_ENDIAN
#define ntohll(x) (((int64_t)(ntohl((int)((x << 32) >> 32))) << 32) | (unsigned int)ntohl(((int)(x >> 32))))
#define htonll(x) ntohll(x)
#else
#define ntohll(x)  (x)
#define htonll(x)  (x)
#endif

enum rost_ethtool_type {
  ROST_ETHTOOL_GET,		/* Get settings */
  ROST_ETHTOOL_SET,		/* Change generic options */
  ROST_ETHTOOL_STATS,		/* Get device statistics */
  ROST_ETHTOOL_LINK,		/* Get link status */
  ROST_ETHTOOL_DRVINFO,		/* Get device info */
};

struct rost_etstatent {
    char	etse_name[ETH_GSTRING_LEN+1];
    uint64_t	etse_value;
};

struct rost_etstats {
    uint32_t		 ets_nstats;	/* number of u64's being returned */
    struct rost_etstatent ets_stat[0];
};

struct rost_ethtool_req {
  uint32_t er_cmd;
  char 	   er_name[IFNAMSIZ+1];
  uint16_t er_len;	/* Length of data */
  uint8_t  er_data[0];  /* Request/response data */
};
  
int rost_ethtool_gset(char *, struct ethtool_cmd *);
struct rost_etstats *rost_ethtool_gstats(char *, const char *);
int rost_ethtool_stat(struct rost_etstats *, char *);
int rost_ethtool_getlink(const char *ifname, int *link);
int rost_ethtool_drvinfo(const char *ifname, struct ethtool_drvinfo *drvinfo);
struct clicon_msg *
clicon_msg_ethtool_encode(struct rost_ethtool_req *req, const char *label);
int
clicon_msg_ethtool_decode(struct clicon_msg *msg, 
			 struct rost_ethtool_req **req, const char *label);
int rost_ifspeed(char *ifname, uint32_t *speed);


#endif	/* _ROST_ETHTOOL_H_ */
