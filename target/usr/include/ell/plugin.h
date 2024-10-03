/*
 *
 *  Embedded Linux library
 *
 *  Copyright (C) 2011-2014  Intel Corporation. All rights reserved.
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

#ifndef __ELL_PLUGIN_H
#define __ELL_PLUGIN_H

#ifdef __cplusplus
extern "C" {
#endif

#define L_PLUGIN_PRIORITY_LOW      -100
#define L_PLUGIN_PRIORITY_DEFAULT     0
#define L_PLUGIN_PRIORITY_HIGH      100

struct l_plugin_desc {
	const char *name;
	const char *description;
	const char *version;
	int priority;
	int (*init) (void);
	void (*exit) (void);
	void *debug_start;
	void *debug_stop;
};


#define L_PLUGIN_DEFINE(symbol, name, description, version, \
						priority, init, exit) \
		extern struct l_plugin_desc symbol \
				__attribute__ ((visibility("default"))); \
		struct l_plugin_desc symbol = { \
			#name, description, version, priority, init, exit, \
			NULL, NULL \
		};

#define L_PLUGIN_DEFINE_DEBUG(symbol, name, description, version, \
						priority, init, exit, debug) \
		extern struct l_debug_desc __start_ ##debug[] \
				__attribute__ ((weak, visibility("hidden"))); \
		extern struct l_debug_desc __stop_ ##debug[] \
				__attribute__ ((weak, visibility("hidden"))); \
		extern struct l_plugin_desc symbol \
				__attribute__ ((visibility("default"))); \
		struct l_plugin_desc symbol = { \
			#name, description, version, priority, init, exit, \
			__start_ ##debug, __stop_ ##debug \
		};

void l_plugin_add(const struct l_plugin_desc *desc, const char *version);

void l_plugin_load(const char *pattern, const char *symbol,
						const char *version);
void l_plugin_unload(void);

#ifdef __cplusplus
}
#endif

#endif /* __ELL_PLUGIN_H */
