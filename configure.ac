#
# Copyright (C) 2009-2014 Olof Hagsand and Benny Holmgren
#
# This file is part of ROST.
#
# ROST is free software; you can redistribute it and/or modify
# it under the terms of the GNU General Public License as published by
# the Free Software Foundation; either version 3 of the License, or
# (at your option) any later version.
#
# ROST is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along wth ROST; see the file COPYING.  If not, see
# <http://www.gnu.org/licenses/>.
#
#

AC_INIT(lib/quaggapi.h)
AC_CONFIG_HEADER(include/rost_config.h)
PKG_PROG_PKG_CONFIG
AC_CANONICAL_TARGET
AC_DEFINE(AUTOCONF)
AC_SUBST(CC)
AC_SUBST(INCLUDES)
AC_SUBST(CPPFLAGS)
AC_SUBST(CFLAGS)
AC_SUBST(LIBS)
AC_SUBST(APPNAME)

#
AC_PROG_CC()
AC_PROG_CPP
AC_PROG_INSTALL
CPPFLAGS="-DHAVE_ROST_CONFIG_H"
CFLAGS="-Wall ${CFLAGS}"
LDFLAGS="-g ${LDFLAGS}"
APPNAME="rost"

PKG_CHECK_MODULES([sqlite], [sqlite3])
PKG_CHECK_MODULES([blkid], [blkid])
PKG_CHECK_MODULES([curl], [libcurl])

AC_CHECK_HEADERS(sys/statfs.h)
AC_CHECK_HEADERS(sys/inotify.h)
AC_CHECK_HEADERS(linux/ethtool.h,,AC_MSG_ERROR("ethtool is required. Install and rerun configure."))
AC_CHECK_HEADERS(endian.h)
AC_CHECK_HEADERS(crypt.h)
AC_CHECK_LIB(crypt, crypt)
AC_CHECK_HEADERS(cligen/cligen.h,,AC_MSG_ERROR("cligen headers are required. Install and rerun configure."))
AC_CHECK_LIB(cligen,cligen_init,,AC_MSG_ERROR("cligen libs are required. Install and rerrun configre."))
AC_CHECK_HEADERS(clicon/clicon.h,,AC_MSG_ERROR("clicon headers are required. Install and rerun configure."), [[#include <cligen/cligen.h>]])
AC_CHECK_LIB(clicon,clicon_handle_init,,AC_MSG_ERROR("clicon libs are required. Install and rerrun configre."), -lcligen)

# Check lspci program used to map PCI bus
AC_PATH_PROG(LSPCI, lspci, /usr/sbin/lspci)
AC_DEFINE_UNQUOTED(PROG_LSPCI, "$LSPCI")

# This is where CLICON include files and libs are
AC_ARG_WITH(clicon,
[  --with-clicon=PATH	  set clicon sdk installation PATH],
  INCLUDES="${INCLUDES} -I$withval/include"
  LIBS="${LIBS} -L $withval/lib "
)

AC_ARG_WITH(ipv6, 
[  --with-ipv6             with IPv6 support],
   AC_DEFINE_UNQUOTED(ROST_IPV6_SUPPORT, 1)
)

# Where is quagga installed?
# (moved from clicon/configure)
QUAGGA_DIR="/var/lib/quagga"
AC_ARG_WITH(quagga_dir, 
[  --with-quagga_dir       set quagga's confapi directory (/var/lib/quagga)],
  if test ! "$withval" = "no"; then
    if test ! "$withval" = "yes"; then
      QUAGGA_DIR="$withval"
    fi
  fi
)
AC_DEFINE_UNQUOTED(QUAGGA_DIR, "$QUAGGA_DIR")

# For rnr router, set ROST_DIR to /rost
# ROST_DIR="/rost"
# (moved from clicon/configure)
if test "$prefix" = "NONE"; then
   ROST_DIR="/usr/local"
else
   ROST_DIR="$prefix"
fi
AC_ARG_WITH(rost_dir, 
[  --with-rost_dir          set rost configure directory],
  if test ! "$withval" = "no"; then
    if test ! "$withval" = "yes"; then
      ROST_DIR="$withval"
    fi
  fi
)
AC_DEFINE_UNQUOTED(ROST_DIR, "${ROST_DIR}")
AC_DEFINE_UNQUOTED(ROST_BIN_DIR, "${ROST_DIR}/bin")
AC_DEFINE_UNQUOTED(ROST_FLASH_DIR, "${ROST_DIR}/flash")
AC_DEFINE_UNQUOTED(ROST_USERS_DIR, "${ROST_DIR}/flash/users")
AC_DEFINE_UNQUOTED(ROST_IMAGE_DIR, "${ROST_DIR}/flash/boot/ROST")
AC_DEFINE_UNQUOTED(ROST_CONFIG_DIR, "${ROST_DIR}/flash/config")

AC_OUTPUT(Makefile
	  rost.conf 
	  lib/Makefile 
	  frontend/Makefile 
	  frontend/lib/Makefile 
	  frontend/ios/Makefile 
	  backend/Makefile 
)

