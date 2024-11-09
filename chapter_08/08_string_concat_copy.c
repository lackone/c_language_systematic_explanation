#include <stdio.h>
#include <string.h>

int main() {
    //strcat strcpy
    char *str = "hello";
    char dest[50] = "i say: ";

    //strcat(dest, str);
    printf("%s\n", dest);
    printf("%d\n", strlen(dest));

    strcpy(dest + strlen(dest), str);
    printf("%s\n", dest);
}
