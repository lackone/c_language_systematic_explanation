#include <stdio.h>

//文件作用域
int g_var = 0;

double add(double a, double b);

//静态变量
//1、作用域全局，内存不会因函数退出而销毁
//2、初值默认为0
void staticVar() {
    auto int a_var = 1;
    static int s_var = 1;
    a_var++;
    s_var++;
    printf("%d\n", a_var);
    printf("%d\n", s_var);
}

//通过寄存器传递数据
void regVar(register int r_var) {
    printf("%d\n", r_var);
}

int main() {
    //函数作用域
    // 自动变量
    // 1、函数块作用域
    // 2、没有默认初值
    auto int value = 0;

    //块作用域
    {
        auto int a = 11;
    }

    //printf("%d\n", a); //无法访问a

    //全局变量
    printf("%d\n", g_var);

    staticVar();
    staticVar();
    staticVar();

    regVar(100);

    return 0;
}
