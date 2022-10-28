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