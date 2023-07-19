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
        int lr=max(solve(p->left),0);//如果左侧递归结果是负值，那还不如不要
        int rr=max(solve(p->right),0);
        int temp=lr+rr+p->val;
        if(temp>ans) ans=temp;  //若不考虑向上返回，则考虑左右递归结果连接起来的值
        return max(0,max(lr,rr)+p->val);  //向上返回时，只需要考虑单侧即可，保证是一条路径，如果小于0，干脆不要
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return ans;
    }
};