/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    TreeNode *p;
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root):p(nullptr) {
        TreeNode* tmp=root;
        while(tmp){
            s.emplace(tmp);
            tmp=tmp->left;
        }
    }
    
    int next() {
        p=s.top();
        s.pop();
        int ans=p->val;
        if(p->right){
            p=p->right;
            while(p){
                s.emplace(p);
                p=p->left;
            }
        } 
        return ans;
    }
    
    bool hasNext() {
        if(!s.empty()) return true;
        else return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */