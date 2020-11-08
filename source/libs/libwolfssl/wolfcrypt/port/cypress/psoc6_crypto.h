/* psoc6_crypto.h
 *
 * Copyright (C) 2006-2020 wolfSSL Inc.
 *
 * This file is part of wolfSSL.
 *
 * wolfSSL is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * wolfSSL is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1335, USA
 */

#ifndef _PSOC6_CRYPTO_PORT_H_
#define _PSOC6_CRYPTO_PORT_H_

#include <libs/libwolfssl/wolfcrypt/settings.h>
#ifdef USE_FAST_MATH
    #include <libs/libwolfssl/wolfcrypt/tfm.h>
#elif defined WOLFSSL_SP_MATH
    #include <libs/libwolfssl/wolfcrypt/sp_int.h>
#else
    #include <libs/libwolfssl/wolfcrypt/integer.h>
#endif
#include "cy_crypto_core_sha.h"
#include "cy_device_headers.h"
#include "psoc6_02_config.h"
#include "cy_crypto_common.h"
#include "cy_crypto_core.h"

#ifdef WOLFSSL_SHA512
typedef struct wc_Sha512 {
    cy_stc_crypto_sha_state_t hash_state;
    cy_en_crypto_sha_mode_t sha_mode;
    cy_stc_crypto_v2_sha512_buffers_t sha_buffers;
} wc_Sha512;

#define WC_SHA512_TYPE_DEFINED
#include <libs/libwolfssl/wolfcrypt/sha512.h>
#endif

#ifndef NO_SHA256

typedef struct wc_Sha256 {
    cy_stc_crypto_sha_state_t hash_state;
    cy_en_crypto_sha_mode_t sha_mode;
    cy_stc_crypto_v2_sha256_buffers_t sha_buffers;
} wc_Sha256;

#include <libs/libwolfssl/wolfcrypt/sha.h>
#include <libs/libwolfssl/wolfcrypt/sha256.h>
#endif /* !def NO_SHA256 */


#ifdef HAVE_ECC
#include <libs/libwolfssl/wolfcrypt/ecc.h>
int psoc6_ecc_verify_hash_ex(mp_int *r, mp_int *s, const byte* hash,
                    word32 hashlen, int* verif_res, ecc_key* key);
#endif /* HAVE_ECC */

#define PSOC6_CRYPTO_BASE ((CRYPTO_Type*) CRYPTO_BASE)

/* Crypto HW engine initialization */
int psoc6_crypto_port_init(void);

#endif /* _PSOC6_CRYPTO_PORT_H_ */
