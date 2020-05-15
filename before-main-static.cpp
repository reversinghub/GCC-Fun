#include <stdio.h>

class BeforeMain
{
    static int foo;

};

int bar() { 
    printf("in bar()\n"); 
    return 0; 
}

int BeforeMain::foo = bar();

int main(int argc, char** argv) { 
    printf("in main()\n");
    return 0; 
}
