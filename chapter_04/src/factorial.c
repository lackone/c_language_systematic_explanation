#include "../include/factorial.h"

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