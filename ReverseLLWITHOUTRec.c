// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

typedef struct listnode
{
    struct listnode * next;
    int value;
} Node;

Node * reverseLL(Node * h)
{
    Node * prev = NULL;
    Node * curr = h;
    Node * next = NULL;
    
    while (curr != NULL)
    {
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}


Node *linkedlist(int v) {
    Node *n = malloc(sizeof(Node));
    n->value = v;
    n->next = NULL;
    return n;
}

void print_list(Node *h) {
    while (h != NULL) {
        printf("%d -> ", h->value);
        h = h->next;
    }
    printf("NULL\n");
}

int main() {
    Node *a = linkedlist(69);
    a->next = linkedlist(7385938);
    a->next->next = linkedlist(4384823);
    a->next->next->next = linkedlist(0);

    printf("Original List:\n");
    print_list(a);

    Node *rev = reverseLL(a);

    printf("Reversed List:\n");
    print_list(rev);

    return 0;
}
