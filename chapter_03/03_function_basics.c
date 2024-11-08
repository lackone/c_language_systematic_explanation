#include <stdio.h>

// x 形式参数
double test(double x) {
    return x * x;
}

int main() {
    //3.33 实际参数
    printf("%f \n", test(3.33));



    return 0;
}
