
//静态链接库
// gcc -c 12_static_sum.c
// file 12_static_sum.o
// ar rcs 12_static_sum.a 12_static_sum.o
// ar t 12_static_sum.a
int sum2(int a, int b) {
    return a + b;
}