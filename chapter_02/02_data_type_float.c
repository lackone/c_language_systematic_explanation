#include <stdio.h>

int main() {
    //浮点默认是双精度的，可以加后缀f表示单精度
    float a = 3.14f; //4字节

    double b = 3.1515; //8字节

    printf("float = %d\n", sizeof(float));
    printf("double = %d\n", sizeof(double));

    float money = 3.14f; //不能用浮点数来表示钱

    return 0;
}
