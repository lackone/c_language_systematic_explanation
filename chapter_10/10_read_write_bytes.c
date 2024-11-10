#include <stdio.h>

void echo() {
    char buf[32];
    while (1) {
        size_t read_bytes = fread(buf, 1, 32, stdin);
        if (read_bytes < 32) {
            if (feof(stdin)) {
                puts("eof");
                fwrite(buf, 1, 32, stdout);
            } else if (ferror(stdin)) {
                perror("error read from stdin");
            }
            break;
        }
        fwrite(buf, 1, 32, stdout);
    }
}

int main() {
    //fread();
    //fwrite();

    echo();

    return 0;
}
