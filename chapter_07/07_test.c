#include <stdio.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node node2 = {2, NULL};
Node node3 = {3, NULL};

void chageNode(Node *node) {
    printf("%p\n", node);
    node->data = 222;
    //这里修改指针的指向
    //没有作用
    node = &node2;
}

void chageNode2(Node **node) {
    printf("%p\n", node);
    printf("%p\n", *node);
    (*node)->data = 333;
    //这里修改指针的指向
    //生效
    (*node) = &node3;
}

int main() {
    Node n = {1, 111};
    Node *p = &n;
    printf("n = %p\n", &n);
    printf("p = %p\n", p);
    printf("&p = %p\n", &p);

    chageNode(p);
    printf("%d\n", n.data);
    printf("%d\n", p->data);

    chageNode2(&p);
    printf("%d\n", n.data);
    printf("%d\n", p->data);
}
