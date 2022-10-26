## x200
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
    - ```p```  Memory Address
- You can pad a number with 0s by prepending a format string with a number ex ```03%d```
- When taking user input the ```scanf``` tool can only take pointers so make sure to use the ```&``` operator ex: ```scanf(%s, &[variable])```
- You can temporarily change a varable datatype by typecasting ex: ```(float) [variable]```
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