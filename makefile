CC=gcc
CFLAGS=-std=c99 -Wall -pedantic -g

Queues : queue_client.o linked_list_2.o
	${CC} ${CFLAGS} -o $@ $^

Stacks : stack_client.o linked_list.o
	${CC} ${CFLAGS} -o $@ $^

Structs : Structs_A Structs_L Structs_L2 Structs_D

Structs_A : structs.o dynamic_array.o array_helpers.o
	${CC} ${CFLAGS} -o $@ $^

Structs_L : structs.o linked_list.o
	${CC} ${CFLAGS} -o $@ $^

Structs_L2 : structs.o linked_list_2.o
	${CC} ${CFLAGS} -o $@ $^

Structs_D : structs.o double_linked_list.o
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

structs.o : structs.c array_helpers.h

queue_client.o : queue_client.c queue.h

stack_client.o : stack_client.c stack.h

array_helpers.o : array_helpers.c array_helpers.h

dynamic_array.o : dynamic_array.c dynamic_array.h array_helpers.o

resizing_array.o : resizing_array.c list.h

linked_list.o : linked_list.c list.h

linked_list_2.o : linked_list_2.c list.h

mem_free.o : mem_free.c array_helpers.o

stackvars.o : stackvars.c array_initializers.o

array_initializers.o : array_initializers.c array_initializers.h

# all: Structs Resizer Memfree Pointers Arraymedian Stackvars ListDemoA ListDemoB

clean:
	rm -f *.o
