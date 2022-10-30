## x200
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
