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

#ifndef __ELL_PKCS5_H
#define __ELL_PKCS5_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <stdint.h>

bool l_pkcs5_pbkdf1(enum l_checksum_type type, const char *password,
			const uint8_t *salt, size_t salt_len,
			unsigned int iter_count,
			uint8_t *out_dk, size_t dk_len);

bool l_pkcs5_pbkdf2(enum l_checksum_type type, const char *password,
			const uint8_t *salt, size_t salt_len,
			unsigned int iter_count,
			uint8_t *out_dk, size_t dk_len);

#ifdef __cplusplus
}
#endif

#endif /* __ELL_PKCS5_H */
