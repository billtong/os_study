all: consumer meminit producer
common.o: common.h
consumer: consumer.c common.o common.h
	cc -o consumer consumer.c common.o
meminit: meminit.c
	cc -o meminit meminit.c
producer: producer.c common.o common.h
	cc -o producer producer.c common.o
