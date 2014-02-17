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
AC_CONFIG_HEADER(include/osr_config.h)
AC_CANONICAL_TARGET
AC_DEFINE(AUTOCONF)
AC_SUBST(CC)
AC_SUBST(INCLUDES)
AC_SUBST(CPPFLAGS)
AC_SUBST(CFLAGS)
AC_SUBST(LIBS)

#
AC_PROG_CC()
AC_PROG_CPP
CPPFLAGS="-DHAVE_OSR_CONFIG_H"
CFLAGS="-g -Wall -Werror -x c" # -g/-O2 # -Werror
LDFLAGS="-g"

AC_CHECK_HEADERS(sys/statfs.h)
AC_CHECK_HEADERS(sys/inotify.h)
AC_CHECK_HEADERS(sqlite3.h)
AC_CHECK_HEADERS(linux/ethtool.h)
AC_CHECK_HEADERS(endian.h)
AC_CHECK_HEADERS(crypt.h)
AC_CHECK_LIB(crypt, crypt)

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
   AC_DEFINE_UNQUOTED(OSR_IPV6_SUPPORT, 1)
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

# For rnr router, set OSR_DIR to /osr
# OSR_DIR="/osr"
# (moved from clicon/configure)
if test "$prefix" = "NONE"; then
   OSR_DIR="/usr/local"
else
   OSR_DIR="$prefix"
fi
AC_ARG_WITH(osr_dir, 
[  --with-osr_dir          set osr configure directory],
  if test ! "$withval" = "no"; then
    if test ! "$withval" = "yes"; then
      OSR_DIR="$withval"
    fi
  fi
)
AC_DEFINE_UNQUOTED(OSR_DIR, "${OSR_DIR}")
AC_DEFINE_UNQUOTED(OSR_BIN_DIR, "${OSR_DIR}/bin")
AC_DEFINE_UNQUOTED(OSR_FLASH_DIR, "${OSR_DIR}/flash")
AC_DEFINE_UNQUOTED(OSR_USERS_DIR, "${OSR_DIR}/flash/users")
AC_DEFINE_UNQUOTED(OSR_IMAGE_DIR, "${OSR_DIR}/flash/boot/OSR")
AC_DEFINE_UNQUOTED(OSR_CONFIG_DIR, "${OSR_DIR}/flash/config")

AC_OUTPUT(Makefile
	  lib/Makefile 
	  frontend/Makefile 
	  frontend/lib/Makefile 
	  frontend/ios/Makefile 
	  backend/Makefile 
)

