/*
 *  CVS Version: $Id: quaggapi.h,v 1.8 2012/01/13 00:55:42 benny Exp $
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

#ifndef _QUAGGAPI_H_
#define _QUAGGAPI_H_

typedef void (quaggapi_cb)(char *str);

/*
 * API batch structure.
 */
struct quaggapi_batch {
  int numcmd;  	/* Number of assigned commands */
  int maxcmd;	/* Number of allocated command structs */
  int numexec;
  struct quaggapi_cmd *cmds;	/* Array of commands in batch */
  quaggapi_cb *cb;		/* Output CB on success if specified */
};

/*
 * API batch command structure
 */
struct quaggapi_cmd {
  char *cmd;
  int retcode;
  char *output;
};

/*
 * Quagga API header info
 */
#define QUAGGAPI_HDR_RETSIZ	3	/* Return code size = 3 characters */
#define QUAGGAPI_HDR_MSGSIZ	12	/* Output mesg size = 6 characters */
#define QUAGGAPI_HDR_SIZ	(QUAGGAPI_HDR_RETSIZ + QUAGGAPI_HDR_MSGSIZ)
struct quaggapi_hdr {
  char retcode[QUAGGAPI_HDR_RETSIZ];
  char msgsize[QUAGGAPI_HDR_MSGSIZ];
};

/*
 * When allocating a quaggapi batch, initially allocate space for this 
 * number of commands. This will grow dynamically as required. 
 */
#define QUAGGAPI_BASE_CMDS	10


/*
 * Quagga API socket names
 */
#define ZEBRA_API_SOCK		"zebra.api"
#define RIP_API_SOCK		"ripd.api"
#define RIPNG_API_SOCK		"ripngd.api"
#define OSPF_API_SOCK		"ospfd.api"
#define OSPF6_API_SOCK		"ospf6d.api"
#define ISIS_API_SOCK		"isisd.api"
#define BGP_API_SOCK		"bgpd.api"
/* Only IPv4 enabled yet */
#define ALL_API_SOCK		ZEBRA_API_SOCK ":" RIP_API_SOCK ":" OSPF_API_SOCK ":" BGP_API_SOCK

#if 0
/*
 * Quagga API socket paths
 */
#define ZEBRA_API_PATH		QUAGGA_DIR "/zebra.api"
#define RIP_API_PATH		QUAGGA_DIR "/ripd.api"
#define RIPNG_API_PATH		QUAGGA_DIR "/ripngd.api"
#define OSPF_API_PATH		QUAGGA_DIR "/ospfd.api"
#define OSPF6_API_PATH		QUAGGA_DIR "/ospf6d.api"
#define ISIS_API_PATH		QUAGGA_DIR "/isisd.api"
#define BGP_API_PATH		QUAGGA_DIR "/bgpd.api"
#define ALL_API_PATH		ZEBRA_API_PATH ":" \
  				RIP_API_PATH ":" \
  				OSPF_API_PATH ":" \
  				BGP_API_PATH
#endif



/* 
 * Quagga command return codes 
 */
#define QUAGGA_SUCCESS              0
#define QUAGGA_WARNING              1
#define QUAGGA_ERR_NO_MATCH         2
#define QUAGGA_ERR_AMBIGUOUS        3
#define QUAGGA_ERR_INCOMPLETE       4
#define QUAGGA_ERR_EXEED_ARGC_MAX   5
#define QUAGGA_ERR_NOTHING_TODO     6
#define QUAGGA_COMPLETE_FULL_MATCH  7
#define QUAGGA_COMPLETE_MATCH       8
#define QUAGGA_COMPLETE_LIST_MATCH  9
#define QUAGGA_SUCCESS_DAEMON      10
#define QUAGGA_NO_CONTACT          11 /* ROST added errcode */

/*
 * Quagga route protocol types
 */
enum {
  QUAGGAPI_PROTO_NONE,
  QUAGGAPI_PROTO_KERNEL,
  QUAGGAPI_PROTO_CONNECTED,
  QUAGGAPI_PROTO_STATIC,
  QUAGGAPI_PROTO_RIP,
  QUAGGAPI_PROTO_RIPNG,
  QUAGGAPI_PROTO_OSPF,
  QUAGGAPI_PROTO_OSPF6,
  QUAGGAPI_PROTO_ISIS,
  QUAGGAPI_PROTO_BGP,
  QUAGGAPI_PROTO_MAX
};  

/*
 * QuaggAPI protocol identifiers
 */
extern const char *quaggapi_proto_str[];

/*
 * String representations of quagga return codes
 */
extern const char *quagga_cmd_retstr[];


#ifdef unused
union qa_addr {
  void *addr;
  struct in_addr addr4;
  struct in6_addr addr6;
};

struct qa_prefix {
  u_char af;
  u_char len;
  union qa_addr u;
};

#define QA_RTFLG_BLACKHOLE	0x01
#define QA_RTFLG_REJECT		0x02
struct qa_route {
  struct qa_prefix prefix;
  union qa_addr dest;
  char iface[IFNAMSIZ+1];
  uint8_t flags;
  uint8_t distance;
};
#endif /* unused */

struct qa_mode {
  uint8_t mode;
  union {
    char *iface;
    uint32_t aclid;
    char *aclname;
    uint32_t bgp_as;
    struct {
      char *name;
      uint8_t permit;
      uint16_t seq;
    } route_map;
  } u;
};

enum {
  QA_MODE_NONE,
  QA_MODE_BASE,
  QA_MODE_ENABLE,
  QA_MODE_CONFIG,
  QA_MODE_INTERFACE,
  QA_MODE_RIP,
  QA_MODE_RIPNG,
  QA_MODE_OSPF,
  QA_MODE_OSPF6,
  QA_MODE_BGP,
  QA_MODE_ISIS,
  QA_MODE_ROUTE_MAP,
  QA_MODE_MAX,
};

struct quaggapi_batch *quaggapi_batchinit(quaggapi_cb *);
int quaggapi_cmdadd (struct quaggapi_batch *, char *, ...);
void quaggapi_free (struct quaggapi_batch *);
struct quaggapi_batch *quaggapi_listexec (const char *, quaggapi_cb *, int, char **, int);
struct quaggapi_batch *quaggapi_strexec (const char *, quaggapi_cb *, int, char *, ...);

struct quaggapi_batch *quaggapi_modeexec (const char *, quaggapi_cb *, struct qa_mode *, char *, ...);

struct quaggapi_batch *quaggapi_lv_exec(char *sockpath, char *cmd);

#endif /* _QUAGGAPI_H_ */
