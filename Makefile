
CC=gcc
CFLAGS=-g -Wall
BIN=cash_register

%.o: %.c
	$(CC) $(CFLAGS) -c $^ -o $@

all: $(BIN)

$(BIN): cash_register.o
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -r $(BIN) *.dSYM
