// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// flatten LL

Node * flatten(Node * root)
{
  if(root == NULL || root -> next == NULL) 
    return root;
  return MergeLL(root, flatten(root -> next));
}


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
    // Create 3 sorted lists
    Node *a = linkedlist(1);
    a->next = linkedlist(4);
    a->next->next = linkedlist(7);

    Node *b = linkedlist(2);
    b->next = linkedlist(5);
    b->next->next = linkedlist(8);

    Node *c = linkedlist(3);
    c->next = linkedlist(6);
    c->next->next = linkedlist(9);

    // Merge them one by one
    Node *merged = MergeLL(a, b);
    merged = MergeLL(merged, c);

    // Print result
    Node *temp = merged;
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }

    return 0;
}
