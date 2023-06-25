CC=gcc
CFLAGS=-I.
DEPS = functions.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

hangman: hangman.o
	gcc -o hangman hangman.o -I.

clean:
	rm -f *.o hangman
