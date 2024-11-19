
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Create a dummy node to start the linked list
        ListNode* dummy = new ListNode();
        ListNode* temp = dummy;
        int carry = 0;
        
        // Traverse both linked lists
        while(l1 != NULL || l2 != NULL || carry) {
            int sum = 0;
            
            // Add the values of the nodes
            if(l1 != NULL) {
                sum += l1->val;
                l1 = l1->next;
            }
            
            if(l2 != NULL) {
                sum += l2->val;
                l2 = l2->next;
            }
            
            // Add the carry from the previous sum
            sum += carry;
            carry = sum / 10;
            
            // Create a new node with the sum value
            ListNode* node = new ListNode(sum % 10);
            temp->next = node;
            temp = temp->next;
        }
        
        return dummy->next;

    }
};