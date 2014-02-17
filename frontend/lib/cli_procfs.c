/*
 *  CVS Version: $Id: cli_procfs.c,v 1.1 2013/04/14 16:20:40 olof Exp $
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

#ifdef HAVE_CONFIG_H
#include "clicon_config.h"
#endif

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>
#include <inttypes.h>
#include <sys/socket.h>
#include <net/if.h>

/* cligen & clicon */
#include <cligen/cligen.h>
#include <clicon/clicon.h>

#include "cli_procfs.h"

/*
 * Parse /proc/net/dev and populate a chunked
 *  vector of  clicon_procfs_ifstats structures.
 */
struct clicon_procfs_ifstats *
clicon_procfs_ifstats(int *nstat, const char *label)
{
    FILE *f;
    int i;
    uint64_t tmp;
    char buf[512], *p;
    struct clicon_procfs_ifstats *stats;
    struct clicon_procfs_ifstats *statp;

    if ((f = fopen(PROCFS_NETDEV, "r")) == NULL) {
	clicon_err(OE_UNIX, errno, "Failed to open %s: %s",
		PROCFS_NETDEV, strerror(errno));
	return NULL;
    }

    *nstat = 0;
    while (fgets (buf, sizeof (buf)-1, f)) {
	if ((p = strchr (buf, ':')) &&
	    sscanf(p+1,
		   "%"PRIu64  "%"PRIu64  "%"PRIu64  "%"PRIu64
		   "%"PRIu64  "%"PRIu64  "%"PRIu64  "%"PRIu64
		   "%"PRIu64  "%"PRIu64  "%"PRIu64  "%"PRIu64
		   "%"PRIu64  "%"PRIu64  "%"PRIu64  "%"PRIu64,
		   &tmp, &tmp, &tmp, &tmp,
		   &tmp, &tmp, &tmp, &tmp,
		   &tmp, &tmp, &tmp, &tmp,
		   &tmp, &tmp, &tmp, &tmp) == 16)
	    (*nstat)++;
    }

    
    stats = (struct clicon_procfs_ifstats *)chunk (sizeof(*stats) * *nstat, label);
    if (stats == NULL) {
	clicon_err(OE_UNIX, errno, "chunk failed: %s", strerror(errno));
	return NULL;
    }


    rewind (f);
    i = 0;
    statp = stats;
    while (i < *nstat && fgets (buf, sizeof (buf)-1, f)) {
	if ((p = strchr (buf, ':')) &&
	    sscanf(p+1, 
		   "%"PRIu64  "%"PRIu64  "%"PRIu64  "%"PRIu64
		   "%"PRIu64  "%"PRIu64  "%"PRIu64  "%"PRIu64
		   "%"PRIu64  "%"PRIu64  "%"PRIu64  "%"PRIu64
		   "%"PRIu64  "%"PRIu64  "%"PRIu64  "%"PRIu64,
		   &statp->pi_rxbyte,
		   &statp->pi_rxpkt,
		   &statp->pi_rxerr,
		   &statp->pi_rxdrop,
		   &statp->pi_rxfifo,
		   &statp->pi_rxframe,
		   &statp->pi_rxcompressed,
		   &statp->pi_rxmcast,

		   &statp->pi_txbyte,
		   &statp->pi_txpkt,
		   &statp->pi_txerr,
		   &statp->pi_txdrop,
		   &statp->pi_txfifo,
		   &statp->pi_txcolls,
		   &statp->pi_txcarrier,
		   &statp->pi_txcompressed) == 16) {

	    *p = '\0';
	    for (p = buf; isspace(*p); p++);
	    strncpy (statp->pi_ifname, p, IFNAMSIZ);
	    i++;
	    statp++;
	}
    }

    fclose(f);
    return stats;
}

/*
 * Populate a stats structure for a particular interface
 */
struct clicon_procfs_ifstats *
clicon_procfs_ifstat(const char *ifname, const char *label)
{
    int n;
    struct clicon_procfs_ifstats *sp, *stats = NULL;

    if((sp = clicon_procfs_ifstats(&n, __FUNCTION__)) == NULL)
	goto done;

    for ( ; n > 0; n--, sp++)  {
	if (strncmp (ifname, sp->pi_ifname, IFNAMSIZ) == 0) {
	    if ((stats = chunkdup (sp, sizeof(*stats), label)) == NULL)
		goto done;
	    break;
	}
    }
		
done:
    unchunk_group(__FUNCTION__);
    return stats;
}

