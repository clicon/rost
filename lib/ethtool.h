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

#ifndef _OSR_ETHTOOL_H_
#define _OSR_ETHTOOL_H_

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

enum osr_ethtool_type {
  OSR_ETHTOOL_GET,		/* Get settings */
  OSR_ETHTOOL_SET,		/* Change generic options */
  OSR_ETHTOOL_STATS,		/* Get device statistics */
  OSR_ETHTOOL_LINK,		/* Get link status */
  OSR_ETHTOOL_DRVINFO,		/* Get device info */
};

struct osr_etstatent {
    char	etse_name[ETH_GSTRING_LEN+1];
    uint64_t	etse_value;
};

struct osr_etstats {
    uint32_t		 ets_nstats;	/* number of u64's being returned */
    struct osr_etstatent ets_stat[0];
};

struct osr_ethtool_req {
  uint32_t er_cmd;
  char 	   er_name[IFNAMSIZ+1];
  uint16_t er_len;	/* Length of data */
  uint8_t  er_data[0];  /* Request/response data */
};
  
int osr_ethtool_gset(char *, struct ethtool_cmd *);
struct osr_etstats *osr_ethtool_gstats(char *, const char *);
int osr_ethtool_stat(struct osr_etstats *, char *);
int osr_ethtool_getlink(const char *ifname, int *link);
int osr_ethtool_drvinfo(const char *ifname, struct ethtool_drvinfo *drvinfo);
struct clicon_msg *
clicon_msg_ethtool_encode(struct osr_ethtool_req *req, const char *label);
int
clicon_msg_ethtool_decode(struct clicon_msg *msg, 
			 struct osr_ethtool_req **req, const char *label);
int osr_ifspeed(char *ifname, uint32_t *speed);


#endif	/* _OSR_ETHTOOL_H_ */
