CC = gcc
CFLAGS = -std=c99

SRC = main.c log.c note.c init.c
BIN = bnote

$(BIN): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(BIN)

clean:
	rm -f $(BIN)

