#include "transaction.h"

/**
 * tx_in_sign - signs transaction input
 * @in: tx input struct to sign
 * @tx_id: id of transaction containing @in
 * @sender: private key of tx receiver
 * @all_unspent: list of unspent tx outputs to date
 * Return: pointer to resulting sig struct or null
 */
sig_t *tx_in_sign(tx_in_t *in, uint8_t const tx_id[SHA256_DIGEST_LENGTH],
	EC_KEY const *sender, llist_t *all_unspent)
{
	uint8_t pub[EC_PUB_LEN];
	ssize_t i;
	unspent_tx_out_t *utx;

	for (i = 0; i < llist_size(all_unspent); i++)
	{
		utx = llist_get_node_at(all_unspent, i);
		if (!memcmp(in->tx_out_hash, utx->out.hash, SHA256_DIGEST_LENGTH))
			break;
		utx = NULL;
	}

	if (!utx || !ec_to_pub(sender, pub) || memcmp(pub, utx->out.pub, EC_PUB_LEN))
		return (NULL);
	if (!ec_sign(sender, tx_id, SHA256_DIGEST_LENGTH, &in->sig))
		return (NULL);

	return (&in->sig);
}
