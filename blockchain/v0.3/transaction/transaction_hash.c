#include "transaction.h"

/**
 * hash_inputs - llist action func to hash inputs
 * @node: tx_in_t * struct
 * @idx: index of node
 * @arg: pointer to address to write to
 * Return: 0 if success else 1
 */
int hash_inputs(llist_node_t node, unsigned int idx, void *arg)
{
	memcpy(*(uint8_t **)arg, node, SHA256_DIGEST_LENGTH * 3);
	*(uint8_t **)arg += SHA256_DIGEST_LENGTH * 3;
	return (0);
	(void)idx;
}

/**
 * hash_outputs - llist action func to hash outputs
 * @node: tx_out_t * struct
 * @idx: index of node
 * @arg: pointer to address to write to
 * Return: 0 if success else 1
 */
int hash_outputs(llist_node_t node, unsigned int idx, void *arg)
{
	memcpy(*(uint8_t **)arg, ((tx_out_t *)node)->hash, SHA256_DIGEST_LENGTH);
	*(uint8_t **)arg += SHA256_DIGEST_LENGTH;
	return (0);
	(void)idx;
}

/**
 * transaction_hash - computes hash of given transaction
 * @transaction: pointer to tx to hash
 * @hash_buf: buffer to save hash
 * Return: ptr to buffer or NULL
 */
uint8_t *transaction_hash(transaction_t const *transaction,
	uint8_t hash_buf[SHA256_DIGEST_LENGTH])
{
	ssize_t len;
	uint8_t *_buf, *buf;

	if (!transaction)
		return (NULL);
	len = SHA256_DIGEST_LENGTH * 3 * llist_size(transaction->inputs)
		+ SHA256_DIGEST_LENGTH * llist_size(transaction->outputs);
	_buf = buf = calloc(1, len);
	if (!_buf)
		return (NULL);
	llist_for_each(transaction->inputs, hash_inputs, &buf);
	llist_for_each(transaction->outputs, hash_outputs, &buf);
	if (!sha256((const int8_t *)_buf, len, hash_buf))
		hash_buf = NULL;
	free(_buf);
	return (hash_buf);
}
