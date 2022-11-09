# Terminal Tools
Here i just plan on including some useful terminal tools as well as optional configurations and flags. 

## Debugging
### GDB 
A useful command line tool for debugging code.
#### Startup Notes
- Run ```gdb -q``` to skip the copyright message
- ```-`args``` allows you to include arguments
- Assembly is much easier to read when its Intel Formatted. To set GDB to intel. 
    ```
    > gdb -q
    > set dis intel
    > quit
    > echo "set dis intel" > ~/.gdbinit
    ```
### Commands
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
#### TUI (Terminal User Interface)
a curses text interface to make gdb more usable
-  ```CTRL+X+A``` - Enter/Exit TUI
-  ```CTRL+L``` Reload display
-  ```layout [name]``` enters one of the specified layouts
   -  ```asm``` - assembly
   -  ```regs``` - registers
   -  ```src``` - source code
-  ```focus [layout]``` - change your cursor focus
   -  ```focus cmd``` - move cursor back to gdb command line
-  ```CTRL+X+O``` - switch focus

#### GDB examination syntax
in order to inspect the instructions, memory, etc in a program, GDB has a very powerful examination syntax in the form of: ```x/[number(opt, default=1)][format][size(opt, default=word)] [target]``` ex: ```x/2xb $eip```
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


## Networking
### Netcat
Netcat is a very useful command line utility for a variety of different network functions, its really useful for scanning and sending data. Here are some examples below
#### TCP Scan
```
nc -nv -w 1 -z [IP_ADDRESS] [PORT]
```
- ```-w ``` specifies connection timeout in seconds
- ```-z ``` zero IO mode (dont send any data)
- ```-n``` no name resolution
- ```-v``` Increase verbosity

#### UDP Scan
```
nv -nv -u -z -w 1 [IP_ADDRESS] [PORT]
```
- ``` -u``` is UDP mode

*Note: This is pretty unreliable with a firewall because it relies on an ICMP unreachable to call something closed*

#### Listen on a port
```
netcat -l -p [PORT]
```
- ```-l``` specifies a listening port
- ```-p``` specifies port to listen on

### Tcpdump
TCPdump is a useful command line utility for sniffing packets on a  network. Below ive syntax with some useful flags
#### Capture Traffic on an IP/Port
```
tcpdump -i eth0 -nn -s0 -v -A src [IP_ADDRESS] and dst port [PORT]
```
- ```-i``` - Specified interface to capture on, in this case we're using ```eth1```
- ```-nn``` 1 ```n``` disables name resolution 2 ```n```s disable name and port resolution
- ```-v``` increase verbosity
- ```-A``` include ASCII strings to help readability 


