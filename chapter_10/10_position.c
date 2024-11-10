#include <stdio.h>

int main() {
    FILE *file = fopen("test.txt", "rb");
    //获取当前文件位置
    long pos = ftell(file);
    printf("pos = %ld\n", pos);

    //设置文件位置
    char buf[10];
    fread(buf, 1, 10, file);
    printf("pos = %ld\n", ftell(file));

    fseek(file, 10, SEEK_SET);
    printf("pos = %ld\n", ftell(file));

    fseek(file, 10, SEEK_CUR);
    printf("pos = %ld\n", ftell(file));

    fseek(file, 10, SEEK_END);
    printf("pos = %ld\n", ftell(file));

    //fsetpos();
    //fgetpost();

    fclose(file);
    return 0;
}
