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
class Solution {
public:

    int deepest=0;
    int sum=0;

    void visit(TreeNode* p,int level){
        if(p->left==nullptr && p->right==nullptr){
            if(level>this->deepest){
                this->deepest=level;
                this->sum=p->val;
            }
            else if(level==this->deepest){
                this->sum+=p->val;
            }
        }
        else{
            if(p->left) visit(p->left,level+1);
            if(p->right) visit(p->right,level+1);
        }

    }

    int deepestLeavesSum(TreeNode* root) {
        visit(root,0);
        return this->sum;
    }
};