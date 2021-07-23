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

/* Maximum signature octet string length (using 256-bit curve) Task 0*/
#define SIG_MAX_LEN    72
/* Task 1 */
#define EC_CURVE   NID_secp256k1
/* EC_KEY public key octet string length (using 256-bit curve) Task 2*/
#define EC_PUB_LEN 65

uint8_t *sha256(int8_t const *s, size_t len,
	uint8_t digest[SHA256_DIGEST_LENGTH]);
EC_KEY *ec_create(void);
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN]);
EC_KEY *ec_from_pub(uint8_t const pub[EC_PUB_LEN]);

#endif
