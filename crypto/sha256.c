#include "hblk_crypto.h"

/**
 * sha256 - gets SHA256 hash of a "sequence of bytes " or string
 * @s: the string to encode
 * @len: length of string
 * @digest:  The resulting hash must be stored in digest
 * Return: pointer to digest else "if digest is NULL return NULL"
 * You are not allowed to allocate memory dynamically
 */
uint8_t *sha256(int8_t const *s, size_t len,
	uint8_t digest[SHA256_DIGEST_LENGTH])
{
	if (!s || !digest)
		return (NULL);
	return (SHA256((const unsigned char *)s, len, digest));
}
