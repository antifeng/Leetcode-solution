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
    ListNode *deleteDuplicates(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (!head)
            return NULL;
        ListNode *retNode = head;
        
        while (head->next) {
            //if found duplicated, del it
            if ( head->val == head->next->val ) {
                ListNode* ptmp = head->next;
                head->next = head->next->next;
                delete ptmp;
            }
            else
                head = head->next;
        }//end while
        
        return retNode;
    }
};
