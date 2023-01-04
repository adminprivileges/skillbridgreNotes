# Program Optimization
## Generally useful optimizations
- Code Motion: When using a for loop, precompute values outside the loop ex
- Reduction in strength: use less costly operatrions such as replacing multipulcations/divisions with shifts

# reassociated computation



- register renaming unit contains multiple copies of registerf for updates that aide in program branch execution prediction


- vim `2mat ErrorMsg '%80v'`

# Memory Heirarcy
## Random Access Memory (RAM)
- Comes in two types
  - S(tatic)RAM - needs 4-d transisters per but, a lot faster, needs to be refreshed, doesnt need error checking, used for caches
  - D(ynamic)RAM
- Usually volatole
  - ROM(Read Only Memory) were orifinally made during prod w/ no ability to re-write, now you can, used for embeded shit
  - A Bus is a collection of parallel wites that carry control signals

## Locality
- The priciple that programs tend to use data and instructions with addresses near or equal to what they have used recently
  - Temporal Locality - Recently referenced items (like variables) are likely to be accessed again in the near future
  - Spatial Locality - Items with nearby addresses tend to be referenced close in time

## Types of caching misses
- Cold (compulsatory) miss - miss occurs because cache is empty
- Conflict Miss - error in the way data is allocated in the cache causing frequently used data to be overrwritten
- Capacity miss- not enough cache for the working set
- Cache = (S(ets), E(cache lines), B(locks))
  - Direct Mapped Cache: When reading from cache, the address is computed by first locating the set, a tag to try to see if a matching tag exits, if so, we have a hit and can then compute the location using a byte offset 
    - If a miss occurs, the block is evicted and it overwrites the block with the new value
    - You want your block to be large to take advantage of spacial locality, but not too big as to cause your system to be slow
    - allowing more elements in the sets creates less conflict cache misses
  
## Writes 
- because of caching, multiple copies of the same data will exist
  - **Write Hits:**
    - **Write through:** Write immediately to lower memory (very expensive)
    - **write back:** write to cache until the block is up for eviction.
  - **Write Miss:**
    - **Write Allocate:** load into cache, then update the line in cache 
    - **No Write Allocate:** write straight to memory
  - These methods are chosen by the hardware manufacturers
    - Write Through + No Write Allocate
    - Write Back + Write Allocate

## Cache Performance Metrics
- Miss rate: The fraction of memory refrences not found in cache
- Hit time: Time to deliver a line in the cache to the cpu
- Miss Penalty: The additional time to deliver info from a miss 

## Memory Mountain
- Read Throughput: Number of bytes read from memory per second
- Memory Mountain: Measured read throughput as a function of locality. (a way to meaysre memory system performance).

- *Blocked Matrix Multipulcation*
# Linking
- What do linkers do?
  - Symbol Resolution: Programs define symbols (global variables and functions) which are stired in an object file by an assembler. In this step the linker associates each symbol reference with ONE definition
  - Relocation: Merges seperate sections into a single section, updates references to point to their new addresses
- Types of Object Files
  - Relocatable file (.o file): COntains code that can be combined with another to form an executable file
  - executable file (a.out): contains code in a form that can be moved directly into memory and ran
  - Shared Object File(so): A type of reolcatable object file that can be loaded into memory and linked dynamically 
- Linker Symbols
  - Global Symbols (static): Defined by one module and then refrereced by another module
  - External Symbols: Referenced by one module but defined by another
  - Local Symbols: Global varibles that are defined and referenced only within the same module (not the same as local program variables) 
- To resolve possible conflicts, the linker defines strong(procedures and initializes globals) and weak symbols(uninitialized globals)
  - Multiple strong symbols are not allowed
  - given a strong symbol and multiple weaks, linker will chose the strong
  - given multiple weaks, the linker chooses an arbitrary one
- Interpositioning
  - Compile Time: Changing the sorce code to specify linked libraries
  - Link Time: If you have a
  - ccess to the object files, they can add arguments to the linker to change libraries
  - Run Time: Only need the executable, which you redirect dynamic calls to libraries to go to your predefined ones

# Exceptional Control Flow
- Exists at all layers of the computer system
- Lower Leverl
  - Exceptions: Change in control flow in respons eto a system event
- Higher level:
  - Process context switching: implemnted by OS and hardware timer
  - Signals: implemented by OS
  - Nonlocal jumps (`setjmp` and `longjmp`): implemente dby c runtime library.
## Exceptions
- An Exception is a transfer of control to the kernel(exception handler) in response to an event.
  - Asyncronous exception (Interrupt): caused by events external to the processor.
    - Kernels have a timer interrupt that happens every few miliseconds to allow the kernel control over user programs.
  - Syncronous exceptions: caused by events that occur as the result of executing an instruction
    - Traps (intentional): things like system calls.
    - Faults (unintentional): recoverable things like page faults, and gloatin point exceptions
    - Aborts: unintentional and unrecoverable
## Processes
- Process is an instance of a running program
- Processes have two key abstractions
  - Logical flow control: Thanks to contect switching, processes operate as if they have full control of the CPU
  - Private address space: thanks to virtual memory, Each program has its own slice of main memory
- From a programmer perspective, processes have 3 states
  - Running
  - Stopped
  - Terminated
## Process Control
- On error linux system level functions return a -1 and set the global varable `errno` to indicate cause
  - Pls check the return status of every system level function (unless it returns void)
