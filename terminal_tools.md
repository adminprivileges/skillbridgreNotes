# Terminal Tools
Here i just plan on including some useful terminal tools as well as optional configurations and flags. 
## Bash

- ``` #!/bin/bash -x ``` means that it produces additional debug
- Variables are very useful, but even more powerful, you can use shell expansion to allocate commands to variables so that: ``` var=$(date) = var=`date` ```
  - if youre experiencing trpuble try adding the following to your ~/.bashrc 
```
shopt -s expand_aliases
```
- arguments are denpted with $1 and $2
- $? will be your exit status
- ```read``` will capture your user input
  - \-p specifies a prompt displayed to the user
  - \-s makes it silent (doesnt show user input)
### Flow control
**If statements** 
```
if <TEST> 
then 
   <ACTION> 
fi
```
- && (AND) only works in a successful command execution
- || (OR) can be added as a condition if command is unsuccessful 
  - or you can use it as a regular logical OR 

**For Loops**
```
for var-name in <LIST> 
do 
   <ACTION>
done
```
(FOR loops can be done in one liners using semicolons)
```
for ip in $(seq 1 10); do echo 11.22.33.$ip; done 
```
also you can use brace expansion
```
for ip in {1..10}; do echo 11.22.33.$ip; done 
```
**While Loops**
```
while [ $counter -le 10 ]
do
   echo "11.22.33.$counter" 
   ((counter++)) #arethmatic expansion
done
```
also dont forget with these loops ```-lt``` is thess than ```-le``` is less than or equal to

**Functions**
These are cool for object oriented programming (not writing the same stuff over and over) they can be declared in two ways (personal preference) 
```
function <FUNCTION NAME>
   { 
commands
}
```
OR 
```
<FUNCTION NAME> () {
commands
}
```
**Hot Tip**
remember all variables declared are global variables unless specified with the ```local``` tag 

### Text Manipulation
#### Cut
The "cut" command is a very useful tool used to split text based on certain delimitters that can be specified with arguments for example the following command will slice an /etc shadow revealing users on a system:
```cut -d ":" -f 1 /etc/passwd``` 

Before:
```
root:$6$Dg3C//iX$Xb3iok11zP0LiXvW.w/fHweiyKrpSE.0NNthRx4T4jj3IFawLJux1pSoippJ0di2nVHcSv9sK4L3RF2qf15ee/:17764:0:99999:7:::
daemon:*:17752:0:99999:7:::
bin:*:17752:0:99999:7:::
sys:*:17752:0:99999:7:::
sync:*:17752:0:99999:7:::
games:*:17752:0:99999:7:::
man:*:17752:0:99999:7:::
lp:*:17752:0:99999:7:::
mail:*:17752:0:99999:7:::
news:*:17752:0:99999:7:::
uucp:*:17752:0:99999:7:::
proxy:*:17752:0:99999:7:::
```
After
```
root
daemon
bin
sys
sync
games
man
lp
mail
news
uucp
proxy
```
#### Awk
the awk command is more robust, but has a bit more of a learning curve you can achieve the same results as the above command by using this in awk
```
cat /etc/shadow | awk -F ":" '{print $1}' 
```
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
- In order to see more verbose debugging infomration include the ```-g``` flag when compiling with ```gcc```, this will give GDB access to the source code, vars, etc.
- When debugging any program that forks execution to a child process, gdb can instucted to follow the execution with ```set follow-fork-mode child``` (this is from withi gdb, not from invocation with bash)
### Commands
  - ```nexti``` or ```ni``` - Next Assembly Instruction
  - ```r [opt_argument]``` or ```run [opt_argument]``` - Start or restart the program
  - ```c``` or ```continue``` - Continue to the next breakpoint
  - ```b```  or ```break``` - Set breakpoint
    - ```info b``` - inspect breakpoints
    -  ```disable/enable b [breakSSpoint_number]``` - disable/enable a set breakpoint
    - ```delete [breakpoint_number]``` - delete breakpoint
    - *Note: When setting a breakpoint to an assembly instruction, make sure to use \* to instruct gdb to stop at e memory location ex: ```break *main+69``` or ```break *0x102982```*
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
