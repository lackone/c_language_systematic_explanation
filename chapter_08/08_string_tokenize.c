#include <stdio.h>
#include <string.h>

int main() {
    char str[] = "c, 1972; c++, 1983; java, 1995;";

    //strtok 拆分字符串
    char *language_break = ";";
    char *field_break = ",";

    char *next = strtok(str, field_break);
    while (next) {
        printf("%s\n", next);

        next = strtok(NULL, language_break);
        if (next) {
            printf("%s\n", next);
        }

        next = strtok(NULL, field_break);
    }
}
