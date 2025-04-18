int findLen(struct ListNode* head) {
    int len = 0;
    while (head) {
        len++;
        head = head->next;
    }
    return len;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int len1, len2;
    len1 = findLen(l1);
    len2 = findLen(l2);

    int len = (len1 < len2) ? len1 : len2;
    struct ListNode* large = (len1 < len2) ? l2 : l1;
    struct ListNode* small = (len1 < len2) ? l1 : l2;

    struct ListNode dummy;
    dummy.next = large;

    int carry = 0;
    for (int i = 0; i < len; i++) {
        int val = large->val + small->val + carry;
        large->val = val % 10;
        carry = val / 10;
        large = large->next;
        small = small->next;
    }

    if (carry) {
        while (large) {
            int val = large->val + carry;
            large->val = val % 10;
            carry = val / 10;
            if (carry == 0)
                return dummy.next;

            large = large->next;
        }

        if (carry) {
            struct ListNode* last = dummy.next;
            while (last->next) {
                last = last->next;
            }

            struct ListNode* newNode = malloc(sizeof(struct ListNode));
            newNode->val = carry;
            newNode->next = NULL;
            last->next = newNode;
        }
    }

    return dummy.next;
}
