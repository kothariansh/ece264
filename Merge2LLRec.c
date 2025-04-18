// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// Given two sorted linked lists, merge them (like mergesort)


typedef struct listnode
{
    struct listnode * next;
    int value;
} Node;

Node * linkedlist(int v)
{
    Node * n = malloc(sizeof(Node) * 1);
    n -> value = v;
    n -> next = NULL;
    return n;
}

Node * MergeLL(Node * a, Node * b)
{
    //base case
    if(a == NULL)
    {
        return b;
    }
    else if (b == NULL)
    {
        return a;
    }
    
    // resursive case
    if ((a->value) > (b -> value))
    {
        b -> next = MergeLL(a, b -> next);
        return b;
    }
    else
    {
        a -> next = MergeLL(a -> next, b);
        return a;
    }
}

int main() {
    // Create first sorted linked list: 1 -> 3 -> 5
    Node *a = linkedlist(1);
    a->next = linkedlist(3);
    a->next->next = linkedlist(5);

    // Create second sorted linked list: 2 -> 4 -> 6
    Node *b = linkedlist(2);
    b->next = linkedlist(4);
    b->next->next = linkedlist(6);

    // Merge the two lists
    Node *merged = MergeLL(a, b);

    // Print merged list
    Node *temp = merged;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    return 0;
}
