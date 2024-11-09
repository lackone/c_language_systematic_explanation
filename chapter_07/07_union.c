#include <stdio.h>

typedef union Oper {
    int int_oper;
    double double_oper;
    char *char_oper;
} Oper;

typedef struct Instruction {
    Oper oper;
} Instruction;

int main(void) {
    //联合体，共享一块内存
    printf("sizeof(union Oper) = %d\n", sizeof(union Oper));

    Oper oper = {.double_oper = 3.14, .char_oper = "hello"};

    printf("%lf\n", oper.double_oper);
    printf("%s\n", oper.char_oper);

    return 0;
}
