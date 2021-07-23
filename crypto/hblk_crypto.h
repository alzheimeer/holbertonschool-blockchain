#ifndef HBLK_CRYPTO
#define HBLK_CRYPTO

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>
#include <sys/types.h>

#include <openssl/sha.h>
#include <openssl/ec.h>
#include <openssl/evp.h>
#include <openssl/bio.h>
#include <openssl/err.h>
#include <openssl/ssl.h>
#include <openssl/pem.h>

/* task0 */
#define SIG_MAX_LEN    72
/* task1 */
#define EC_CURVE   NID_secp256k1

/* task0 */
uint8_t *sha256(int8_t const *s, size_t len,
	uint8_t digest[SHA256_DIGEST_LENGTH]);
/* task1 */	
EC_KEY *ec_create(void);

#endif
