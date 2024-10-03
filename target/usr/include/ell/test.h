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

#ifndef __ELL_TEST_H
#define __ELL_TEST_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*l_test_func_t) (const void *test_data);

void l_test_init(int *argc, char ***argv);
int l_test_run(void);

void l_test_add(const char *name, l_test_func_t function,
					const void *test_data);

#ifdef __cplusplus
}
#endif

#endif /* __ELL_TEST_H */
