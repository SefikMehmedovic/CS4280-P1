#makefile for P1

all: *.c
	gcc -g -Wall -o scanner *.c

clean:
	$(RM) scanner
