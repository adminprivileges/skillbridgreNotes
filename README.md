# Art of Exploitation Notes
## x200 Programming
### C Programming
#### Key concepts/definitions to know:
- **Variables** - An object that can hold data
  - **Constant** - A type of variable that doesn't change
  - **Variable (Data) types**
    - **int** - stores whole numbers (2 or 4 bytes)
    - **float** - stores fractional digits can store up to 7 digits (4 bytes)
    - **char** - store single character (1 byte)
- **Pointers** - A variable that storesthe address of another variable as its value here are some key concepts as they apply to pointers
  - **Dereference/Pointer** (```*```)
    - When used in a declaration ```int* ptr``` it creates a pointer var
    - When used anywhere else is used to dereference (reference the value stored at a pointer location) ex: ```*ptr=10```
  - **Reference** (```&```) - Specifies address of a variable ex ```*ptr=&x```

- **Comments** - Comments are text in your code that do not run but should provide information about the intended use of the code, please use comments or you will forget how you did things, comments are denoted by the double backslash ```\\``` 

- **Control Structures** - Control structures are the statements that dictate the flow of execution of your code they include:
  - [**If, Else**](https://www.w3schools.com/c/c_conditions.php) - These statements dictate a decision that is made based on the result of a certain condition. ex:
    ```c
    if(you_understand_this){
        int gold_star_count = 1
    } 
    else(
        int click_if_else_hyperlink = 1
    )
    ```
    *note: despite what people tell you, use the braces ```{}``` in your if statements even if its only one line*
  - [**While**](https://www.w3schools.com/c/c_while_loop.php) - Keeps looping a block of code until a condition is reached ex:
    ```c
    while(you_dont_understand_this){
        click_while_hyperlink = 1
        you_dont_understand_this = 0
    }
    ```
    *note: always make sure to include something to trip the condition so you can exit the loop*
  - [**For**](https://www.w3schools.com/c/c_for_loop.php) - Used for when you want to execute a code block for a defined number of intervals ex:
    ```c
    for(iterator=0;iterator<5;iterator++){
        print("Printing this line")
    }
    ```
  - [**Break/Continue**](https://www.simplilearn.com/tutorials/cpp-tutorial/break-and-continue-statements-cpp) - Both can be used to exit a loop but the behavior is a bit different for each
    - Break: Stops the entire process of the loop
    - Continue: Only stops the current iteration 
- [**Functions**](https://www.w3schools.com/c/c_functions.php) - Used to perform a repetitive and uniform action multiple times with out rewriting code. The function is comprised of:
  - The prologue which includes function return type, name of function, and parameters ex:
    ```c
    void make_sandwich(char *bread, char *meat, char* cheese){
        //make the sandwich
    }
    ```
    *Note: The ```void``` data type is used in situations like this where you dont expect return data*  
  - The actual code you intent to execute, which should be nested within the brackets ```{}```
  - The return value, which is data you intend to pass back to the calling function. This will be denoted with the ```return``` keyword. *Note: please ensure your return value is the same type as your function prologue* 

<details> 
<summary><strong>Arithmetic operators</strong></summary>
<strong>Arithmetic operators</strong> - Allows you to do mathematical operations on two operators
<table class="tg">
<thead>
<tr>
    <th class="tg-g7sd">Full Expression</th>
    <th class="tg-yla0">Shorthand</th>
    <th class="tg-yla0">Explanation</th>
</tr>
</thead>
<tbody>
<tr>
    <td class="tg-cly1">i = i + 12</td>
    <td class="tg-cly1">i+=12</td>
    <td class="tg-cly1">Add some value to the variable.</td>
</tr>
<tr>
    <td class="tg-cly1">i = i - 12</td>
    <td class="tg-cly1">i-=12</td>
    <td class="tg-cly1">Subtract some value from the variable.</td>
</tr>
<tr>
    <td class="tg-cly1">i = i * 12</td>
    <td class="tg-cly1">i*=12</td>
    <td class="tg-cly1">Multiply some value by the variable.</td>
</tr>
<tr>
    <td class="tg-cly1">i = i / 12</td>
    <td class="tg-cly1">i/=12</td>
    <td class="tg-cly1">Divide some value from the variable.</td>
</tr>
</tbody>
</table>
</details>

<details> 
<summary><strong>Equivalency Operators</strong></summary>
<strong>Equivalency Operators</strong> used to compare two operators ex:
<table class="tg">
<thead>
<tr>
    <th class="tg-g7sd">Condition</th>
    <th class="tg-yla0">Symbol</th>
    <th class="tg-yla0">Example</th>
</tr>
</thead>
<tbody>
<tr>
    <td class="tg-cly1">Less than</td>
    <td class="tg-cly1">&lt;</td>
    <td class="tg-cly1">(a &lt; b)</td>
</tr>
<tr>
    <td class="tg-cly1">Greater than</td>
    <td class="tg-cly1">&gt;</td>
    <td class="tg-cly1">(a &gt; b)</td>
</tr>
<tr>
    <td class="tg-cly1">Less than or equal to</td>
    <td class="tg-cly1">&lt;=</td>
    <td class="tg-cly1">(a &lt;= b)</td>
</tr>
<tr>
    <td class="tg-cly1">Greater than or equal to</td>
    <td class="tg-cly1">&gt;=</td>
    <td class="tg-cly1">(a &gt;= b)</td>
</tr>
<tr>
    <td class="tg-cly1">Equal to</td>
    <td class="tg-cly1">==</td>
    <td class="tg-cly1">(a == b)</td>
</tr>
<tr>
    <td class="tg-cly1">Not equal to</td>
    <td class="tg-cly1">!=</td>
    <td class="tg-cly1">(a != b)</td>
</tr>
</tbody>
</table>
</details>

<details>
    <summary><strong>Logic Operators</strong></summary>
    <strong >Logic Operators</strong> - used to chain together operators
    <table class="tg">
    <thead>
    <tr>
        <th class="tg-g7sd">Condition</th>
        <th class="tg-yla0">Symbol</th>
        <th class="tg-yla0">Example</th>
    </tr>
    </thead>
    <tbody>
    <tr>
        <td class="tg-cly1">Less than</td>
        <td class="tg-cly1">&lt;</td>
        <td class="tg-cly1">(a &lt; b)</td>
    </tr>
    <tr>
        <td class="tg-cly1">Greater than</td>
        <td class="tg-cly1">&gt;</td>
        <td class="tg-cly1">(a &gt; b)</td>
    </tr>
    <tr>
        <td class="tg-cly1">Less than or equal to</td>
        <td class="tg-cly1">&lt;=</td>
        <td class="tg-cly1">(a &lt;= b)</td>
    </tr>
    <tr>
        <td class="tg-cly1">Greater than or equal to</td>
        <td class="tg-cly1">&gt;=</td>
        <td class="tg-cly1">(a &gt;= b)</td>
    </tr>
    <tr>
        <td class="tg-cly1">Equal to</td>
        <td class="tg-cly1">==</td>
        <td class="tg-cly1">(a == b)</td>
    </tr>
    <tr>
        <td class="tg-cly1">Not equal to</td>
        <td class="tg-cly1">!=</td>
        <td class="tg-cly1">(a != b)</td>
    </tr>
    </tbody>
    </table>
    </details>

#### Best Practices 
  - All of the primary functionality should be integrated in the ```main()``` function
  - add newlines at the end of your code to avoid include errors
  - always terminate statements with a ```;```
#### Things to remember
  - When the filename for a #include is surrounded by < and >, the compiler looks for this file in standard include paths, such as /usr/include/. If the filename is surrounded by quotes, the compiler looks in the current directory.
  - strings are just character arrays, to avoid having to add them one at a time, use strcpy ex ```strcpy([var], "Hello World!");```


### Assembly
All C programming is further translated to assembly code which is a lower level and somewhat human readable representation of the eventual machine code that is interpreted by the computer.
### Key concepts/definition to know
- Assembly is syntax formatted ```operation, [destination], [source]``` 
- There are two major syntaxes for assembly, AT&T and Intel (Intel is a lot cleaner)
    - To set GDB to intel reference [GDB](https://github.com/adminprivileges/skillbridgreNotes/blob/main/terminal_tools.md#gdb)
- <details>
  <summary><strong>Registers</strong> - a register is a small bit of memory that sits inside the CPU. and is used by assembly language to perform various tasks. </summary>

    - ```EAX``` (Accumulator register): It is used for I/O port access, arithmetic, interrupt calls, etc
    - ```EBX``` (Base register): It is used as a base pointer for memory access. Gets some interrupt return values
    - ```ECX``` (Counter register): It is used as a loop counter and for shifts. Gets some interrupt values
    - ```EDX``` (Data register): It is used for I/O port access, arithmetic, some interrupt calls.
    - ```EDI``` (Destination index):Used for string, memory array copying and setting and for far pointer addressing with EDI
    - ```ESI``` (Source index): Used for string and memory array copying
    - ```EBP``` (Stack Base pointer): Holds the base address of the stack
    - ```ESP``` (Stack pointer): Holds the top address of the stack
    - ```EIP``` (Index Pointer): Holds the offset of the next instruction. It can only be read
  </details>

- x86 processor values are stored in little-endian (least sig byte first) byte order which means the byte values ```0xc7    0x45    0xfc    0x00``` would be stored in a word as ```0x00fc45c7```


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

### Everything after this is rough notes that need to be formated

---
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