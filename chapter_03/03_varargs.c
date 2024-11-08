#include <stdio.h>
#include <stdarg.h>

void args(int arg_count, ...) {
    //1、定义va_list用于获取我们变长参数
    va_list vl;

    //2、开始遍历
    va_start(vl, arg_count);

    for (int i = 0; i < arg_count; i++) {
        //3、取出对应参数
        int arg = va_arg(vl, int);
        printf("%d\n", arg);
    }

    //4、结束遍历
    va_end(vl);
}

int main(void) {
    args(3, 1, 2, 3);

    return 0;
}
