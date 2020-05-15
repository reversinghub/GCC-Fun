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
