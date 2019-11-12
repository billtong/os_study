CC=gcc
CFLAGS = -Wall -g

all: test
.o: ctest1.c ctest2.c
	$(CC) $(CFLAGS) -c $^
libctest.a: ctest1.o ctest2.o
	ar -cvq $@ $^
test: prog.c libctest.a
	$(CC) $(CFLAGS) -o $@ $^

.PHONY: clean cleanobj
clean:
	rm *.o *.a test

cleanobj:
	rm *.o