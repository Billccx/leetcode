class MyLinkedList {
public:
    ListNode* head;
    MyLinkedList(){
        head=new ListNode();
    }

    
    int get(int index) {
        ListNode* p=head->next;
        int i=0;
        while(p!=NULL && i<index){
            p=p->next;
            i++;
        }
        if(i!=index || p==NULL) return -1;
        else return p->val;
        
    }
    
    void addAtHead(int val) {
        ListNode* p=new ListNode(val);
        p->next=head->next;
        head->next=p;
    }
    
    void addAtTail(int val) {
        ListNode* p=head;
        while(p->next!=NULL) p=p->next;
        ListNode* t=new ListNode(val);
        p->next=t;
    }
    
    void addAtIndex(int index, int val) {
        if(index<0){
            addAtHead(val);
            return;
        } 

        ListNode* q=head;
        ListNode* p=head->next;
        int i=0;
        while(p!=NULL && i<index){
            p=p->next;
            q=q->next;
            i++;
        }
        if(i<index) return;
        else{
            ListNode* n=new ListNode(val);
            n->next=p;
            q->next=n;
            return;
        }
    }
    
    void deleteAtIndex(int index) {
        int i=0;
        if(index<0) return;
        ListNode* p=head->next,* q=head;
        while(p!=NULL && i<index){
            p=p->next;
            q=q->next;
            i++;
        }
        if(i<index || p==NULL) return;
        else{
            q->next=p->next;
            return;
        }
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */