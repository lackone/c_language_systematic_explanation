#include <stdio.h>

typedef struct Company {
    char *name;
    char *id;
} Company;

//定义结构体
struct Person {
    char *name;
    int age;
    char *id;
    Company *company;
    Company company2;

    struct {
        int extra;
        char *extra_str;
    } extra_value;
};

//匿名结构体
struct {
    char *name;
    int age;
    char *id;
} Anonymous_Person;

int main(void) {
    //结构体初始化
    Company company = {.id = "Company", .name = "Company"};

    struct Person p = {
        .name = "John", .age = 20, .id = "John", .company = &company, .company2 = {.id = "test", .name = "test"}
    };

    printf("Name: %s\n", p.name);

    //p.company->name
    //p.extra_value.extra

    //结构体指针
    struct Person *pp = &p;

    printf("Age: %d\n", pp->age);

    printf("sizeof: %d\n", sizeof(struct Person));
    printf("sizeof: %d\n", sizeof(p));

    return 0;
}
