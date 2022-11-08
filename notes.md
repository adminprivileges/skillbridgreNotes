## x200
- add newlines at the end of your code, its the standards and ```#includes``` can get a bit messy if you dont since the code is prepended to the beginning EXACTLY as it is. 
- When the filename for a #include is surrounded by < and >, the compiler looks for this file in standard include paths, such as /usr/include/. If the filename is surrounded by quotes, the compiler looks in the current directory.
- always terminate statements with a ```;```
- strings are just character arrays, to avoid having to add them one at a time, use strcpy ex ```strcpy([var], "Hello World!");```
- ```&``` Specifies address of
- ```*``` Indicates a pointer
- Using printf you can include variables into print strings when using format strings which will dictate how theyre printed ex ```printf("Include example variable here: %s", [variable])```
    - ```%d``` Decimal
    - ```%u``` Unsigned decimal
    - ```%x``` Hexadecimal
    - ```%s``` String
    - ```%n``` Number of bytes written so far
    - ```%p```  Memory Address
- You can pad a number with 0s by prepending a format string with a number ex ```03%d```
- When taking user input the ```scanf``` tool can only take pointers so make sure to use the ```&``` operator ex: ```scanf(%s, &[variable])```
- You can temporarily change a varable datatype by typecasting ex: ```(float) [variable]```
    - Make sure to include an ```*``` after the type if youre typecasting a pointer because youre saying its a pointer to this var ex ```(int*) [pointer_variable]``` [ref](https://ecomputernotes.com/what-is-c/function-a-pointer/type-casting-of-pointers)

    - Doing arithmetic on typecasted pointers is a bad idea unless you change it to the expected value first and then back to its typecasted self ex: ```int_pointer = (char *) ((int *) int_pointer + 1)```
        - void pointers must be typecasted before arithmetic
        - void pointers cant be de-referenced
- static variables preserve their values even when out of scope ex:
```
#include <stdio.h>

int function()
{
    static int count = 0;
    count++;
    return count;
}

void main(){
    print("%d", function);
    print("%d", function);
}
// will output 1 2 instead of 1 1
```
- Four common functions that use file descriptors 
  - ```open()```: Opens a file and returns file descriptor
    - requires ```<fcntl.h>``` and ```<sys/stat.h>``` to be included to use flags
    - Open flags include:
      - ```O_RDONLY``` Open file for read-only access.
      - ```O_WRONLY``` Open file for write-only access.
      - ```O_RDWR``` Open file for both read and write access.
      - ```O_APPEND``` Write data at the end of the file.
      - ```O_TRUNC``` If the file already exists, truncate the file to 0 length.
      - ```O_CREAT``` Create the file if it doesn't exist.
        - ```S_IRUSR``` Give the file read permission for the user (owner).
        - ```S_IWUSR``` Give the file write permission for the user (owner).
        - ```S_IXUSR``` Give the file execute permission for the user (owner).
        - ```S_IRGRP``` Give the file read permission for the group.
        - ```S_IWGRP``` Give the file write permission for the group.
        - ```S_IXGRP``` Give the file execute permission for the group.
        - ```S_IROTH``` Give the file read permission for other (anyone).
        - ```S_IWOTH``` Give the file write permission for other (anyone).
        - ```S_IXOTH``` Give the file execute permission for other (anyone).
  - ```close()```: fd is the only arg
  - ```read()```: 
  - ```write()```: combine with int (usually ```strlen``` to know how much to write) 
  - Structs are kind of like classes in that they can hold multiple variables which can be held by a struct and referenced as such. Theres 3 different ways to access elements in a struct
    - The sensible way (Direct access): ```[Struct].[element]```
    - Via a pointer to the struct (arrow operator): ```[pointer]->[element]```
    - Typecasting the pointer then dereferencing the value out (assuming you know how the data is store in memory): ```*((int *) [pointer])```
    - if you want to grab user input but you also need spaces you can use a scanset char ```[]``` which says "read only" the trick is to combine with a not operator ```^``` to make it act as"read until" ex:  ```scanf("%[^\n]s", [variable])``` this will take all user input until a newline is sent into one string.   
  - You can use the ```#define``` directive to set global constants
  


- Assembly is syntax formatted ```operation, [destination], [source]``` 
- There are two major syntaxes for assembly, AT&T and Intel (Intel is a lot cleaner)
    - To set GDB to intel 
        ```
        > gdb -q
        > set dis intel
        > quit
        > echo "set dis intel" > ~/.gdbinit
        ```
- The ```-g``` flag can be used by gcc to include extra debugging information, which will give GDB access to the source code.
- Registers
    - ```EAX``` (Accumulator regiSster): It is used for I/O port access, arithmetic, interrupt calls, etc
    - ```EBX``` (Base register): It is used as a base pointer for memory access. Gets some interrupt return values
    - ```ECX``` (Counter register): It is used as a loop counter and for shifts. Gets some interrupt values
    - ```EDX``` (Data register): It is used for I/O port access, arithmetic, some interrupt calls.
    - ```EDI``` (Destination index):Used for string, memory array copying and setting and for far pointer addressing with EDI
    - ```ESI``` (Source index): Used for string and memory array copying
    - ```EBP``` (Stack Base pointer): Holds the base address of the stack
    - ```ESP``` (Stack pointer): Holds the top address of the stack
    - ```EIP``` (Index Pointer): Holds the offset of the next instruction. It can only be read 

- x86 processor values are stored in little-endian (least sig byte first) byte order which means the byte values ```0xc7    0x45    0xfc    0x00``` would be stored in a word as ```0x00fc45c7```
- GDB examination syntax ```x/[number(opt, default=1)][format][size(opt, default=word)] [target]``` ex: ```x/2xb $eip```
    - format:
        - ```o``` Display in octal.
        - ```x``` Display in hexadecimal.
        - ```u``` Display in unsigned, standard base-10 decimal.
        - ```t``` Display in binary.
        - ```i``` Display instruction
        - ```c``` Diplay character (should prolly use with b size)
        - ```s``` Display string
    - size
        - ```b``` A single byte
        - ```h``` A halfword, which is two bytes in size
        - ```w``` A word, which is four bytes in size
        - ```g``` A giant, which is eight bytes in size
- ```bt``` (Backtrace) will show you a the stack or istory of functions, ```bf ful```will show you variables as well.

- Compiled program memory is broken into 5 segments:
    - **Text:** (Code Segment), where the assembly instructions are located. 
        - Read Only

    - **Data:** used to store initialized global and static variables
        - Writable, but fixed in size
    - **BSS:**  used for uninitialized g&s variables
        - Writable, but fixed in size
    - **Heap:** directly controlled by the programmer, writes downward towards higher memory addresses
    - **Stack:** used to store local function variables and context during function calls (what ```bt``` looks at) grows upards towards lower memory
- When a function is called a stack frame is pushed to the stack [Check out this youtube video](https://www.youtube.com/watch?v=vcfQVwtoyHY&list=PL_9C1QR5FDr2GZVhwajY_uWUPzkzCPMeK). 
    - frame contains function parameters, its local variables and the: 
        - SFP (saved frame pointer), used to restore EIP to previous value
        - return address, used to restore EIP to the next inst after the function call
![Stack](https://learning.oreilly.com/api/v2/epubs/urn:orm:book:9781593271442/files/httpatomoreillycomsourcenostarchimages254229.png.jpg)
    - when going from main to funct
        - parameters are added to the ESP
        - Main ebp becomes SFP
        - funct EBP sits between SFP and return address
        - next instruction becomes return address
        - variables are added on top of funct ebp 
- ```malloc()``` and ```free()``` are used to allocate and deallocate space in the heap respectively
    - malloc returns a pointer with the datatype void so it must be typecasted to its expected type
- use ```atoi()``` (ASCII to INT) to change character type to int


# GDB Notes    - To set GDB to intel 
- Run ```gdb -q``` to skip the copyright message
- ```-`args``` allows you to include arguments
- To set GDB to intel
    ```
    > gdb -q
    > set dis intel
    > quit
    > echo "set dis intel" > ~/.gdbinit
    ```
- Commands
  - ```nexti``` - Next Assembly Instruction
  - ```r [opt_argument]``` or ```run [opt_argument]``` - Start or restart the program
  - ```c``` or ```continue``` - Continue to the next breakpoint
  - ```b```  or ```break``` - Set breakpoint
    - ```info b``` - inspect breakpoints
    -  ```disable/enable b [breakSSpoint_number]``` - disable/enable a set breakpoint
    - ```delete [breakpoint_number]``` - delete breakpoint
   -  ```p [variable]``` or ```print [variable]``` - print a variable or register
   - ```set [variable]``` - set the value of a variable inline  
   - ```bt```- backtraces the stack from the current point in execution
 -  TUI (Terminal User Interface) - a curses text interface to make gdb more usable
    -  ```CTRL+X+A``` - Enter/Exit TUI
    -  ```CTRL+L``` Reload display
    -  ```layout [name]``` enters one of the specified layouts
       -  ```asm``` - assembly
       -  ```regs``` - registers
       -  ```src``` - source code
    -  ```focus [layout]``` - change your cursor focus
       -  ```focus cmd``` - move cursor back to gdb command line
 -  ```CTRL+X+O``` - switch focus


# Assembly
- Assembly is syntax formatted ```operation, [destination], [source]``` 
- There are two major syntaxes for assembly, AT&T and Intel (Intel is a lot cleaner)
    - To set GDB to intel 
        ```
        > gdb -q
        > set dis intel
        > quit
        > echo "set dis intel" > ~/.gdbinit
        ```
- The ```-g``` flag can be used by gcc to include extra debugging information, which will give GDB access to the source code.
- Registers
    - ```EAX``` (Accumulator regiSster): It is used for I/O port access, arithmetic, interrupt calls, etc
    - ```EBX``` (Base register): It is used as a base pointer for memory access. Gets some interrupt return values
    - ```ECX``` (Counter register): It is used as a loop counter and for shifts. Gets some interrupt values
    - ```EDX``` (Data register): It is used for I/O port access, arithmetic, some interrupt calls.
    - ```EDI``` (Destination index):Used for string, memory array copying and setting and for far pointer addressing with EDI
    - ```ESI``` (Source index): Used for string and memory array copying
    - ```EBP``` (Stack Base pointer): Holds the base address of the stack
    - ```ESP``` (Stack pointer): Holds the top address of the stack
    - ```EIP``` (Index Pointer): Holds the offset of the next instruction. It can only be read 

- x86 processor values are stored in little-endian (least sig byte first) byte order which means the byte values ```0xc7    0x45    0xfc    0x00``` would be stored in a word as ```0x00fc45c7```
- GDB examination syntax ```x/[number(opt, default=1)][format][size(opt, default=word)] [target]``` ex: ```x/2xb $eip```
    - format:
        - ```o``` Display in octal.
        - ```x``` Display in hexadecimal.
        - ```u``` Display in unsigned, standard base-10 decimal.
        - ```t``` Display in binary.
        - ```i``` Display instruction
        - ```c``` Diplay character (should prolly use with b size)
        - ```s``` Display string
    - size
        - ```b``` A single byte
        - ```h``` A halfword, which is two bytes in size
        - ```w``` A word, which is four bytes in size
        - ```g``` A giant, which is eight bytes in size
- ```bt``` (Backtrace) will show you a the stack or istory of functions, ```bf ful```will show you variables as well.

## x400
## Networking
- There are two kinds of sockets
  - Stream Sockets: Used for TCP
  - Datagram Sockets: Used for TCP
- A socket behaves a lot like a file descriptor, and can be interacted with using ```read()```  and ```write()``` a the prototype of a socket looks like this:
  - ```socket(int domain, int type, int protocol)```
    - ```domain``` - protocol family of the socket (ex: ```pf_inet, pf_ax25```)
    - ```type``` - type of socket (ex: ```sock_stream, sock_dgram```)
    - ```protocol``` - choose a protocol within the family (most families only have 1 so this is usually set to ```0```)
  - ```SOCKADDR_COMMON``` is an unsigned int used to represent the family of addresses along with the rest of the strcture for its saved data 
  - The port number and IP in ```AF_INET``` are expected to be in big endian (regardless of architecture) and there are functions that can be used to convert this such as ```htonl``` (Host to network long)
  - 