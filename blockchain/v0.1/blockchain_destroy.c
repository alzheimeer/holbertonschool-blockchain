#include "blockchain.h"

/**
 * blockchain_destroy - frees an entire chain of blocks
 * @blockchain: pointer to chain struct
 */
void blockchain_destroy(blockchain_t *blockchain)
{
	block_t *node = NULL;

	for (node = llist_pop(blockchain->chain); node != NULL;
			node = llist_pop(blockchain->chain))
		block_destroy(node);
	llist_destroy(blockchain->chain, 0, NULL);
	free(blockchain);
}
