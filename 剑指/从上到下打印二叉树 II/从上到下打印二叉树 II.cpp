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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.emplace(root);
        int cnt=1;
        while(!q.empty()){
            vector<int> v;
            int temp=0;
            for(int i=0;i<cnt;i++){
                TreeNode* now=q.front();
                q.pop();
                v.push_back(now->val);
                if(now->left){
                    q.emplace(now->left);
                    temp++;
                }
                if(now->right){
                    q.emplace(now->right);
                    temp++;
                }
            }
            cnt=temp;
            ans.push_back(v);
        }
        return ans;
    }
};