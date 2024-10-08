//
// Created by Viljen Apalset Vassbø on 04/10/2024.
//
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <set>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *head;
        ListNode *trav;
        ListNode* l = list1;
        ListNode* r = list2;
        while(l!=nullptr && r!= nullptr) {
            if(l->val<r->val) {
                trav->next = l;
                l = l->next;
            }
            else {
                trav->next = r;
                r = r->next;
            }
            trav = trav->next;
        }
        while(l!=nullptr){
            trav -> next = l;
            l = l->next;
        }
        while(r!=nullptr){
            trav -> next = r;
            r = r->next;
        }
        return head;
    }
};

int main() {


    return 0;
}