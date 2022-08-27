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
    int widthOfBinaryTree(TreeNode* root) {
        queue<TreeNode*> q;
        queue<unsigned long long int> v;
        int ans=1;
        q.push(root);
        v.push(1);
        while(!q.empty()){
            int width=v.back()-v.front()+1,cnt=v.size();
            if(width>ans) ans=width;
            while(cnt>0){
                TreeNode* now=q.front();
                unsigned long long int temp=v.front();
                cout<<temp<<' ';
                q.pop();
                v.pop();
                if(now->left!=nullptr){
                    q.push(now->left);
                    v.push(temp*2-1);
                } 
                if(now->right!=nullptr){
                    q.push(now->right);
                    v.push(temp*2);
                } 
                cnt--;
            }
            cout<<endl;
        }
        return ans;
    }
};