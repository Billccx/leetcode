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
    int result;
    int solve(TreeNode* p){
        if(p==nullptr) return 0;
        int rresult=0,lresult=0,lret=0,rret=0,temp=0;


        if(p->left!=nullptr){
            lresult=solve(p->left);
            if(lresult>result) result=lresult;
            if(p->val==p->left->val){
                lret=lresult+1;
            } 
        }
        if(p->right!=nullptr){
            rresult=solve(p->right);
            if(rresult>result) result=rresult;
            if(p->val==p->right->val){
                rret=rresult+1;
            }
        }

        if(p->left!=nullptr && p->right!=nullptr && p->val==p->left->val && p->val==p->right->val){
            temp=rresult+lresult+2;
            if(temp>result) result=temp;
        }
        // cout<<"now:"<<p->val<<" lresult:"<<lresult<<" rresult:"<<rresult<<" temp:"<<temp<<endl;

        int r=max(lret,rret);
        if(r>result) result=r;

        return r;
    }

    int longestUnivaluePath(TreeNode* root) {
        this->result=0;
        int temp=solve(root);
        return result;
    }
};