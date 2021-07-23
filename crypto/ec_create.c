#include "hblk_crypto.h"

/**
 * ec_create - creates new EC "private/public" key pair
 * Return: pointer to EC_KEY structure or NULL
 * containing both the public and private keys, or NULL upon failure
 * Both the private and the public keys must be generated
 * You have to use the secp256k1 elliptic curve to create the new pair
 */
EC_KEY *ec_create(void)
{
	EC_KEY *key;

	key = EC_KEY_new_by_curve_name(EC_CURVE);
	if (!key)
		return (NULL);
	if (!EC_KEY_generate_key(key))
	{
		EC_KEY_free(key);
		return (NULL);
	}
	return (key);
}
