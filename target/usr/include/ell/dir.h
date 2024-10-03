/*
 *
 *  Embedded Linux library
 *
 *  Copyright (C) 2017  Intel Corporation. All rights reserved.
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#ifndef __ELL_DIR_H
#define __ELL_DIR_H

#ifdef __cplusplus
extern "C" {
#endif

struct l_dir_watch;

enum l_dir_watch_event {
        L_DIR_WATCH_EVENT_CREATED,
	L_DIR_WATCH_EVENT_REMOVED,
	L_DIR_WATCH_EVENT_MODIFIED,
	L_DIR_WATCH_EVENT_ACCESSED,
};

typedef void (*l_dir_watch_event_func_t) (const char *filename,
						enum l_dir_watch_event event,
						void *user_data);
typedef void (*l_dir_watch_destroy_func_t) (void *user_data);

struct l_dir_watch *l_dir_watch_new(const char *pathname,
					l_dir_watch_event_func_t function,
					void *user_data,
					l_dir_watch_destroy_func_t destroy);
void l_dir_watch_destroy(struct l_dir_watch *watch);

#ifdef __cplusplus
}
#endif

#endif /* __ELL_DIR_H */
