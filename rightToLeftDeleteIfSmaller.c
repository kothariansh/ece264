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

// Actual recursive logic using sum_so_far
Node* filter_helper(Node* head, int* sum_so_far) {
    if (head == NULL) return NULL;

    Node* new_next = filter_helper(head->next, sum_so_far);

    if (head->value < *sum_so_far) {
        printf("Deleted: %d\n", head->value);
        free(head);
        return new_next;
    } else {
        *sum_so_far += head->value;
        head->next = new_next;
        return head;
    }
}

// Public function taking only head
Node* filter(Node* head) {
    int sum = 0;
    return filter_helper(head, &sum);
}

void print_list(Node* head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = create_node(4);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(1);
    head->next->next->next->next = create_node(3);

    printf("Original: ");
    print_list(head);

    printf("\nDeleted Nodes:\n");
    head = filter(head);

    printf("\nFiltered: ");
    print_list(head);

    return 0;
}
