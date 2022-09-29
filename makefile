CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g

Structs : Structs_A Structs_L Structs_L2

Structs_A : structs.o dynamic_array.o array_helpers.o
	${CC} ${CFLAGS} -o $@ $^

Structs_L : structs.o linked_list.o
	${CC} ${CFLAGS} -o $@ $^

Structs_L2 : structs.o linked_list_2.o
	${CC} ${CFLAGS} -o $@ $^

Resizer : resizing_array.c array_helpers.o
	${CC} ${CFLAGS} -DRES_MAIN -o $@ $^

ListDemoA : listdemo.c resizing_array.o array_helpers.o
	${CC} ${CFLAGS} -o $@ $^

ListDemoB : listdemo.c linked_list.o
	${CC} ${CFLAGS} -o $@ $^

Memfree : mem_free.o array_helpers.o
	${CC} ${CFLAGS} -o $@ $^

Pointers : pointers.o array_initializers.o array_helpers.o
	${CC} ${CFLAGS} -o $@ $^

Arraymedian : array_median.c array_initializers.o array_helpers.o
	${CC} ${CFLAGS} -o $@ $^

Stackvars : stackvars.c array_initializers.o
	${CC} ${CFLAGS} -o $@ $^

Live :
	rm -f $@
	${CC} ${CFLAGS} -o $@ $^
	./$@

structs.o : array_helpers.h

array_helpers.o : array_helpers.c array_helpers.h

dynamic_array.o : dynamic_array.c dynamic_array.h array_helpers.o

resizing_array.o : resizing_array.c list.h

linked_list.o : linked_list.c list.h

linked_list_2.o : linked_list_2.c list.h

mem_free.o : mem_free.c array_helpers.o

stackvars.o : stackvars.c array_initializers.o

array_initializers.o : array_initializers.c array_initializers.h

all: Structs Resizer Memfree Pointers Arraymedian Stackvars ListDemoA ListDemoB

clean:
	rm -f Structs Resizer Memfree Pointers Arraymedian Stackvars ListDemoA ListDemoB
	rm -f *.o
