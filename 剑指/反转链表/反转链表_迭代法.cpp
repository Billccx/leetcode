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
    ListNode* reverseList(ListNode* head) {
        ListNode *pre=nullptr,*now=head;
        while(now){
            ListNode* nxt=now->next;
            now->next=pre;
            pre=now;
            now=nxt;
        }
        return pre;
    }
};