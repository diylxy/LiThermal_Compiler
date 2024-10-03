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

#ifndef __ELL_GENL_H
#define __ELL_GENL_H

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

struct l_genl;
struct l_genl_family;
struct l_genl_msg;

typedef void (*l_genl_destroy_func_t)(void *user_data);
typedef void (*l_genl_debug_func_t)(const char *str, void *user_data);
typedef void (*l_genl_watch_func_t)(void *user_data);
typedef void (*l_genl_msg_func_t)(struct l_genl_msg *msg, void *user_data);

struct l_genl *l_genl_new(int fd);
struct l_genl *l_genl_new_default(void);

struct l_genl *l_genl_ref(struct l_genl *genl);
void l_genl_unref(struct l_genl *genl);

bool l_genl_set_debug(struct l_genl *genl, l_genl_debug_func_t callback,
				void *user_data, l_genl_destroy_func_t destroy);

bool l_genl_set_close_on_unref(struct l_genl *genl, bool do_close);

struct l_genl_attr {
	struct l_genl_msg *msg;
	const void *data;
	uint32_t len;
	const void *next_data;
	uint32_t next_len;
};

struct l_genl_msg* l_genl_msg_new(uint8_t cmd);
struct l_genl_msg *l_genl_msg_new_sized(uint8_t cmd, uint32_t size);

struct l_genl_msg *l_genl_msg_ref(struct l_genl_msg *msg);
void l_genl_msg_unref(struct l_genl_msg *msg);

uint8_t l_genl_msg_get_command(struct l_genl_msg *msg);
uint8_t l_genl_msg_get_version(struct l_genl_msg *msg);
int l_genl_msg_get_error(struct l_genl_msg *msg);

bool l_genl_msg_append_attr(struct l_genl_msg *msg, uint16_t type,
					uint16_t len, const void *data);
bool l_genl_msg_append_attrv(struct l_genl_msg *msg, uint16_t type,
				const struct iovec *iov, size_t iov_len);
bool l_genl_msg_enter_nested(struct l_genl_msg *msg, uint16_t type);
bool l_genl_msg_leave_nested(struct l_genl_msg *msg);

bool l_genl_attr_init(struct l_genl_attr *attr, struct l_genl_msg *msg);
bool l_genl_attr_next(struct l_genl_attr *attr, uint16_t *type,
					uint16_t *len, const void **data);
bool l_genl_attr_recurse(struct l_genl_attr *attr, struct l_genl_attr *nested);

struct l_genl_family *l_genl_family_new(struct l_genl *genl, const char *name);

struct l_genl_family *l_genl_family_ref(struct l_genl_family *family);
void l_genl_family_unref(struct l_genl_family *family);

bool l_genl_family_set_unicast_handler(struct l_genl_family *family,
						l_genl_msg_func_t handler,
						void *user_data,
						l_genl_destroy_func_t destroy);

bool l_genl_family_set_watches(struct l_genl_family *family,
				l_genl_watch_func_t appeared,
				l_genl_watch_func_t vanished,
				void *user_data, l_genl_destroy_func_t destroy);

uint32_t l_genl_family_get_version(struct l_genl_family *family);
struct l_genl *l_genl_family_get_genl(struct l_genl_family *family);

bool l_genl_family_can_send(struct l_genl_family *family, uint8_t cmd);
bool l_genl_family_can_dump(struct l_genl_family *family, uint8_t cmd);
unsigned int l_genl_family_send(struct l_genl_family *family,
				struct l_genl_msg *msg,
				l_genl_msg_func_t callback,
				void *user_data,
				l_genl_destroy_func_t destroy);
unsigned int l_genl_family_dump(struct l_genl_family *family,
				struct l_genl_msg *msg,
				l_genl_msg_func_t callback,
				void *user_data,
				l_genl_destroy_func_t destroy);
bool l_genl_family_cancel(struct l_genl_family *family, unsigned int id);

bool l_genl_family_has_group(struct l_genl_family *family, const char *group);
unsigned int l_genl_family_register(struct l_genl_family *family,
				const char *group, l_genl_msg_func_t callback,
				void *user_data, l_genl_destroy_func_t destroy);
bool l_genl_family_unregister(struct l_genl_family *family, unsigned int id);

#ifdef __cplusplus
}
#endif

#endif /* __ELL_GENL_H */
