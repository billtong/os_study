
all:	lab2mod.o lab2user

lab2mod.o:	lab2mod.c
	cc -c  -Wall -DMODULE -D__KERNEL__ lab2mod.c

lab2user:	lab2user.c
	cc -o lab2user -Wall lab2user.c

