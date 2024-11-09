#include <stdio.h>
#include <time.h>

int main() {
    time_t current_time;
    time(&current_time);

    printf("%d\n", current_time);
    //获取本地时间
    struct tm *local_time = localtime(&current_time);

    printf("%d\n", local_time->tm_year); //年份，其值等于实际年份减去1900
    printf("%d\n", local_time->tm_mon); //月份，范围从0到11（0表示一月）
    printf("%d\n", local_time->tm_mday);
    printf("%d\n", local_time->tm_hour);
    printf("%d\n", local_time->tm_min);
    printf("%d\n", local_time->tm_sec);

    //tm转换成time_t
    time_t current_time2 = mktime(local_time);
    printf("%d\n", current_time2);

    //获取格林威治时间，差了8小时
    struct tm *gmt = gmtime(&current_time);

    printf("%d\n", gmt->tm_year); //年份，其值等于实际年份减去1900
    printf("%d\n", gmt->tm_mon); //月份，范围从0到11（0表示一月）
    printf("%d\n", gmt->tm_mday);
    printf("%d\n", gmt->tm_hour);
    printf("%d\n", gmt->tm_min);
    printf("%d\n", gmt->tm_sec);

    return 0;
}
