/*+
 *	lab0mod.c - ELEC 377 Demo Module
 *
 *	Demo Lab showing the use of Linux Modules
 *
 *	Return How long OS has been running in a human readable string
 *	through a /proc file
 *
 *	Author: Thomas R. Dean
-*/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>

#define PROC_NAME "Lab0"


/*+
 * my_read: a function that will be called by the kernel when
 *   the user reads the /proc file. In this case, the number
 *   of characters is always less than the size of the buffer,
 *   so we use a simplified version of the /proc api.
 *
 *   Return value: The number of bytes written into the buffer
-*/

int my_read(char * page, char **start, off_t file_pos, int count, int *eof,
void*data){

    int numChars; // number of chars in the buffer
    int seconds;	 // number of seconds since boot

    seconds = (int) (xtime.tv_sec - jiffies / 100);
    numChars = sprintf(page, "%i\n",seconds);

    // tell the kernel that there is no more data
    *eof = 1;

    // Return the number of characters in the buffer
    return numChars;
}


/*+
 * init_module - Called by the kernel to initialize
 *	any data structures used by the module when
 *	the module is loaded. In this case we will
 *	add our file entry to the /proc file system
 *
 * Return value: 0 on success, non-zero for failure
-*/

int init_module() {

    //structure to represent a process directory entry
    struct proc_dir_entry * procentry;

    printk("<> Loading lab0 into the kernel\n");

    // create a proc ntry in the directory
    printk("<> Loading lab0 into the kernel\n");

    // create a proc entry directly in /proc
    procentry = create_proc_entry(PROC_NAME,0444,NULL);
    if (procentry == NULL){
       return -1;
    }
    procentry->read_proc = my_read;
    return 0;
}

/*+
 * cleanup_module - Called by the kernel to deallocate
 *	any data structures used by the module when
 *	the module is removed from the kernel. In our
 *      case we remove the entry from the /proc file system
-*/

void cleanup_module(){
    remove_proc_entry(PROC_NAME, NULL);
    printk("<> lab0 - removed module from the kernel\n");
}
