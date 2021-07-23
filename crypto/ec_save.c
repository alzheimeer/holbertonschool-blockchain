#include "hblk_crypto.h"

/**
 * ec_save - saves public/private keys in PEM format
 * @key: pointer to EC_KEY struct with key pair
 * @folder: the folder to save, created if need be
 * Return: 1 on success else 0
 */
int ec_save(EC_KEY *key, char const *folder)
{
	FILE *fp;
	char path[256] = {0};

	if (!key || !folder)
		return (0);

	/*Create a folder if not exist*/
	mkdir(folder, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	/*Create the complete path to store the private key*/
	sprintf(path, "%s/" PRI_FILENAME, folder);
	fp = fopen(path, "w");
	if (!fp)
		return (0);
	/*write the private key in the given file*/
	if (!PEM_write_ECPrivateKey(fp, key, NULL, NULL, 0, NULL, NULL))
	{
		fclose(fp);
		return (0);
	}
	fclose(fp);
	/*Create the complete path to store the public key*/
	sprintf(path, "%s/" PUB_FILENAME, folder);
	fp = fopen(path, "w");
	if (!fp)
		return (0);
	/*Open a file descriptor to store the public key*/
	if (!PEM_write_EC_PUBKEY(fp, key))
	{
		fclose(fp);
		return (0);
	}
	fclose(fp);

	return (1);
}
