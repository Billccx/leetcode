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
    ListNode* solve(ListNode* p){  
        if(!p->next) return p;
        ListNode* q=solve(p->next); 
        p->next->next=p;
        p->next=nullptr;
        return q;
    }

    ListNode* reverseList(ListNode* head) {
        if(!head) return nullptr;
        ListNode* ans=solve(head);
        
        return ans;
    }
};