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
    ListNode *mergeTwoLists(ListNode *left, ListNode *right) {
        if (!left)
            return right;
        if (!right)
            return left;
        
        ListNode* header;
        ListNode* tail; //use this node to track the insert point
        
        //handler the first node of the new list
        if (left->val < right->val) {
            header = left;
            left = left->next;
        }
        else {
            header = right;
            right = right->next;
        }
        tail = header;
        
        while (left && right) {
            if (left->val < right->val){
                tail->next = left;
                left = left->next;
             }
             else {
                tail->next = right;
                right = right->next;
             }
             tail = tail->next;
        }
        tail->next = left? left:right;
        return header;
    }
};
