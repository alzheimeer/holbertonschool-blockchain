CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu90 -ggdb3 -c -I. -Itransaction/ -Iprovided/ -I../../crypto -L../../crypto -lhblk_crypto -lllist -lssl -lcrypto -pthread

SRC0 = $(wildcard *.c) $(wildcard transaction/*.c) $(wildcard provided/*.c)
OBJ0 = $(SRC0:.c=.o)
NAME0 = libhblk_blockchain.a

.PHONY: clean oclean flcean libhblk_blockchain.a

clean:
	$(RM) *~ $(NAME0)

oclean:
	$(RM) $(OBJ0)

fclean: clean oclean

libhblk_blockchain.a: blockchain.h transaction/transaction.h $(OBJ0)
	ar rcs $(NAME0) $(OBJ0)
