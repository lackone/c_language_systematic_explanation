#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int number = rand();
    printf("%d \n", number);
    int i = 0;

    while (1) {
        printf("please input your number: \n");
        scanf("%d", &i);
        if (i > number) {
            printf("is bigger \n");
        } else if (i < number) {
            printf("is small \n");
        } else {
            printf("ok \n");
            break;
        }
    }
    return 0;
}
