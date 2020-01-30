/*
*   Author: Bill Tong
*/

#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/sched.h>

#define PROC_NAME "Lab2"
//#define NR_RUNNING_LOC 0xc03dc3a4
#define NR_THREADS_LOC 0xc038b3a8

static struct task_struct * firstTask, * nextTask;

int my_read(char * page, char **start, off_t file_pos, int count, int *eof,
void*data){
    int numChars;
    if (file_pos == 0) {
        //Write nr_running and nr_threads global variables to the buffer.
        //int *nr_running = (int *)NR_RUNNING_LOC;
        int *nr_threads = (int *)NR_THREADS_LOC;
        numChars = sprintf(page, "Number of running processes: %d\nNumber of threads: %d\nPID\tUID\tNICE\n", nr_running, *nr_threads);
        firstTask = &init_task;
        nextTask = firstTask->next_task;
    } else {
        if(nextTask == NULL) {
            nextTask = init_task.next_task;
        }
        //condition at beginning of list again
        if(nextTask->pid == firstTask->pid) {
            // tell the kernel that there is no more data
            *eof = 1;
            *start=page;
            return 0; 
        }
        //write task info to the buffer 
        if(nextTask->pid != 0) {
            numChars = sprintf(page, "%ld\t%ld\t%ld\n", (long *)nextTask->pid, (long *)nextTask->uid, (long *)nextTask->nice);
        }
        //advance the task pointer 
        nextTask = nextTask->next_task; 
    }
    // tell the kernel that there is still more data
    *eof = 0;
    *start=page;
    // Return the number of characters in the buffer
    return numChars;
}


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
