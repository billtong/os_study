# Memory Management
## Static Linking vs Dynamic Loading vs Dynamic Linking
- dynamic loading, a routine is not loaded until it is called.
- static linking is when the all of the modules including system libraries are linked together at compile time.
- dynamic linking, provides stubs for each routine.
## Overlays
to keep in memory only those instructions and data that are needed at any given time. When other instructions are needed, they are loaded into space that was occupied previously by instructions that are no longer needed.
## Swapping
- processes can be `swapped` temporarily out of memory to be a backing store, and then brought back into memory for continued execution in order to make room for higher priority processes
- if memory binding is not exection time, then process must be swapped back into same place in memory
## Physical vs Logical Management
- logical address, address gerated by CPU, also known as virtual address
- physical address, location in physical memory
- logical and physical address are the same in compile and load time address binding. They differ in execution time binding
- user program only deals with logical addresses. It never sees the physical address
- Memory Management Unit(MMU), the hardware that maps virtual to physical address.
## Simple Allocation
to have a `relocation register` that is added to every virtual address. to have a `limit register` storing the size of memory space
## Contiguous Allocation
main memory is divided into two parts: operating system (usually in same part as interrupt vector); user memory (divided among processes)
- fixed size segments
- os keeps list of holes
    - First Fit, use the first hole on the free list that is big enough
    - Best Fit, find the smallest hole that is big enough
    - Worst Fit, find the largest hold
## Fragmentation
- compaction, to shuffle the memory contents to place all free memory together in one large block.
## Paging Structure
Another possible solution to the external fragmentation problem is to permit the physical address space of a process to be noncontiguous, thus allowing a process to be allocated physical memory wherever the latter is available.
- basic method:  
physical memory is brokent into fixed-sized blocks called frames. Logical memory is also broken into blocks of the same size called pages. When a process is to be excuted, its pages are loaded into any available meory frames from the backing store. The backing store is divided into fixed-sized blocks that are of the same size as the memory frames.
- no external fragmentation, but still have internal fragmentation
- frame and page always the same size, with power of 2
### Page Tables
- each process can have its own logical address space, thus each process has its own page table, and mapping to physical memory
- frame table, keeps track of allocated and free frames
- page tables are large, and usually kept in main memory.
### Translation look-aside buffer (TLB)
- use a special, small. fast-loopup hardware cache to minimize extra memory traffic of page tables.
## Shared Pages 
# Virtual Memory
## Concept
## Demand Paging