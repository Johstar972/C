# Documentation de GNU Make : https://www.gnu.org/software/make/manual/
# L'option -Wall permet d'indiquer tous les messages d'avertissement

CC = gcc
CFLAGS = -Wall

juryBUT1 : jury.o moyenne.o
		$(CC) -o juryBUT1 jury.o moyenne.o

jury.o : jury.c moyenne.h
		$(CC) -c jury.c $(CFLAGS)

moyenne.o : moyenne.c moyenne.h
		$(CC) -c moyenne.c $(CFLAGS)

clean :
		rm -f juryBUT1 jury.o moyenne.o