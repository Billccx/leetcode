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
    vector<vector<string>> mp;
    int depth;
    int n,m;
    void getdepth(TreeNode* p, int d){
        if(p!=nullptr){
            if(d>this->depth) this->depth=d;
            getdepth(p->left,d+1);
            getdepth(p->right,d+1);
        }
        return;
    }

    void print(TreeNode* p, int r, int c){
        if(p==nullptr) return;
        cout<<p->val<<endl;
        cout<<r<<' '<<c<<endl;
        mp[r][c]=to_string(p->val);
        cout<<'success'<<endl;
        print(p->left,r+1,(int)(c-pow(2,depth-r-1)));
        cout<<'left'<<endl;
        print(p->right,r+1,(int)(c+pow(2,depth-r-1)));
        cout<<'right'<<endl;

    }

    vector<vector<string>> printTree(TreeNode* root){
        depth=0;
        getdepth(root,0);
        this->m=depth+1;
        this->n=(int)(pow(2,depth+1)-1);
        mp.resize(m,vector<string>(n));
        print(root,0,(n-1)/2);
        return this->mp;
    }
};