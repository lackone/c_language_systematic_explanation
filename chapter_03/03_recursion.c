#include <stdio.h>

int Factorial(int n) {
    if (n == 0) {
        return 1;
    }
    return n * Factorial(n - 1);
}

int Fibonacci(int n) {
    if (n == 0 || n == 1) {
        return n;
    }
    return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main() {
    printf("%d\n", Factorial(3));
    printf("%d\n", Factorial(5));
    printf("%d\n", Factorial(10));

    printf("%d\n", Fibonacci(1));
    printf("%d\n", Fibonacci(2));
    printf("%d\n", Fibonacci(3));
    printf("%d\n", Fibonacci(5));
    printf("%d\n", Fibonacci(10));

    return 0;
}
