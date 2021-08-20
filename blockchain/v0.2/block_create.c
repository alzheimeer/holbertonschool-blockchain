#include "blockchain.h"

/**
 * block_create - creates a new block in the sequence
 * @prev: pointer to previous block
 * @data: pointer of data to duplicate
 * @data_len: length of data
 * Return: pointer to new block or NULL
 */
block_t *block_create(block_t const *prev, int8_t const *data,
	uint32_t data_len)
{
	block_t *block = calloc(1, sizeof(*block));

	if (!block)
		return (NULL);
	memcpy(&(block->data.buffer), data, MIN(data_len, BLOCKCHAIN_DATA_MAX));
	block->data.len = MIN(data_len, BLOCKCHAIN_DATA_MAX);
	block->info.index = prev->info.index + 1;
	block->info.timestamp = time(NULL);
	memcpy(&(block->info.prev_hash), prev->hash, SHA256_DIGEST_LENGTH);
	return (block);
}
