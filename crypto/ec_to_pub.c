#include "hblk_crypto.h"

/**
 * ec_to_pub - extracts the public key from an EC_KEY opaque structure
 * @key: pointer to the EC_KEY structure
 * @pub: address at which to store the extracted public key
 * Return: public key from an EC_KEY opaque structure, NULL otherwise
 */
uint8_t *ec_to_pub(EC_KEY const *key, uint8_t pub[EC_PUB_LEN])
{
	const EC_GROUP *group = NULL;
	const EC_POINT *point = NULL;

	if (!key || !pub)
		return (NULL);
	/*Get the curve of the key*/
	group = EC_KEY_get0_group(key);
	/*Get the point of the key curve*/
	point = EC_KEY_get0_public_key(key);
	/*Set the public key in the pub variable (extract the public key in octact)*/
	if (!EC_POINT_point2oct(group, point, POINT_CONVERSION_UNCOMPRESSED,
		pub, EC_PUB_LEN, NULL))
		return (NULL);
	return (pub);
}
