/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    } else if (head->next == NULL) {
        return head;
    }
    else{
        struct ListNode *temp1=head;
        struct ListNode *temp2=head->next;
        while(temp1!=NULL && temp2!=NULL){
            int val=temp1->val;
            temp1->val=temp2->val;
            temp2->val=val;
            temp1=temp2->next;
            if(temp1!=NULL){
                temp2=temp1->next;
            }
        }
    }
    return head;
}
