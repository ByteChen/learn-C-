.PHOINY:clean all
CC=g++
CFLAGS=-Wall -g
BIN=test_lru_cache
all:$(BIN)
%.o:%.cc
		$(CC) $(CFLAGS) -c $< -o $@
clean:
		rm -f *.o $(BIN)
