#include <locale.h>
#include <stdio.h>
#include <stdbool.h>

#define MAX_NUM 100

int main() {
    setlocale(LC_ALL, "");

    //_Bool  bool
    _Bool is_ok = true;

    bool is_yes = true;

    //if else 语句
    if (is_ok) {
        printf("is ok \n");
    } else {
        printf("is not ok \n");
    }

    //if elseif else 语句
    int ret = 10;
    if (ret > 1) {
        printf("ret > 1 \n");
    } else if (ret < 10) {
        printf("ret < 10 \n");
    } else {
        printf("else \n");
    }

    int input;
    wprintf(L"请输入一个数字:\n");
    scanf("%d", &input);
    printf("%d\n", input);
    if (input > MAX_NUM) {
        printf("you input > MAX_NUM \n");
    } else {
        printf("you input < MAX_NUM \n");
    }

    //三元运算符
    int a = 3 > 2 ? 1 : -1;
    printf("%d\n", a);

    //switch语句
    switch (input) {
        case 1:
            printf("%d \n", input);
            break;
        case 2:
            printf("%d \n", input);
            break;
        default:
            printf("%d \n", input);
            break;
    }

    return 0;
}
