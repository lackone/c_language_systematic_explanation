#include <stdio.h>

int main() {
    FILE *p = fopen("test.txt", "r");
    char buf[8192] = {0};
    //setbuf(p, buf);
    //_IOFBF 全缓冲
    //_IOLBF 按行缓冲
    //_IONBF 无缓冲
    if (p) {
        setvbuf(p, buf, _IOLBF, 8192);


        fclose(p);
    }

    //清空缓冲
    fflush(p);

    return 0;
}
