- Why use heap for variables instead of stack? 
    - Use the stack when your variable will not be used after the current function returns. Use the heap when the data in the variable is needed beyond the lifetime of the current function.
    - heap is more flexible with size changes and altering memory
- In gdb, im getting ```0x41:   Cannot access memory at address 0x41```
  - Check out this explination on [SoF](https://stackoverflow.com/questions/30139356/gdb-cant-access-memory-address-error)
  - need to understand diff between print a x/x

- got confused for a sec in x330 since they changed the compiled name from the default exploit_notesearch to just notesearch so i was looking for the address of my variables in notesearch which is running as root who doesnt have variables

- The VM prolly shouldnt be able to touch the internet
