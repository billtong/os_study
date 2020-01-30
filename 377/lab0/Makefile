
all:	lab0mod.o lab0user

lab0mod.o:	lab0mod.c
	cc -c  -Wall -DMODULE -D__KERNEL__ lab0mod.c

lab0user:	lab0user.c
	cc -o lab0user -Wall lab0user.c
