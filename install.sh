#!/bin/sh
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
#  ROST is distributed in the hope that it will be useful,
#  but WITHOUT ANY WARRANTY; without even the implied warranty of
#  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
#  GNU General Public License for more details.
#
# You should have received a copy of the GNU General Public License
# along wth ROST; see the file COPYING.  If not, see
# <http://www.gnu.org/licenses/>.
#

if [ $# -ge 2 ]; then
	echo "usage: $0 [prefix]"
	exit
fi

prefix=/usr/local/rost
if [ $# -ge 1 ]; then
    prefix=$1
fi

echo "Welcome to ROST application install script."

# topdir
echo -n "Enter top application directory: [$prefix]: "
read p
if [ "$p" ]; then
    prefix=$p
fi

install -d $prefix
if [ $? != 0 ]; then
    echo "ERROR: Failed to create $prefix"
    exit 1
fi

# Create rest of directories
install -d $prefix/frontend
install -d $prefix/backend
install -d $prefix/db
install -d $prefix/config
install -d $prefix/archive

# Install configuration file
install -m 644 clicon.conf $prefix

# Install datamodel
install -m 644 *.spec $prefix

# Install backend plugins
for i in backend/*.so; do
    echo "install $i $prefix/backend/`basename $i`"
    install $i $prefix/backend/`basename $i`
done

# Install frontend plugins
for i in frontend/*.so frontend/*.cli; do
    echo "install $i $prefix/frontend/`basename $i`"
    install $i $prefix/frontend/`basename $i`
done

# Install frontend syntaxgroup plugins in sub-dirs
for d in frontend/*; do
    b=`basename $d`
    if [ -d $d -a $b != CVS ]; then
	if [ "$(ls -A $DIR)" ]; then
	    install -d $prefix/frontend/$b
	    for i in $d/*.so $d/*.cli; do
		echo "install $i $prefix/frontend/$b/`basename $i`"
		install $i $prefix/frontend/$b/`basename $i`
	    done	
	fi
    fi
done

# LICENSE, README ?
echo "ROST application installed"
echo "You may want to change the CLICON config file so that CLICON_APPDIR points to $prefix"
