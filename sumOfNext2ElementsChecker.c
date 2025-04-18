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

Node* process_recursive(Node* head) {
    if (head == NULL || head->next == NULL || head->next->next == NULL)
        return head;

    if (head->value < head->next->value + head->next->next->value) {
        Node* temp = head;
        head = head->next;
        free(temp);
        return process_recursive(head);
    } else {
        head->next = process_recursive(head->next);
        return head;
    }
}

void print_list(Node* head) {
    while (head) {
        printf("%d ", head->value);
        head = head->next;
    }
    printf("\n");
}

int main() {
    // Build list: 4 -> 2 -> 3 -> 1
    Node* head = create_node(4);
    head->next = create_node(2);
    head->next->next = create_node(3);
    head->next->next->next = create_node(1);

    printf("Original list:\n");
    print_list(head);

    head = process_recursive(head);

    printf("Processed list:\n");
    print_list(head);

    return 0;
}
