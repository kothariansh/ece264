// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// removes duplicates from 2 linkedlists and merges them

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
    
    if (a == NULL)
    {
        return b;
    }
    else if(b == NULL)
    {
        return a;
    }
    
    // recursive case
    if ((a -> value) > (b -> value))
    {
        b -> next = MergedLL(a, b -> next);
        return b;
    }
    else
    {
        a -> next = MergedLL(a -> next, b);
        return a;
    }
}

Node * DuplicateRemover(Node * h)
{
    Node * p = h;
    Node * q = p -> next;
    
    while (q != NULL)
    {
        if ((p -> value) == (q -> value))
        {
            p -> next = q -> next;
            Node * r = q -> next;
            free(q);
            p -> next = r;
            q = r;
        }
        else
    {
        p = p -> next;
        q = q -> next;
    }
    }
return h;
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

    // Merge and remove duplicates
    Node *merged = MergedLL(a, b);
    DuplicateRemover(merged);

    // Print merged and cleaned list
    Node *temp = merged;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    return 0;
}
