/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    struct ListNode* temp=head;
    struct ListNode* even=head->next;
    struct ListNode* temp2=head->next;
    while(temp->next!=NULL && even->next!=NULL)
    {
        temp->next=temp->next->next;
        even->next=even->next->next;
        temp=temp->next;
        even=even->next;
    }
    temp->next=temp2;
    return head;
}
