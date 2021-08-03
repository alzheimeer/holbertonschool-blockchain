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
	block_t *new_block = NULL;
	int i = 0;

	new_block = calloc(1, sizeof(block_t));
	if (new_block == NULL)
		return (NULL);
	new_block->info.index = (prev->info).index + 1;
	new_block->info.difficulty = 0;
	new_block->info.timestamp = time(NULL);
	new_block->info.nonce = 0;
	for (i = 0; i < 32; i++)
		(new_block->info.prev_hash)[i] = (prev->hash)[i];
	new_block->data.len = SET_MAX_LEN(data_len, BLOCKCHAIN_DATA_MAX);
	memcpy(new_block->data.buffer, data, new_block->data.len);
	return (new_block);
}
