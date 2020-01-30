/*
    Author: Bill Tong
-*/

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define FILENAME "/proc/Lab2"

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
    char line[256];
    // read the number of seconds from the /proc file
    while (fgets(line, sizeof(line), stream)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        printf("%s", line); 
    }
    
    fclose(stream);
    
    return 0;
}
