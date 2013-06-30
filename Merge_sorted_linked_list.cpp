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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        
        ListNode* newList;
        ListNode* endNode; //use this node to track the insert point
        
        if (l1->val < l2->val) {
            newList = l1;
            endNode = newList;
            l1 = l1->next;
        }
        else {
            newList = l2;
            endNode  = newList;
            l2 = l2->next;
        }
        
        while (l1 && l2) {
            
            if (l1->val < l2->val){
                endNode->next = l1;
                l1 = l1->next;
             }
             else {
                endNode->next = l2;
                l2 = l2->next;
             }
             endNode = endNode->next;
        }
        endNode->next = l1? l1:l2;
        return newList;
    }
};
