#include "transaction.h"

/**
 * unspent_tx_out_create - creates unspent transaction struct
 * @block_hash: hash of block containing transaction
 * @tx_id: hash of transaction in block
 * @out: address of transaction output to be copied
 * Return: new unspent transaction struct
 */
unspent_tx_out_t *unspent_tx_out_create(
	uint8_t block_hash[SHA256_DIGEST_LENGTH],
	uint8_t tx_id[SHA256_DIGEST_LENGTH], tx_out_t const *out)
{
	unspent_tx_out_t *utx = calloc(1, sizeof(*utx));

	if (!utx)
		return (NULL);
	memcpy(utx->block_hash, block_hash, sizeof(utx->block_hash));
	memcpy(utx->tx_id, tx_id, sizeof(utx->tx_id));
	memcpy(&utx->out, out, sizeof(utx->out));
	return (utx);
}
