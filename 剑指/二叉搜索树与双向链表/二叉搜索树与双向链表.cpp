/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/
class Solution {
public:
    Node *head,*tail;
    //中序遍历，完成对所有节点前驱的定位
    Node* visit(Node* p,Node* pre){
        //第一个没有左孩子的节点是头节点
        if(!p->left){
            if(!head) head=p;
        } 
        else{
            pre=visit(p->left,pre);
        }
        //若当前节点没有左孩子，那么该节点的前驱是回溯前一层的节点
        //若当前节点有左孩子，那么该节点的前驱是对左子树中序遍历后的最后一个节点，即左子树最右边的节点
        p->left=pre;

        //最后一个没有右孩子的节点是tail
        if(!p->right){
            //如果没有右孩子，那么下一个节点的前驱就是当前节点
            tail=p;
            return p;
        }
        else{
            //如果有右孩子，那么跳出p后下一个节点的前驱是p的右子树的最后一个节点
            return visit(p->right,p);
        }
    }

    Node* treeToDoublyList(Node* root) {
        if(!root) return NULL;
        head=NULL;
        tail=NULL;
        visit(root,head);
        //连接所有前驱节点后，从尾节点延前驱逆向寻找，同时完成各节点后继指针的连接
        for(Node* p=tail;p!=head;p=p->left){
            cout<<p->val<<endl;
            p->left->right=p;
        }
        tail->right=head;
        head->left=tail;
        return head;
    }
};