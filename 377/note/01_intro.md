# Introduction
## Operating Systems
- General Defination:
    - A program acts as an intermediary between an user of a computer and the computer hardware.
- Purpose:
    - execute programs by user (purpose)
    - use the computer system conveniently (primary goal)
    - use the computer hardware in an efficient manner (secondary goal)  
## What is an Operating System
- Resource Allocator
    - manage and allocate resources efficently and fairly
    - provid a uniform interface to similar hardware
- Control Program
    - control the execution of user programs
    - control operation of I/O devices
- Kernel
    - one program running at all times on computer
    - IPL inital program load
## The development of Operating System
### Early System
- large amount of set-up time in involved in the running of a job.
### Single Program Systems(Early Batch Mainframe Systems)
- pool of jobs each run sequentially
- single process at a time
- CPU is idle while waiting for mechanical I/O devices operation. (wasted cycles)
- minimal hardware/OS requirements
### Multiprogram Systems (Later Batch Mainframe Systems)
- more than one program in memory at a time
- when one program is doing I/O, another gets the CPU (eliminate wasted cycles)
- more hardware/OS requirements
    - OS provides I/O routines
    - memory management and security
    - CPU scheduling
    - device allocation
### Time Sharing/Interactive Systems
- CPU is shared between several programs kept in memory
- programs are swapped between disk and memory, sometimes only parts of programs are swapped
- usually more than one user at a time
- more hardware/OS requirements
    - communication with user (terminal, WIMP)
    - scheduling differences from batch multiprocessing
### Parallel Systems (tghtly coupled systems)
- more than one processor in close communication, sharing the computer bus, the clock, and sometimes memory and peripheral devices.
- advatages
    - increased throughput
    - cheaper
    - increase reliability, the failure of one precessor will not halt the system, but only slow it down
- symmetric multiprocessing system
    - each processor identical, process run on whatever processor is available (may run on more than one during it's lifetime)
- asymmetric multiprocessing system
    - master-slave/back/frond-end relationship
### Distributed Systems (loosely coupled)
- each processor has its own local memory, and they communicate with one another through various communication lines(high speed bus, telephone lines)
- advantages
    - resource sharing
    - computation speedup
    - reliability
    - communication
### Real-Time Systems
- a real-time system is used when there are rigid time requirements on the operation of a processor or the flow of data, and thus is often used as a control devices in a dedicated application.
- has well-defined, fixed time constraints. a process must be done within the defined constraints.
- Hard real-time system
    - guarantees that critical tasks complete on time
- Soft real-time system
    - a missed deadline does not mean system failure, but value of result decreases with time (real time video, virtual reality)
    - a critical real-time task gets priority over other atsks, and retains that priority until it completes
