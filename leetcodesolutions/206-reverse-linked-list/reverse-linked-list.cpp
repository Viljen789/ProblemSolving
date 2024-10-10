/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* f = head;
        ListNode* back;
        if(!head||!head->next)return head;
        int c = 0;
        while(f){
            c++;
            f = f->next;
        }
        c;
        vector<ListNode*> v(c);
        back = f;
        f = head;
        for(int i = 0; i<c; i++){
            v[i] = f;
            f = f->next;
        }
        cout << c<<endl;
        for(int i = 0; i<c; i++){
            cout << v[i]->val;
        }
        back = v[c-1];
        f = back;
        cout << back->val<<endl;
        
        for(int i = c-2; i>=0; i--){
            f->next = v[i];
            f = f->next;
        }
        f -> next = nullptr;
        
        return back;

        
    }
};