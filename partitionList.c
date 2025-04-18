struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode less_dummy;
    struct ListNode great_dummy;

    struct ListNode* less = &less_dummy;
    struct ListNode* great = &great_dummy;

    while (head) {
        if (head->val < x) {
            less->next = head;
            less = head;
        } else {
            great->next = head;
            great = head;
        }
        head = head->next;
    }

    less->next = great_dummy.next;
    great->next = NULL;

    return less_dummy.next;
}
