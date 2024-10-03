/*
 *
 *  Embedded Linux library
 *
 *  Copyright (C) 2011-2015  Intel Corporation. All rights reserved.
 *
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

#ifndef __ELL_RINGBUF_H
#define __ELL_RINGBUF_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef void (*l_ringbuf_tracing_func_t)(const void *buf, size_t count,
							void *user_data);

struct l_ringbuf;

struct l_ringbuf *l_ringbuf_new(size_t size);
void l_ringbuf_free(struct l_ringbuf *ringbuf);

bool l_ringbuf_set_input_tracing(struct l_ringbuf *ringbuf,
			l_ringbuf_tracing_func_t callback, void *user_data);

size_t l_ringbuf_capacity(struct l_ringbuf *ringbuf);

size_t l_ringbuf_len(struct l_ringbuf *ringbuf);
size_t l_ringbuf_drain(struct l_ringbuf *ringbuf, size_t count);
void *l_ringbuf_peek(struct l_ringbuf *ringbuf, size_t offset,
							size_t *len_nowrap);
ssize_t l_ringbuf_write(struct l_ringbuf *ringbuf, int fd);

size_t l_ringbuf_avail(struct l_ringbuf *ringbuf);
int l_ringbuf_printf(struct l_ringbuf *ringbuf, const char *format, ...)
					__attribute__((format(printf, 2, 3)));
int l_ringbuf_vprintf(struct l_ringbuf *ringbuf, const char *format,
					va_list ap);
ssize_t l_ringbuf_read(struct l_ringbuf *ringbuf, int fd);

#ifdef __cplusplus
}
#endif

#endif /* __ELL_RINGBUF_H */
