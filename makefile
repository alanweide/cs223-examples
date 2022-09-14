CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g

Pointers: pointers.c array_initializers.c array_helpers.c
	${CC} -o $@ ${CFLAGS} $^

Stackvars: stackvars.c array_initializers.c
	${CC} -o $@ ${CFLAGS} $^

run: Stackvars
	./Stackvars
