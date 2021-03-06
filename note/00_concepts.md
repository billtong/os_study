# Concepts 
## Operating System 
- An Operating System is a Program that acts as an intermediary between a user and the computer hardware. 
## Kernel 
- A program that run all times. A kernel is the core component of an operating system. Using interprocess communication and system calls, it acts as a bridge between applications and the data processing performed at the hardware level. 
## Trap 
- A trap is an exception in a user process. It's caused by division by zero or invalid memory access. It's also the usual way to invoke a kernel routine (a system call) because those run with a higher priority than user code. Handling is synchronous (so the user code is suspended and continues afterwards).  
## Interrupts 
- An interrupt is a function of an operating system that provides multi-process multi-tasking. The interrupt is a signal that prompts the operating system to stop work on one process and start work on another. 
- An interrupt is something generated by the hardware (devices like the hard disk, graphics card, I/O ports, etc). These are asynchronous (i.e. they don't happen at predictable places in the user code) or "passive" since the interrupt handler has to wait for them to happen eventually. 
## Cache 
- Cache is a buffer between the CPU and main memory. 
## Process 
- A process is the unit of work in a system. 
- (A process is the instance of a computer program that is being executed by one or many threads. It contains the program code and its activity. Depending on the operating system, a process may be made up of multiple threads of execution that execute instructions concurrently.) 
## Thread 
- A thread is a basic unit of CPU utilization; it comprises a thread ID, a program counter, a register set, and a stack. It shares with other threads belonging to the same process its code section, data section, and other operating-system resources,suchasopenﬁlesandsignals.Atraditional(orheavyweight)process has a single thread of control. If a process has multiple threads of control, it can perform more than one task at a time. 
## Progress 
- Progress is : If no process is executing in its critical section and some processes wish to enter their critical sections, then only those processes that are not executing in their remainder section can participate in deciding which will enter its critical section next, and this selection cannot be postponed indefinitely. 
## Bounded Wait 
- Bounded waiting is : There exists a bound, or limit, on the number of times other processes are allowed to enter their critical sections after a process has made request to enter its critical section and before that request is granted. 
## Mutual Exclusion 
- A mutual exclusion (mutex) is a program object that prevents simultaneous access to a shared resource. This concept is used in concurrent programming with a critical section, a piece of code in which processes or threads access a shared resource. 
- Mutual exclusion: At least one resource must be held in a non-shareable mode. (dead lock) 
## Critical Section 
- A Critical Section is a code segment that accesses shared variables and has to be executed as an atomic action. It means that in a group of cooperating processes, at a given point of time, only one process must be executing its critical section. 
- ( Each process has a segment of code, called a critical section, in which the process may be changing common variables, updating a table, writing a ﬁle, and so on.) 
## Semaphore 
- In computer science, a semaphore is a variable or abstract data type used to control access to a common resource by multiple processes in a concurrent system such as a multitasking operating system. 
## Process Control Block (PCB) 
- Process Control Block is a data structure in the operating system kernel containing the information needed to manage the scheduling of a particular process. The PCB is "the manifestation of a process in an operating system. 
## Mode 
### User Mode 
- User mode is restricted from accessing hardware directly. This is where all user applications are executed.  
### Kernel Mode 
- The kernel mode has direct access to hardware and maintains control over all resources and the system itself. The central or core elements of the operating system are part of the kernel mode. 
- (These two modes correspond to the theory or concept of protection rings for an operating system. Kernel mode represents RING 0, which has the highest level of access and controls the environment. User mode represents RING 3, which is the lowest level of access and which must request access to resources from the lower numbered levels. The levels are exactly the same for Windows 2000.) 