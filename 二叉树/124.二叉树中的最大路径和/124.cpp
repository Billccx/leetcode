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
    int ans=-INT_MAX;
    int solve(TreeNode* p){
        if(!p) return 0;
        int lr=max(solve(p->left),0);
        int rr=max(solve(p->right),0);
        int temp=lr+rr+p->val;
        if(temp>ans) ans=temp;
        return max(0,max(lr,rr)+p->val);
    }



    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};