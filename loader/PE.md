# Notes for understanding the PE/COFF File Format
*Some quick notes on PE/COFF so i dont forget stuff, check outt he official docs at https://learn.microsoft.com/en-us/windows/win32/debug/pe-format also check out https://0xrick.github.io/win-internals/pe3/*

## Overview

- **COFF** - A format for executables, shared libraries, ans object code.
  - original design was very limited, which spawned the  need for new extensions such as XCOFF and ECOFF
  - This iwas eventually replaced by ELFm but is still use don windows and some UNix-Like systems
-  **PE Format** - format for executable files, DLLS, etc on windows systems. It consists of a number of headers and sections that tell the linker how to map the file into memory. 
   - PE files do not contain position independent code
   - all addresses emitted are fixed at compile time
     - if these addresses cant be used, the OS usually recalculatess them and adapts the code.

![PE_COFF](https://upload.wikimedia.org/wikipedia/commons/thumb/1/1b/Portable_Executable_32_bit_Structure_in_SVG_fixed.svg/1024px-Portable_Executable_32_bit_Structure_in_SVG_fixed.svg.png)
 - The PE format consists of
   - **DOS Header** - 64 bytes long, Starts with "MZ", but more importantly the last 4 bytes is the location of the PE header.
   - **DOS Stub** - This program cannot be run in DOS mode”
   - **COFF/NT fields** - Contains the
     - **PE Signature** - "PE 00" File is PE 
     - **File Headers** - A standard COFF header with file metadata
     - **Optional Headers** -  
   - **Section Headers Array/Section Table** - a 40 byte array of image section headers 
   - **Sections** - Contains the actual file contents and dependencies.

## DOS Stub and Rich Header 
### Dos Header
The Dos header is a 63 byte long struct at the beginning of the PE file. Its not important on modern systems but is left for backwards compatibility. In a MS-DOS system the stub here will be executed instead of the actual program but on any other system this is ignored.
<pre>
typedef struct _IMAGE_DOS_HEADER {      // DOS .EXE header
    <b>WORD   e_magic;                     // Magic number</b>
    WORD   e_cblp;                      // Bytes on last page of file
    WORD   e_cp;                        // Pages in file
    WORD   e_crlc;                      // Relocations
    WORD   e_cparhdr;                   // Size of header in paragraphs
    WORD   e_minalloc;                  // Minimum extra paragraphs needed
    WORD   e_maxalloc;                  // Maximum extra paragraphs needed
    WORD   e_ss;                        // Initial (relative) SS value
    WORD   e_sp;                        // Initial SP value
    WORD   e_csum;                      // Checksum
    WORD   e_ip;                        // Initial IP value
    WORD   e_cs;                        // Initial (relative) CS value
    WORD   e_lfarlc;                    // File address of relocation table
    WORD   e_ovno;                      // Overlay number
    WORD   e_res[4];                    // Reserved words
    WORD   e_oemid;                     // OEM identifier (for e_oeminfo)
    WORD   e_oeminfo;                   // OEM information; e_oemid specific
    WORD   e_res2[10];                  // Reserved words
    <b>LONG   e_lfanew;                    // File address of new exe header</b>
  } IMAGE_DOS_HEADER, *PIMAGE_DOS_HEADER;
</pre>
Above is the entirety of the 64 byte struct although the only important values are bold, they are:
- **e_magic**: In a PE, this will always be `0x5A4D` which is the hex representation of `MZ` which states this program is executable.
- **e_lfanew**: located at offset `0x3C`, this is an 8 bytes long that signifies the start of the NT Headers. This is how the data looks using a PE analysis tool:
![Dos Header](https://0xrick.github.io/images/wininternals/pe3/1.png)

### Dos Stub
This is just a warning message that by default says `"This program cannot be run in DOS mode"` however this can be modified by the programmerr at compile time.

### Rich Header
The rich header is the chunk of data that resides between the Dos Stub and the NT headers. It is an undocumented stuctture and is only present in executables built with Microsoft Visual Studio, then it simply holds meradata about the tools used to build the executable.  

The Rich Header consists of a chunk of XORed data followed by a signature (Rich) and a 32-bit checksum value that is the XOR key. It contains other data as well but its less important as to how its encoded because any PE analyzer will decode this for you very simply. 

## NT Headers
*An Important note is the definition of an RVA(Relative Virtual Address), this is an offset of where the image was loaded into memeory (The image base) so an actual virtual address is RVA+Image Base*

NT headers is a structure defined in `winnt.h` as `IMAGE_NT_HEADERS` there are seperare ones for 32 but and 64 bit systems with the ony real difference being the `IMAGE_OPTIONAL_HEADER` the structure itself has 3 members:
- **Signature** - `0x50450000` or `PE \0\0`
- **File Header** - A structure which contains information abotut he PE File.
  ```
  typedef struct _IMAGE_FILE_HEADER {
    WORD    Machine;
    WORD    NumberOfSections;
    DWORD   TimeDateStamp;
    DWORD   PointerToSymbolTable;
    DWORD   NumberOfSymbols;
    WORD    SizeOfOptionalHeader;
    WORD    Characteristics;
  } IMAGE_FILE_HEADER, *PIMAGE_FILE_HEADER;
  ```
    - **Machine** - CPU Architecture `0x8864` for AMD64 and `0x14c` for i386 [complete list here](https://docs.microsoft.com/en-us/windows/win32/debug/pe-format) (ignored by windows PE loader)
    - **NumberOfSections** - Indicates the Number of sectioins/the size of the section table.
    - **TimeDateStamp** - an epoc timestamp of when the file was created
    - **PointerToSymbolTable/NumberOfSymbols** - these indicate the offset to the COFF table and the number of entries, although they get zeroed out because this is deprecated.
    - **SizeOfOptionalHeader** - Exactly what it says
    - **Characteristics** - contains file specific attributes such as system file, executable, etc. [Docs](https://docs.microsoft.com/en-us/windows/win32/debug/pe-format)
    - ![PE_Header](https://0xrick.github.io/images/wininternals/pe4/2.png)
- **Optional Header** - My favorite part about widows is when they do things like name important things "optional". This contains crucial information that allows windows to actually load and run the ecexutable. Its called optional because not all files use them (like object files). The optional header is a very large struct with 30/31 members depending on whether it the 32 or the 64 bit counterpart. The first 8 members are standard for every implementation of the CODD file format, while the others may vary with milelage. The 32 bit contains the extra `BaseOfData` member which simply states the begining of the data section. 

    ```
    typedef struct _IMAGE_OPTIONAL_HEADER {
        //
        // Standard fields.
        //

        WORD    Magic;
        BYTE    MajorLinkerVersion;
        BYTE    MinorLinkerVersion;
        DWORD   SizeOfCode;
        DWORD   SizeOfInitializedData;
        DWORD   SizeOfUninitializedData;
        DWORD   AddressOfEntryPoint;
        DWORD   BaseOfCode;
        DWORD   BaseOfData;

        //
        // NT additional fields.
        //

        DWORD   ImageBase;
        DWORD   SectionAlignment;
        DWORD   FileAlignment;
        WORD    MajorOperatingSystemVersion;
        WORD    MinorOperatingSystemVersion;
        WORD    MajorImageVersion;
        WORD    MinorImageVersion;
        WORD    MajorSubsystemVersion;
        WORD    MinorSubsystemVersion;
        DWORD   Win32VersionValue;
        DWORD   SizeOfImage;
        DWORD   SizeOfHeaders;
        DWORD   CheckSum;
        WORD    Subsystem;
        WORD    DllCharacteristics;
        DWORD   SizeOfStackReserve;
        DWORD   SizeOfStackCommit;
        DWORD   SizeOfHeapReserve;
        DWORD   SizeOfHeapCommit;
        DWORD   LoaderFlags;
        DWORD   NumberOfRvaAndSizes;
        IMAGE_DATA_DIRECTORY DataDirectory[IMAGE_NUMBEROF_DIRECTORY_ENTRIES];
    } IMAGE_OPTIONAL_HEADER32, *PIMAGE_OPTIONAL_HEADER32;
    ```
    - **Magic**
      - 0x10B: Identifies the image as a PE32 executable.
      - 0x20B: Identifies the image as a PE32+ executable.
      - 0x107: Identifies the image as a ROM image.
    - **MajorLinkerVersion/MinorLinkerVersion** - Major/minor versions of the linkers
    - **SizeOfCode** - Holds the size of the .text section(s)
    - **SizeOfInitializedData** - size of the .data section(s)
    - **SizeOfUninitializedData**- size of .bss section(s)
    - **AddressOfEntryPoint** - RVA of the entry point when the file is loaded into memory. THIS IS NOT THE POINT THE MAIN FUNCTION. In the absense of an entry point (like with DLLS) this will be 0.
    - **BaseOfCode** - An RVA for the start of the code section when the file is loaded into memory
    - **BaseOfData** - An RVA for the start of the data section when the file is loaded into memory (for 32 but only)
    - **ImageBase** - holds the prefered address of the the first byte when loaded into memory, due to memory protections this isnt listened to and is randomized and fized y the OS.
    - **SectionAlignment** - Holds the size of the section alignment in memory, cant be less than the file alignment
    - **FileAlignment** - hold the value used to align raw data, this value should be a power of 2 between 512 and 64K, and if the value of SectionAlignment is less than the architecture’s page size then the sizes of FileAlignment and SectionAlignment must match.
    - **MajorOperatingSystemVersion, MinorOperatingSystemVersion, MajorImageVersion, MinorImageVersion, MajorSubsystemVersion and MinorSubsystemVersion** -OS Info
    - **Win32VersionValue** - Reserved Field, should be 0.
    - **SizeOfImage** - The size of the image in bytes rounded to the SectionAlignment. 
    - **SizeOfHeaders** - The combined size of the DOS stub, PE header (NT Headers), and section headers rounded up to a multiple of FileAlignment
    - **CheckSum** - A checksum of the image file, it’s used to validate the image at load time.
    - **Subsystem** - specifies if any windows subsystems are needed to run this
    - **DLLCharacteristics** - Not specific to DLLS, this specifies file atributes.
    - **SizeOfStackReserve, SizeOfStackCommit, SizeOfHeapReserve and SizeOfHeapCommit** - Memory reservation
    - **LoaderFlags** - reserved field, set to 0
    - **NumberOfRvaAndSizes** - the size of the DataDirectory array
    - **DataDirectory** - an array of `IMAGE_DATA_DIRECTORY` structures
    ![optional_header](https://0xrick.github.io/images/wininternals/pe4/3.png)