#include <practica_b.h>
ListNode *add(ListNode *num1, ListNode *num2)
{
	ListNode * p = reverse_list(num1);
	ListNode * q = reverse_list(num2);
	
	while ((p != NULL) && (q != NULL) 	
	{
		n = p -> value + q -> value;
		
	}
    return NULL;
}

ListNode * reverse_list(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    ListNode* new_head = reverse_list(head->next);

    head->next->next = head;
    head->next = NULL;

    return new_head;
}

