/*+
 *	lab0user.c - ELEC377 Demo User Module
 *	
 *	This program reads the results produced by our /proc module
 *	and formats it for the user.
 *
 *	Author: Thomas R. Dean
-*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define FILENAME "/proc/Lab0"

int main()
{
    FILE * stream;
    int second;
    time_t sec;

    // open the file
    stream = fopen(FILENAME,"r");

    if (stream == NULL){
	fprintf(stderr,"Could not open %s\n",FILENAME);
	exit(-1);
    }
    // read the number of seconds from the /proc file
    fscanf(stream,"%d",&second);

    // cast it into a time_t

    sec = (time_t) second;

    // Convert to a string and print

    printf("The System was booted at %s\n",ctime(&sec));
    fclose(stream);
    
    return 0;
}
