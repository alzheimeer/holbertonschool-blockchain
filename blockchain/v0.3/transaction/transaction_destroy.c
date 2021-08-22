#include "transaction.h"

/**
 * transaction_destroy - frees tx structure
 * @transaction: tx struct to free
 */
void transaction_destroy(transaction_t *transaction)
{
	if (!transaction)
		return;
	llist_destroy(transaction->inputs, 1, free);
	llist_destroy(transaction->outputs, 1, free);
	free(transaction);
}
