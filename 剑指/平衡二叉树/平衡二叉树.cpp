/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isBal=true;

    int visit(TreeNode* p){
        if(!isBal) return 0;
        if(!p) return 0;
        int lc=visit(p->left);
        int rc=visit(p->right);
        if(abs(lc-rc)>1) isBal=false;
        return max(lc,rc)+1;
    }

    bool isBalanced(TreeNode* root) {
        visit(root);
        return isBal;
    }
};

/*
isBal和节点深度是可以状态可并的
让return -1表示当前节点是不平衡的，其余大于等于0的数字表示当前节点是平衡的，且深度为返回值
*/