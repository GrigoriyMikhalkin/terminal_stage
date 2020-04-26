CC = gcc
CFLAGS = -lncurses -I$(IDIR)

IDIR = ./include/
SRCDIR = ./src/
SOURCES = $(SRCDIR)*.c

all: clean game

game:
	$(CC) $(SOURCES) $(CFLAGS) -o $@

clean:
	rm -f game
