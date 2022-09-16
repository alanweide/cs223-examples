CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g

Pointers : pointers.c array_initializers.c array_helpers.c
	${CC} -o $@ ${CFLAGS} $^

ArrayMedian : array_median.c array_initializers.c array_helpers.c
	${CC} -o $@ ${CFLAGS} $^

Stackvars : stackvars.c array_initializers.c
	${CC} -o $@ ${CFLAGS} $^

Live :
	rm -f $@
	${CC} -o $@ ${CFLAGS} $^
	./$@

clean:
	rm -f Pointers ArrayMedian Stackvars
