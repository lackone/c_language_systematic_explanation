#include <stdio.h>
#include <time.h>

typedef long long long_time_t;

long_time_t TimeInMilliSeconds(void) {
#if defined(_WIN32) || defined(_WIN64)
    struct timeb time_buffer;
    ftime(&time_buffer);
    return time_buffer.time * 1000LL + time_buffer.millitm;
#elif defined(__unix__) || defined(__unix) || defined(unix)
    struct timeval time_value;
    gettimeofday(&time_value, NULL);
    return time_value.tv_sec * 1000LL + time_value.tv_usec / 1000;
#elif defined(__STDC__) && __STDC_VERSION__ == 201112L
    struct timespec timespec_value;
    timespec_get(&timespec_value, TIME_UTC);
    return timespec_value.tv_sec * 1000LL + timespec_value.tv_nsec / 1000000;
#else
    time_t current_time = time(NULL);
    return current_time * 1000LL;
#endif
}

int main() {
    time_t current_time;
    time(&current_time);
    printf("%lld\n", current_time);
    struct tm *local_time = localtime(&current_time);

    puts(asctime(local_time));
    puts(ctime(&current_time));

    //格式化时间
    char buf[20] = {0};
    strftime(buf, 20, "%Y-%m-%d %H:%M:%S", local_time);
    //strftime(buf, 20, "%F %T", local_time);
    puts(buf);

    char buf2[20] = {0};
    strftime(buf2, 20, "%Y%m%d%H%M%S", local_time);
    puts(buf2);

    long_time_t current_time_millis = TimeInMilliSeconds();
    printf("%lld\n", current_time_millis);
    current_time_millis = current_time_millis % 1000;
    printf("%lld\n", current_time_millis);

    //输出毫秒
    char buf3[20] = {0};
    strftime(buf3, 20, "%Y%m%d%H%M%S", local_time);
    sprintf(buf3 + 14, "%03d", current_time_millis);
    puts(buf3);

    return 0;
}
