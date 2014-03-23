/*
 *  CVS Version: $Id: grub.h,v 1.2 2013/03/08 11:35:39 benny Exp $
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

#ifndef _GRUB_H_
#define _GRUB_H_

#define GRUB_DIR	"/rost/flash/boot/grub"
#define GRUB_MENU	GRUB_DIR "/menu.lst"

struct grub_conf {
  cvec *gv;
  int nent;
  cvec **ent;
};

extern char *grub_image_vars[];

struct grub_conf *grub_parsemenu();
struct grub_conf *grub_addimage(struct grub_conf *g, char *img);
struct grub_conf *grub_delimage(struct grub_conf *g, char *img);
int grub_printmenu(struct grub_conf *g, FILE *f);
void grub_free(struct grub_conf *g);



#endif /* _GRUB_H_ */
