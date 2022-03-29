/* gtk-gui.h
 * Definitions for the GTK GUI
 *
 * Yersinia
 * By David Barroso <tomac@yersinia.net> and Alfredo Andres <aandreswork@hotmail.com>
 * Copyright 2005-2017 Alfredo Andres and David Barroso
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

#ifndef __GTK_GUI_H__
#define __GTK_GUI_H__

#include "thread-util.h"
#include "terminal-defs.h"
#include "admin.h"
#include "interfaces.h"
#include "attack.h"

#include "parser.h"

#define PARAM_SCREEN   10
#define LIST_FILECAPS  9
#define LIST_ATTACKS   8
#define IFACE_SCREEN   7
#define MAIN_SCREEN    6
#define SEC_SCREEN     5
#define ATTACK_SCREEN  4
#define INFO_SCREEN    3
#define HELP_SCREEN    2
#define SPLASH_SCREEN  1

#define INFO_HEIGHT    13 
#define INFO_WIDTH     44
#define MAX_PAD_HEIGHT 40 
#define MAX_PAD_WIDTH  70

static u_int8_t pointer[MAX_PROTOCOLS];

void gtk_gui(void *);
void gtk_gui_th_exit(struct term_node *);

/* Global stuff */
extern void   thread_error(char *, int8_t);
extern u_int32_t uptime;
extern struct term_tty *tty_tmp;
extern int8_t parser_write_config_file(struct term_tty *);


extern int8_t parser_get_formated_inet_address(u_int32_t, char *, u_int16_t);

/* Terminal stuff */
extern struct terminals *terms;
extern int8_t term_add_node(struct term_node **, int8_t, int32_t, pthread_t);

/* Attack stuff */
extern int8_t attack_stp_learn_packet(void);
extern int8_t attack_launch(struct term_node *, u_int16_t, u_int16_t, struct attack_param *, u_int8_t);
extern int8_t attack_kill_th(struct term_node *, pthread_t );
extern int8_t attack_init_params(struct term_node *, struct attack_param *, u_int8_t);
extern int8_t attack_filter_all_params(struct attack_param *, u_int8_t, u_int8_t *);
extern void   attack_free_params(struct attack_param *, u_int8_t);

#endif
/* vim:set tabstop=4:set expandtab:set shiftwidth=4:set textwidth=120: */
