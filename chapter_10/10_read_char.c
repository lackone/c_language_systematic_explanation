#include <stdio.h>

void readFile() {
    FILE *p = fopen("test.txt", "r");
    if (p) {
        int c = getc(p);
        while (c != EOF) {
            printf("%c", c);
            c = getc(p);
        }
        fclose(p);
    }
}

int main() {
    //getchar 等价于 getc(stdin)
    //putchar 等价于 putc(stdout)
    //fputc
    //fgetc

    readFile();

    while (1) {
        int c = getchar();
        if (c == EOF) {
            break;
        }
        if (c == '\n') {
            continue;
        }
        printf("%c\n", c);
    }
}
