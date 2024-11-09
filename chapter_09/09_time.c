#include <stdio.h>
#include <time.h>
#include <sys/timeb.h>

int main() {
    //UTC 世界调和时间，国际时间的标准，提及UTC，它一定是一个确定的值，不受时区的影响
    //GMT 格林威治时间，与UTC的时间是一致的，但我们说起GMT的时候其实指的就是零时区的时间
    //Epoch 翻译为纪元，时代，通常在计算机程序中使用的时间是从UTC时间1970年1月1日0时0分0秒开始的一个整数值

    //time_t
    //clock_t 程序运行的时间
    //struct tm t;
    struct timespec t; //C11 MSVC
    //struct timeb;
    //struct timeval;

    return 0;
}