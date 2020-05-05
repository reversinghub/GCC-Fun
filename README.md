# GCC-Fun

This repository contains interesting tricks, twists and cool features of GNU Compiler Collection

```
 ██████╗  ██████╗ ██████╗    ███████╗██╗   ██╗███╗   ██╗
██╔════╝ ██╔════╝██╔════╝    ██╔════╝██║   ██║████╗  ██║
██║  ███╗██║     ██║         █████╗  ██║   ██║██╔██╗ ██║
██║   ██║██║     ██║         ██╔══╝  ██║   ██║██║╚██╗██║
╚██████╔╝╚██████╗╚██████╗    ██║     ╚██████╔╝██║ ╚████║
 ╚═════╝  ╚═════╝ ╚═════╝    ╚═╝      ╚═════╝ ╚═╝  ╚═══╝
 ```

### Techniques

* Run code before the ```main()``` function
* Run code after the ```main()``` function

### Pre-main/Post-main code

Each ELF executable and shared object file contains a section table, describing the sections inside the ELF object file. Two of those sections are specifically interesting because they offer opportunities to hide code that might not be immediately spotted during static analysis:

> The .init and .fini sections have a special purpose. If a function is placed in the .init section, the system will execute it before the main function. Also the functions placed in the .fini section will be executed by the system after the main function returns. This feature is utilized by compilers to implement global constructors and destructors in C++.


* ```.init``` - This section holds executable instructions that contribute to the process initialization code. When a program starts, the system arranges will execute the code in this section __before the main program entry point__ (called main in C programs).
* ```.fini``` - This section holds executable instructions that contribute to the process termination code. When a program exits normally, the system will execute the code in this section.

#### How to create constructors/destructors

Constructors and destructors are created using the ```constructor (priority)``` and ```destructor (priority)``` attributes. The priority number is optional and controls the order in which constructor and destructor functions are run. _A constructor with a smaller priority number runs before a constructor with a larger priority number; the opposite relationship holds for destructors_. 

**Note:** This logic order is important. If we have a constructor that allocates a resource and a destructor that deallocates the same resource, both functions typically have the same priority.

Example:

```
#include <stdio.h>
  
int __attribute__ ((constructor)) premain() {
    printf("[*] In premain()\n");
    return 0;
}

int __attribute__ ((destructor)) postmain(){
    printf("[*] In postmain()\n");
    return 0;
}

int main(int argc, char **argv) {
    printf("[*] In main()\n");
    return 0;
}
```
#### How to detect constructors/destructors
* How to view .ctors/.dtors, .fini/.init array?
* id pro example
* GDB example
* Other places?

### References

* [gdbinit man page](http://man7.org/linux/man-pages/man5/gdbinit.5.html)
* [GitHub gdbinit/Gdbinit](https://github.com/gdbinit/Gdbinit)
* [GDB Debugging cheatsheet](https://darkdust.net/files/GDB%20Cheat%20Sheet.pdf)
* [GDB Command Reference](https://visualgdb.com/gdbreference/commands/)
* [x86_64 GCC Calling convention](https://wiki.osdev.org/Calling_Conventions)
* [GCC Function attributes](https://gcc.gnu.org/onlinedocs/gcc-4.7.0/gcc/Function-Attributes.html)
* [The .init and .fini Sections](http://ftp.math.utah.edu/u/ma/hohn/linux/misc/elf/node3.html)
* [Abusing .CTORS and .DTORS for fun 'n profit](https://www.exploit-db.com/papers/13234)https://www.exploit-db.com/papers/13234
