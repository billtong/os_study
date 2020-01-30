/* 	ELEC 377, Lab 3
 *
 * common.c contains routines to be used from both the  producer, and the  consumer
 *   Mutual Exclusion routines will be here
 */

#include <stdio.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <asm/system.h>

#include "common.h"

#define FALSE 0
#define TRUE 1

static struct shared *sharedptr;

/*
    exchange a value between a register and memory
*/
int test_and_set(int * lock){
    return __cmpxchg(lock, 0, 1, 4);
}

// initialize the only mutex once, from the producer... 
void mutexInit(struct shared *memptr){
    sharedptr = memptr;
}

// this should not return until it has mutual exclusion. Note that many versions of 
// this will probobly be running at the same time. 
void getMutex(short pid){
    sharedptr->waiting[pid] = TRUE;
    int key = TRUE;
    while (sharedptr->waiting[pid] && key)
        key = test_and_set(&sharedptr->lock);
    sharedptr->waiting[pid] = FALSE;
}


// set the mutex back to initial state so that somebody else can claim it
void releaseMutex(short pid){
    int j = (pid + 1) % NUMPROCS;
    while (j != pid && !sharedptr->waiting[j])
        j = ( j + 1 ) % NUMPROCS;
    if (pid == j)
        sharedptr->lock = FALSE;
    else 
        sharedptr->waiting[j] = FALSE;
}
