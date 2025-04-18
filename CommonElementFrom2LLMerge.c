// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// Given two sorted linked lists, build a new list containing only the values found in both lists

// similar to removing duplicate values from a linkedlist, we must first remove the duplicate values by comparing 2 seperate linkedlists and from there consolidate them into 1.
// i believe the steps to remove/filter out the elements in both of them is the same/ very similar to what we did for 1 linkedlist but only after that we have to take all the elements and combine them together.
// first it is better to merge both linkedlists, probably through recursion. then we apply what we wrote for remvoing duplicates from a linkedlist and then we combine them together therby giving us the final result.


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

Node * MergedLL(Node * a, Node * b)
{
    // base case
    if (a == NULL || b == NULL)
    return NULL;
    
    // recursive case
    if ((a -> value) == (b -> value))
    {
        Node * r = linkedlist(a-> value);
        r -> next = MergedLL(a->next, b->next);
        return r;
    }

    else if ((a -> value) > (b -> value))
    {
        return MergedLL(a, b -> next);
    }
    else
    {
        return MergedLL(a -> next, b);
    }
}


int main() {
    // Create first sorted linked list: 1 -> 2 -> 3 -> 5 -> 7
    Node *a = linkedlist(1);
    a->next = linkedlist(2);
    a->next->next = linkedlist(3);
    a->next->next->next = linkedlist(5);
    a->next->next->next->next = linkedlist(7);

    // Create second sorted linked list: 2 -> 3 -> 4 -> 5 -> 6
    Node *b = linkedlist(2);
    b->next = linkedlist(3);
    b->next->next = linkedlist(4);
    b->next->next->next = linkedlist(5);
    b->next->next->next->next = linkedlist(6);

    // Get intersection
    Node *intersection = MergedLL(a, b);

    // Print the intersection list
    printf("Values found in both lists: ");
    Node *temp = intersection;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    return 0;
}

