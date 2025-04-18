/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* temp=head;
    int count=0;
    while(temp!=NULL){
        temp=temp->next;
        count=count+1;

    }
     if (count == n) {
        struct ListNode* newHead = head->next;
        free(head);
        return newHead;
    }
    struct ListNode* tempa=head;
    for(int i=0;i<count-n-1;i++){
        tempa=tempa->next;

    }
    struct ListNode* tem=tempa->next;
     tempa->next=tempa->next->next;
    free(tem);
   
   return head;
}
