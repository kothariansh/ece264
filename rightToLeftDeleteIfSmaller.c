#include <stdio.h>
#include <stdlib.h>

typedef struct listnode {
    int value;
    struct listnode* next;
} Node;

Node* create_node(int v) {
    Node* n = malloc(sizeof(Node));
    n->value = v;
    n->next = NULL;
    return n;
}

// Recursive helper to filter and print deleted nodes
Node* filter(Node* head, int* sum_so_far) {
    if (head == NULL) return NULL;

    Node* new_next = filter(head->next, sum_so_far);

    if (head->value < *sum_so_far) {
        printf("Deleted: %d\n", head->value);
        free(head);
        return new_next;
    } else {
        *sum_so_far += head->value;  // Only add kept values
        head->next = new_next;
        return head;
    }
}

Node* process(Node* head) {
    int sum = 0;
    return filter(head, &sum);
}

void print_list(Node* head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Input: 15 -> 2 -> 3 -> 1 -> 1 -> 2 -> 5 -> 7
    Node* head = create_node(4);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(1);
    head->next->next->next->next = create_node(3);
    

    printf("Original: ");
    print_list(head);

    printf("\nDeleted Nodes:\n");
    head = process(head);

    printf("\nFiltered: ");
    print_list(head);

    return 0;
}
