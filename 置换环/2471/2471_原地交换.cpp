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
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*> q;
        q.emplace(root);
        int cnt=1;
        int ans=0;
        while(!q.empty()){
            vector<int> v;
            int temp=0;
            for(int i=0;i<cnt;i++){
                TreeNode* now=q.front();
                q.pop();
                if(now->left){
                    q.emplace(now->left);
                    temp++;
                } 
                if(now->right){
                    q.emplace(now->right);
                    temp++;
                } 
                v.push_back(now->val);
            }

            int len=v.size();
            
            vector<int> v2=v;
            sort(v2.begin(),v2.end());
            unordered_map<int,int> ump;
            for(int i=0;i<len;i++){
                ump[v2[i]]=i;
            }

            /*
            此处直接通过交换来计算操作次数

            也可以计算置换环的数量r,然后用序列长度n减去之，即n-r即为需要交换的最小次数
            https://www.cnblogs.com/CDOI-24374/p/16410082.html
            
            */

            for(int i=0;i<len;i++){
                while(v[i]!=v2[i]){
                    swap(v[i],v[ump[v[i]]]);
                    ans++;
                }
            }
            cnt=temp;
        }
        return ans;
    }
};