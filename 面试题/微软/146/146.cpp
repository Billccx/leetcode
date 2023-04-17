/*
双向链表+哈希表
*/

typedef struct node{
    int key,data;
    struct node *next,*pre;
    node(){
        data=0;
        key=-1;
        next=pre=nullptr;
    }
    node(int k, int v){
        key=k;
        data=v;
        next=pre=nullptr;
    }
}Node;


class LRUCache {
public:
    int size;
    int cap;
    Node* head;
    Node* tail; 
    unordered_map<int,Node*> ump;
    LRUCache(int capacity) {
        size=0;
        cap=capacity;
        head=new Node();
        tail=new Node();
        head->pre=tail->next=nullptr;
        head->next=tail;
        tail->pre=head;
    }

    void print(){
        Node* p=head->next;
        while(p!=tail){
            cout<<p->data<<"->";
            p=p->next;
        }
        cout<<endl;

        p=tail->pre;
        while(p!=head){
            cout<<p->data<<"->";
            p=p->pre;
        }
        cout<<endl;
    }
    
    int get(int key) {
        //cout<<"get:"<<key<<endl;
        if(!ump.count(key)) return -1;
        Node* temp=ump[key];
        temp->pre->next=temp->next;
        temp->next->pre=temp->pre;

        temp->next=head->next;
        temp->pre=head;
        head->next=temp;
        temp->next->pre=temp;
        //cout<<"return:"<<temp->data<<endl;
        //print();
        return temp->data;
    }
    
    void put(int key, int value) {
        //cout<<"put:"<<key<<','<<value<<endl;

        if(ump.count(key)){
            ump[key]->data=value;
            Node* temp=ump[key];
            temp->pre->next=temp->next;
            temp->next->pre=temp->pre;
            temp->next=head->next->next;
           
            temp->next=head->next;
            temp->pre=head;
            head->next=temp;
            temp->next->pre=temp;
        }
        else{
            if(size==cap){
                size--;
                ump.erase(tail->pre->key);
                Node* temp=tail->pre->pre;
                temp->next=tail;
                tail->pre=temp;
                
            }
            size++;
            Node* tnext=head->next;
            Node* temp=new Node(key,value);
            ump[key]=temp;
            temp->next=tnext;
            head->next=temp;
            tnext->pre=temp;
            temp->pre=head;
        } 
        //print();     
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */