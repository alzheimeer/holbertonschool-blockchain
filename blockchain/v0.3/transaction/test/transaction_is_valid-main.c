/* Description: Unspent output refered to by transaction input not found  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "transaction.h"

EC_KEY *_ec_load(char const *folder);

/**
 * main - Entry point
 *
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int main(void)
{
	uint8_t block_hash[SHA256_DIGEST_LENGTH];
	uint8_t transaction_id[SHA256_DIGEST_LENGTH];
	tx_out_t *out;
	uint8_t pub[EC_PUB_LEN];
	EC_KEY *sender, *receiver;
	llist_t *all_unspent;
	unspent_tx_out_t *unspent;
	transaction_t *transaction;

	sha256((int8_t *)"Block test", strlen("Block test"), block_hash);
	sha256((int8_t *)"Transaction test", strlen("Transaction test"), transaction_id);

	sender = ec_load("fee");
	receiver = ec_load("foo");
	all_unspent = llist_create(MT_SUPPORT_FALSE);

	out = tx_out_create(500, ec_to_pub(sender, pub));
	unspent = unspent_tx_out_create(block_hash, transaction_id, out);
	llist_add_node(all_unspent, unspent, ADD_NODE_REAR);

	/* Create transaction */
	transaction = transaction_create(sender, receiver, 500, all_unspent);
	if (!transaction)
	{
		printf("Failed to create transaction\n");
		return (EXIT_FAILURE);
	}
	unspent->block_hash[0] +=1;
	if (transaction_is_valid(transaction, all_unspent))
		printf("Transaction valid\n");
	else
		printf("Transaction invalid\n");

	/* Cleanup */
	EC_KEY_free(sender);
	EC_KEY_free(receiver);
	free(out);
	llist_destroy(all_unspent, 1, free);
	return (EXIT_SUCCESS);
}
