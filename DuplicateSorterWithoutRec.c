// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// Remove duplicates from a sorted linked list

// we traverse through a linked list to start off - the condition here being that we keep going until the list is empty.
// as we traverse, we will apply a condition where if a certain element is equal to its next element, given the linked list is sorted, we will REMOVE that element the NEXT element and assign the thing it is pointing to to the pointer before it.
// ie if we have p as element n and q as n+1 we make a condition to check is p -> value == q->value and if true, we remove q and then set p -> next = q -> next (to preserve the memory address of whatever came after q). then we make a temporary node r so that we can prserve q's memory address and the value that address stores because after deleting q, our objective remains the same except we don't have q remaining anymore.
// Hence after deleting q, we still need the memory q is pointing to (q -> next) and the value of that memory. so we say p -> next = a temporary variable (r) which stores q's address Node * r = q -> next; and we say q = r; so that q takes on r's value. 

typedef struct listnode
{
    int value;
    struct listnode * next;
} Node;

Node * Duplicate_Sorter(Node * h)
{
    Node * p = h;
    Node * q = p -> next;
    
    while ((q != NULL))
    {
        if (p -> value == q -> value)
        {
            Node * r = q -> next;
            free(q);
            p -> next = r;
            q = r;
        }
        
        else
        {
            p = p->next;
            q = q->next;
        }
    }

        
    return h;
}

Node* create_node(int val) {
    Node* new_node = malloc(sizeof(Node));
    new_node->value = val;
    new_node->next = NULL;
    return new_node;
}

void print_list(Node* head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Create list: 1 → 1 → 2 → 3 → 3
    Node* h = create_node(1);
    h->next = create_node(1);
    h->next->next = create_node(2);
    h->next->next->next = create_node(3);
    h->next->next->next->next = create_node(3);

    printf("Before:\n");
    print_list(h);

    Duplicate_Sorter(h); // Assuming you implemented this

    printf("After:\n");
    print_list(h);

    return 0;
}
