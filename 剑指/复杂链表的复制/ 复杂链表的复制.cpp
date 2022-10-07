/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*>ump;
        Node* ans=new Node(0),*q=ans;
        for(auto p=head;p!=NULL;p=p->next){
            Node* temp=new Node(p->val);
            ump[p]=temp;
            q->next=temp;
            q=q->next;
        }
        q=ans->next;
        for(auto p=head;p!=NULL;p=p->next){
            if(p->random) q->random=ump[p->random];
            else q->random=NULL;
            q=q->next;
        }
        return ans->next;
    }
};