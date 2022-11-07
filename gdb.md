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


Break 1. ESP = 