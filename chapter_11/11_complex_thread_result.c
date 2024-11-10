#include <stdio.h>
#include "tinycthread.h"
#include "tinycthread.c"

typedef struct {
    int a;
    char *b;
} ComplexResult;

typedef struct {
    int arg;
    ComplexResult result;
} ComplexArg;

int ComplexReturnValue(void *arg) {
    ComplexResult *result = malloc(sizeof(ComplexResult));
    result->a = 10;
    result->b = "hello world";
    return (int) result;
}

int ComplexReturnValue2(void *arg) {
    ComplexResult *result = &(((ComplexArg *) arg)->result);
    result->a = 10;
    result->b = "hello world";
    return 0;
}

int main() {
    // int arg = 1;
    // thrd_t t;
    // thrd_create(&t, ComplexReturnValue, &arg);
    //
    // int ret;
    // thrd_join(t, &ret);
    // ComplexResult *result = (ComplexResult *) ret;
    //
    // printf("%d\n", result->a);
    // printf("%s\n", result->b);

    thrd_t t2;
    ComplexArg arg2 = {.arg = 2};
    thrd_create(&t2, ComplexReturnValue2, &arg2);
    thrd_join(t2, NULL);
    printf("%d\n", arg2.result.a);
    printf("%s\n", arg2.result.b);

    return 0;
}
