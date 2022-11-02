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
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        queue<TreeNode*> q;
        q.emplace(root);
        while(!q.empty()){
            int l=q.size();
            if(l==1){
                TreeNode* now=q.front();
                q.pop();
                q.emplace(now->left);
                q.emplace(now->right);
            }
            else{
                stack<TreeNode*> s;
                for(int i=0;i<l/2;i++){
                    TreeNode* now=q.front();
                    q.pop();
                    s.emplace(now);
                    if(now){
                        q.emplace(now->left);
                        q.emplace(now->right);
                    }
                }

                for(int i=0;i<l/2;i++){
                    TreeNode* now=q.front();
                    TreeNode* now2=s.top();
                    q.pop();
                    s.pop();
                    if((!now && !now2) || (now && now2 && (now->val==now2->val))){
                        if(now){
                            q.emplace(now->left);
                            q.emplace(now->right);
                        }
                    }
                    else{
                        return false;
                    }
                }

            }
        }
        return true;
    }
};