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
    int visit(TreeNode* p,int limit,int sum){
        int temp=sum+p->val;
        if(!p->left && !p->right) return temp;
        temp=-INT_MAX;
        if(p->left){
            int l=visit(p->left,limit,sum+p->val);
            if(l<limit) p->left=nullptr;
            temp=max(temp,l);
        }
        if(p->right){
            int r=visit(p->right,limit,sum+p->val);
            if(r<limit) p->right=nullptr;
            temp=max(temp,r);
        }
        return temp;
    }


    TreeNode* sufficientSubset(TreeNode* root, int limit) {
        int ans=visit(root,limit,0);
        if(ans<limit) root=nullptr;
        return root;
    }
};