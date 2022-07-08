#include <iostream>
#include <algorithm>
#include <queue>
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
    struct Node{

        int val;
        ListNode* p;
        bool operator <(const Node& a) const{
            return val>a.val;
        }
        Node(int v,ListNode* ptr):val(v),p(ptr){}
    };

    priority_queue<Node> q;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for(auto item:lists){
            if(item) q.push({item->val,item});
        }
        
        ListNode* head=new ListNode();
        ListNode* p=head;

        while(!q.empty()){
            p->next=q.top().p;
            q.pop();
            p=p->next;
            if(p->next)q.push(Node(p->next->val,p->next));
        }
        return head->next;
    }
};

/*
class Solution {
public:
    struct Status {
        int val;
        ListNode *ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }
    };

    priority_queue <Status> q;

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        for (auto node: lists) {
            if (node) q.push({node->val, node});
        }
        ListNode head, *tail = &head;
        while (!q.empty()) {
            auto f = q.top(); q.pop();
            tail->next = f.ptr; 
            tail = tail->next;
            if (f.ptr->next) q.push({f.ptr->next->val, f.ptr->next});
        }
        return head.next;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/merge-k-sorted-lists/solution/he-bing-kge-pai-xu-lian-biao-by-leetcode-solutio-2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/