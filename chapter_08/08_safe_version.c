#include <stdio.h>
#include <string.h>

int main() {
    char dst[50] = {0};

    int error_no = strcpy_s(dst, 50, "abcdefghijklmnopqrst");

    printf("%s\n", dst);

    return 0;
}
