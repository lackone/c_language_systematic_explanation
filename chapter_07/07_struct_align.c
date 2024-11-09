#include <stdio.h>
#include <stddef.h>

#pragma pack(push, 4)
typedef struct Person {
    int age;
    char *name;
    char *id;
} Person;
#pragma pack(pop)

typedef struct Person2 {
    int age;
    char *name;
    char *id;
} Person2;

typedef struct {
    char a; //1
    char b; //1
    _Alignas(8)
    int c; //4
    short d; //2
    double e; //8
} Align;

int main(void) {
    //结构体对齐，默认为它占用大小空间的倍数

    printf("%d\n", sizeof(Person));

    printf("%d\n", sizeof(Person2));

    printf("%d\n", sizeof(Align));

    printf("%d\n", _Alignof(Align));

    printf("%d\n", offsetof(Align, c));

    return 0;
};
