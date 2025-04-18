Node* Duplicate_Sorter(Node* h) {
    if (h == NULL || h->next == NULL)
        return h;

    if (h->value == h->next->value) {
        Node* temp = h->next;
        h->next = temp->next;
        free(temp);
        return Duplicate_Sorter(h);  // Stay at current node
    } else {
        h->next = Duplicate_Sorter(h->next);  // Move to next node
        return h;
    }
}
