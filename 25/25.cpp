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