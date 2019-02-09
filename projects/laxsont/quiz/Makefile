PROG_NAME = testme

CC = gcc
OBJECT_FILES = $(PROG_NAME).o
CFLAGS = -g -Wall -fpic -coverage -lm -std=c99

all: $(PROG_NAME)
	./$(PROG_NAME)

$(PROG_NAME): $(OBJECT_FILES)
	$(CC) $(CFLAGS) -o $@ $(OBJECT_FILES)

$(PROG_NAME).o: $(PROG_NAME).c
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf testme *.o *.dSYM *.gcda *.gcno
