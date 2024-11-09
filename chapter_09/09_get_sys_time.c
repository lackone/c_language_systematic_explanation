#include <stdio.h>
#include <time.h>

#if defined(_WIN32) || defined(_WIN64)
#include <sys/timeb.h>
#elif defined(__unix__) || defined(__unix) || defined(unix)
#include <sys/time.h>
#endif

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

    //获取秒数
    printf("%ld\n", current_time);
    printf("%ld\n", time(NULL));

    //获取毫秒
    printf("%lld\n", TimeInMilliSeconds());

    return 0;
}
