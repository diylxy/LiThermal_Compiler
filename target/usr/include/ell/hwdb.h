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

#ifndef __ELL_HWDB_H
#define __ELL_HWDB_H

#include <stdarg.h>

#ifdef __cplusplus
extern "C" {
#endif

struct l_hwdb;

struct l_hwdb *l_hwdb_new(const char *pathname);
struct l_hwdb *l_hwdb_new_default(void);

struct l_hwdb *l_hwdb_ref(struct l_hwdb *hwdb);
void l_hwdb_unref(struct l_hwdb *hwdb);

struct l_hwdb_entry {
	const char *key;
	const char *value;
	struct l_hwdb_entry *next;
};

struct l_hwdb_entry *l_hwdb_lookup(struct l_hwdb *hwdb, const char *format, ...)
					__attribute__((format(printf, 2, 3)));
struct l_hwdb_entry *l_hwdb_lookup_valist(struct l_hwdb *hwdb,
					const char *format, va_list args);
void l_hwdb_lookup_free(struct l_hwdb_entry *entries);

typedef void (*l_hwdb_foreach_func_t)(const char *modalias,
					struct l_hwdb_entry *entries,
							void *user_data);

bool l_hwdb_foreach(struct l_hwdb *hwdb, l_hwdb_foreach_func_t func,
							void *user_data);

#ifdef __cplusplus
}
#endif

#endif /* __ELL_HWDB_H */