struct clicon_procfs_cpu *
clicon_procfs_cpuinfo(int *ncpu, const char *label)
{
    int i;
    FILE *f;
    char buf[1024];
    int nvec;
    char **vec, **tmp;
    struct clicon_procfs_cpu *cp, *cpp;    
    struct clicon_procfs_cpu *retval = NULL;
    
    if ((f = fopen(PROCFS_CPUINFO, "r")) == NULL) {
	clicon_err(OE_UNIX, errno, "Failed to open %s: %s",
		PROCFS_CPUINFO, strerror(errno));
	return NULL;
    }

    *ncpu = 0;
    while (fgets (buf, sizeof (buf)-1, f)) {
	if (strcmp(buf, "\n") == 0) /* Empty line, CPU section complete */
	    (*ncpu)++;
    }	       

    if ((cp = (struct clicon_procfs_cpu *)chunk(*ncpu * sizeof(*cp), label))==NULL)
	goto catch;
    memset (cp, 0, (*ncpu * sizeof(*cp)));

    cpp = cp;
    rewind (f);
    for (i = 0; i < *ncpu && fgets (buf, sizeof (buf)-1, f); ) {

	if (strcmp(buf, "\n") == 0) { /* Empty line, CPU section complete */
	    i++;
	    cpp++;
	    continue;
	}
	if ((vec = clicon_sepsplit(buf, ":", &nvec, __FUNCTION__)) == NULL)
	    goto catch;

	cpp->cif_ninfo++;	
	tmp = (char **)
	    rechunk(cpp->cif_name, cpp->cif_ninfo * sizeof(char *), label);
	if (tmp == NULL)
	    goto catch;
	cpp->cif_name = tmp;
	tmp = (char **)
	    rechunk(cpp->cif_value, cpp->cif_ninfo * sizeof(char *), label);
	if (tmp == NULL)
	    goto catch;
	cpp->cif_value = tmp;
	
	/* Assign trimmed name, value */
	if ((cpp->cif_name[cpp->cif_ninfo-1] = clicon_strtrim(vec[0], label))==NULL)
	    goto catch;
	if ((cpp->cif_value[cpp->cif_ninfo-1] = clicon_strtrim(vec[1], label))==NULL)
	    goto catch;
	
	unchunk(vec);
    }
    
    retval = cp;

catch:
    fclose(f);
    unchunk_group(__FUNCTION__);
    return retval;
}


char *
clicon_procfs_cpuinfo_value(struct clicon_procfs_cpu *cpu, const char *name)
{
    int i;
    
    for (i = 0; i < cpu->cif_ninfo; i++) 
	if (strcmp(name, cpu->cif_name[i]) == 0)
	    return cpu->cif_value[i];

    return NULL;
}

#ifdef NOTUSED

static int
clicon_procfs_set(const char *path, char *val)
{
    FILE *f;
    
    /* Write to /proc */
    f = fopen(path, "w");
    if (f == NULL) {
	clicon_err(OE_UNIX, errno, "fopen", path);
	return -1;
    }
    fputs(val, f);
    fclose(f);

    return 0;
}

static char *
clicon_procfs_get(const char *path, int val, const char *label)
{
    FILE *f = NULL;
    int len = 0;
    char *str = NULL;
    char buf[1024];
    
    /* Write to /proc */
    f = fopen(path, "r");
    if (f == NULL) {	
	clicon_err(OE_UNIX, errno, "fopen", path);
	goto err;
    }
    while (fgets (buf, sizeof (buf)-1, f))
	len += strlen(buf);
    len++;

    str = chunk(len, label);
    if (str == NULL) {
	clicon_err(OE_UNIX, errno, "chunk", path);
	goto err;
    }

    len--;
    rewind(f);
    while (fgets (buf, sizeof (buf)-1, f)) {
	strncat(str, buf, len);
	len -= strlen(buf);
    }
	
    fclose(f);
    return str;
    
err:
    if (f)
	fclose(f);
    unchunk_group(label);
    str = NULL;
    
    return str;
}
#endif /* NOTUSED */
