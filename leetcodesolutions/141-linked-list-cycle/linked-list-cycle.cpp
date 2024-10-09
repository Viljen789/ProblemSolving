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
    bool hasCycle(ListNode *head) {
        ListNode *slow = head; 
        if(!head || !(head->next))return 0;
        ListNode *fast = head->next;
        while(slow!=fast){
            if(!fast->next || !fast->next->next)return 0;
            fast = fast->next->next;
            slow = slow->next;          
        }
        return 1;
    }
};