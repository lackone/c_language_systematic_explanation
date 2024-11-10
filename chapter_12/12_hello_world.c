#include <stdio.h>

// gcc -E -E 12_hello_world.c -o 12_hello_world.i
// gcc -S 12_hello_world.i -o 12_hello_world.s
// gcc -c 12_hello_world.s -o 12_hello_world.o
// gcc -v 12_hello_world.o 12_hello_world
int main() {
    printf("Hello, world!\n");
    return 0;
}
