#include <stdio.h>
#include <time.h>

#define _XOPEN_SOURCE

int main() {
    time_t current_time;
    time(&current_time);
    struct tm *local_time = localtime(&current_time);
    char buf[20] = {0};
    strftime(buf, 20, "%Y-%m-%d %H:%M:%S", local_time);

    struct tm parse_time;
    //char* unparse_string = strptime(buf, "%Y-%m-%d %H:%M:%S", &parse_time);

    long milliseconds;
    sscanf(buf, "%4d-%2d-%2d %2d:%2d:%2d.%3d",
           &parse_time.tm_year,
           &parse_time.tm_mon,
           &parse_time.tm_mday,
           &parse_time.tm_hour,
           &parse_time.tm_min,
           &parse_time.tm_sec,
           &milliseconds
    );

    return 0;
}
