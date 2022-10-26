## x200
- Compiled program memory is broken into 5 segments:
    - **Text:** (Code Segment), where the assembly instructions are located. 
        - Read Only

    - **Data:** used to store initialized global and static variables
        - Writable, but fixed in size
    - **BSS:**  used for uninitialized g&s variables
        - Writable, but fixed in size
    - **Heap:** directly controlled by the programmer, writes downward towards higher memory addresses
    - **Stack:** used to store local function variables and context during function calls (what ```bt``` looks at) grows upards towards lower memory
- When a function is called a stack frame is pushed to the stack. 
    - frame contains function parameters, its local variables and the: 
        - SFP (saved frame pointer), used to restore EIP to previous value
        - return address, used to restore EIP to the next inst adter the function call
![Stack](https://learning.oreilly.com/api/v2/epubs/urn:orm:book:9781593271442/files/httpatomoreillycomsourcenostarchimages254229.png.jpg)
    - when going from main to funct
        - parameters are added to the ESP
        - Main ebp becomed SFP
        - funct EBP sits between SFP and return address
        - next instruction becomes return address
        - variables are added on top of funct ebp 
- ```malloc()``` and ```free()``` are used to allocate and deallocate space in the heap respectively
    - malloc returns a pointer with the datatype void so it must be typecasted to its expected type
    