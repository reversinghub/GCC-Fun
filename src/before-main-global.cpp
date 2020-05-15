#include <stdio.h>

int foo();

int bar = foo();

int foo() {
    printf("in foo()\n");
    return 42;
}

int main(int argc, char **argv) {
    printf("in main()\n");
    return 0;
}