- To do proper error (and efficient) handling you want to do two things.
  - Make an error reporting function:
  ```c
  void unix_error(char *msg){
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(0);
  }
  ```
  - Make a wrapper function for system calls, (this will vary depending on the function and return types)
  ```c
  pid_t Fork(void){
    pid_t pid;

    if((pid = fork()) < 0){
      unix_error("Fork Error");
    }
    return pid;
  }

  pid = Fork()
  ```
- Reaping child processes: WHen a process terminates, it is a zombie that still consumes system resources, it is the job of the parent to "reap" the child using `wait` which tells the kernel to delete the child.
  - If the parent exits without reaping the child it is orphaned and is eventually reaped by `init` (pid 1) 

## Signals
- A signal is a small messgae that notifies a process that an event has occured in the system. 
  - These are a lot like exceptions, except these are handled by the code itself
- A signal is pending if sent but not recieved, these do not stack, it only holds one pending signal each
- a process can block the recipt of some signals
- Processes are organized in heirarchal process groups which can recieve signals
- During context switching, when the kernel changes execution from one process to the next, the first thing it does is a `pnb` which checks for all pending but not blocked processes

- *Guidelines for writing safe handlers*
  - G0: Keep handlers as simple as possible
    - set a global flag and return
  - G1: Call onlu async-signal-safe functions
    - `printf`, `malloc`, and `exit` are not safe.
  - G2: Save and restore `errno` on entry and exit.
    - so other handlers wont overwrite `errno`
  - *G3: protect access to shared data structures by temporarily blocking all signals*
  - G4: Declare global variables as volatile
    - to prevent compiler from storing them in a register 
  - G5: declare global flags as volatile `sig_atomic_t`
    - flags declared this way dont need to be protected like other globals
- Async-Signal-Safety: A function that stores all needed vars on the stack, and is unintterruptable
  - posix garuntees 117 functions as async-signal-safe.
  - write is the only async-signal-safe output function. 

# System I/O
- carraige return, line feed comes from the days of type writers where a new line was done by returning the carraige to the left and feeding a new line of paper
- `strace` is useful for watching the system calls a program does. You can tune it to a specific call like such
  - ```
    strace -e trace=write ./EXE.c
    ```
- Short Counts
  - Short counts can occur in these situations
    - EOF during reads
    - reading text lines from the terminal
    - network sockets
  - Never occur in these situations
    - reading/writing from disk files (except EOF)
    - writing to disk files.
- File metadata is stored in a data structure called stat `man 2 stat`
  - man pages are split into different categories and unix system calls are typically in section 2 
- How does Unix represent open files?
  - Every process has a unique descriptor table
  - Those descriptor tables all point to a shared open file table which will have metadata associated with the current state of the live file such as the position offset and the reference count this table points to a v-node table which has actual metadata about the file itself(from the `stat` struct)
    - If a program forks, that child process will get a copy of the descriptor table with the exact pointers to the open file table, so any changes one makes, the other sees.
      - Note, new opens and closes after the fork will not be shared
- When to use which I/O
  - Standard I/O: When workign with disk or terminal files
  - Unix I/O: Inside signal handlers and rare cases when you need high performance

# Virtual Memory
-  In Physical addressing, memory is accessed via an offset of the entire physical memory structure
-  In Virtual memory adddressing the Memory management unit intercepts memory calls and translates virtual address calls to physical addresses
-  A page table is a data structure in memory that each proccess has to map virtual memory to physical memory
-  Every process has a "working set" which is a set of active virtual pages
   -  If working set < main memory size you get good performance
   -  if sum(working sets) > main memory size then you have thrashing which means pages are swapped continuously killing your performance
-  Virtual memory can be used for memory protection by allocating smaller blocks for addresses (48bits for intel) and using the upper bits for permissions when actually storing on physical memory
- The TLB (translation lookaside buffer) ia s physical cache of page table entries
- TLBs have two levels to be able to hold all the addresses

# Dynamic Memory allocation
- An Allocator maintains heap as a collevtion of variable sized blocks
  - Explicit allocators (C) put the burden of allocating and freeing space to the programmer
  - implicit allocarors free space themselves (garbage collection in python)
- Allocator Implementation issues
  - How do we know how much memory to free given just a pointer.
    1. can be done by inserting a header that keeps teack of the size.
  - How do we keep track of free blocks
    1. using a implicit, sequential list using the headers of allocated and unallocated block sizes as offsets.
    2. using an explicit linked list of the allocated blocks that use extra space to point to the next allocated block
    3. using different "free lists" that indicate the locations of free blocks of different sizes (Segregated lists)
       1. This is the best method in terms of throughput and memory utilization
    4. using a balanced tree with pointers within each free block and the length used as a key.
  - How do we free blocks?
    1. Just remove the "allocated" flag.
       - Can lead to external fragmentation if you dont combine contiguous free blocks
       - This is easy for the next block, but difficult to find the previous block **in constant time** so one solution is to have copy the header to the foot of the block as well
         - This takes up space, this overhead can be eliminated by removing the footer from allocated blocks AND adding an exta bit to the boundary tags of Free bytes to indicate allocation status
  - What do we do with the extra space when allocating a structure that is smaler than the free block it is placed in
  - how do we pick a block to use for allocation
  - how do we reinsert freed block

# Network Programming
