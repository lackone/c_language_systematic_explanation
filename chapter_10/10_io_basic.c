#include <stdio.h>

int main() {
    //fopen打开文件，
    FILE *p = fopen("test.txt", "r");

    if (p) {
        puts("open success");
        int err = ferror(p);
        printf("ferror: %d\n", err);
        int eof = feof(p);
        printf("eof: %d\n", eof);
        fclose(p);
    } else {
        puts("open failed");
    }

    //stdout
    //stdin
    //stderr

    return 0;
}
