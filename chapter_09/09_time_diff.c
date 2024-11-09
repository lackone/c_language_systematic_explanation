#include <stdio.h>
#include <time.h>

void work() {
    double sum = 0;
    for (int i = 0; i < 400000000; i++) {
        sum += i * i / 3.14;
    }
    printf("sum = %lf\n", sum);
}

int main() {
    time_t start_time = time(NULL);
    work();
    time_t end_time = time(NULL);
    //获取时间相差的秒数
    double diff = difftime(end_time, start_time);

    printf("%lf\n", diff);

    //处理器时钟所使用的时间
    clock_t start = clock();
    work();
    clock_t end = clock();
    printf("%lf\n", (end - start) * 1.0 / CLOCKS_PER_SEC);

    return 0;
}
