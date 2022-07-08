class Solution {
public:

    void reverseList(ListNode* pre, ListNode* start, ListNode* end, ListNode* post){
        ListNode* p=pre;
        ListNode* q=start;
        while(p!=end){
            ListNode* temp=q->next;
            q->next=p;
            p=q;
            q=temp;
        }
        if(pre!=nullptr) pre->next=end;
        start->next=post;
        return;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* newHead=nullptr;
        ListNode* pre=nullptr;

        while(head!=nullptr){
            ListNode* end=head;
            int cnt=1;
            while(cnt<k && end->next!=nullptr){
                cnt++;
                end=end->next;
            }
            if(cnt!=k) break;
            cout<<"strat:"<<head->val<<" end:"<<end->val<<endl;
            if(pre) cout<<"pre"<<pre->val<<endl;
            else cout<<"pre null"<<endl;
            ListNode* temp=end->next; //下次起点
            if(temp) cout<<"post"<<temp->val<<endl;
            else cout<<"post null"<<endl;
            reverseList(pre,head,end,temp);
            if(newHead==nullptr) newHead=end;
            pre=head;
            head=temp;
        }
        return newHead;
    }
};


/*
class Solution {
public:
    // 翻转一个子链表，并且返回新的头与尾
    pair<ListNode*, ListNode*> myReverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* hair = new ListNode(0);
        hair->next = head;
        ListNode* pre = hair;

        while (head) {
            ListNode* tail = pre;
            // 查看剩余部分长度是否大于等于 k
            for (int i = 0; i < k; ++i) {
                tail = tail->next;
                if (!tail) {
                    return hair->next;
                }
            }
            ListNode* nex = tail->next;
            // 这里是 C++17 的写法，也可以写成
            // pair<ListNode*, ListNode*> result = myReverse(head, tail);
            // head = result.first;
            // tail = result.second;
            tie(head, tail) = myReverse(head, tail);
            // 把子链表重新接回原链表
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return hair->next;
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/reverse-nodes-in-k-group/solution/k-ge-yi-zu-fan-zhuan-lian-biao-by-leetcode-solutio/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


*/

