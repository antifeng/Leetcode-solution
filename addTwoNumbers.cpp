/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        
        if (l1==NULL && l2==NULL)
            return NULL;
        
        ListNode *tail, *header;
        tail = header = NULL;
        int carry = 0;
        while(l1!=NULL || l2!=NULL) {
            if (l1!=NULL){
                carry += l1->val;
                l1 = l1->next;
            }
            if (l2!=NULL){
                carry += l2->val;
                l2 = l2->next;
            }
            if (header==NULL){
                header= new ListNode(carry%10);
                tail = header;
            }
            else{
                tail->next = new ListNode(carry%10);
                tail = tail->next; //be aware that when header==tail, do not move forward
            }
            carry = carry/10;
        }
        if (carry>0) //remember to add last carry
            tail->next = new ListNode(carry);
        return header;
    }
};
