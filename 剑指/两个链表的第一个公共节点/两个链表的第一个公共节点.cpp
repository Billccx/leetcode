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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        auto p=headA,q=headB;
        if(!p||!q) return NULL;
        while(q||p){
            if(!p&&q) p=headB;
            else if(p&&!q) q=headA;
            else{
                if(p==q) return p;
                p=p->next;
                q=q->next;
            }
        }
        return NULL;
    }
};