#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node *CreateNode(int data) {
    Node *node = (Node *) malloc(sizeof(Node));
    if (!node) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    return node;
}

void DestroyNode(Node **node) {
    (*node)->next = NULL;
    free(*node);
    *node = NULL;
}

Node *CreateList(int *arr, int len) {
    if (!arr || len <= 0) {
        return NULL;
    }

    Node *head = CreateNode(arr[0]);
    Node *current = head;
    for (int i = 1; i < len; i++) {
        current->next = CreateNode(arr[i]);
        current = current->next;
    }

    return head;
}

void DestroyList(Node **head) {
    if (!head || !*head) {
        return;
    }
    Node *current = *head;
    while (current) {
        Node *next = current->next;
        DestroyNode(&current);
        current = next;
    }
    *head = NULL;
}

void InsertNode(Node **head, int data, int index) {
    if (!head || index < 0) {
        return;
    }
    Node *new = CreateNode(data);
    if (index == 0) {
        new->next = *head;
        *head = new;
    } else {
        if (!(*head)) {
            *head = CreateNode(0);
        }
        Node *current = *head;
        while(index > 1) {
            if (!current->next) {
                current->next = CreateNode(0);
            }
            current = current->next;
            index--;
        }
        new->next = current->next;
        current->next = new;
    }
}

void PrintList(Node *head) {
    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    Node *head = CreateList(arr, 5);
    PrintList(head);

    InsertNode(&head, 100, 3);
    InsertNode(&head, 200, 0);
    InsertNode(&head, 300, 9);
    InsertNode(&head, 400, 10);
    PrintList(head);

    DestroyList(&head);

    InsertNode(&head, 10, 0);
    PrintList(head);
    DestroyList(&head);

    InsertNode(&head, 10, 10);
    PrintList(head);
    DestroyList(&head);

    return 0;
}
