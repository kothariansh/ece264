// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>


typedef struct listnode
{
    struct listnode * next;
    int value;
} Node;

Node * Node_construction(int v)
{
    Node * n = malloc(sizeof(Node));
    n -> value = v;
    n -> next = NULL;
    return n;
}

Node * List_search(Node * h, int v)
{
    Node * p = h;
    while (((p-> value ) != v) && p != NULL)
    {
        if ((p->value) == v)
        {
            return p;
        }
        p = p->next;
    }
    return p;
}

Node * List_destroy(Node * h)
{
    while (h != NULL)
    {
        Node * p = h -> next;
        free(h);
        h = p;
    }
}

Node * List_delete(Node * h, int v)
{
    if((h -> value) == v)
    {
        Node * p = h;
        free(h);
        return p;
    }
}

Node * List_deleteAlt (Node * h, int v)
{
    Node * p = h;
    Node * q = p -> next;
    
    while ((q != NULL) && ((q -> value) != v))
    {
        p = p -> next;
        q = q -> next;
    }
    
    if (q != NULL)
    {
        p -> next = q -> next;
        free(q);
    }
    
    return h;
}

Node * List_insert(Node * h, int v)
{
    printf("insert whatever: %d\n", v);
    Node * p = Node_construction(v);
    p -> next = h;
    return p;
}


int main() {
    Node * head = NULL;
    head = List_insert(head, 917);
    head = List_insert(head, -503);
    head = List_insert(head, 326);

    return 0;
}



