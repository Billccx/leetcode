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
    TreeNode* build(vector<int>& preorder,vector<int>&inorder,int pl,int il,int ir){
        int root=preorder[pl];
        int p=ump[root];
        TreeNode* now=new TreeNode(root);
        int leftlen=p-il,rightlen=ir-p;
        if(leftlen) now->left=build(preorder,inorder,pl+1,il,p-1);
        if(rightlen) now->right=build(preorder,inorder,pl+leftlen+1,p+1,ir);
        return now;
    }

    unordered_map<int,int> ump;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int len=inorder.size();
        if(!len) return NULL;
        for(int i=0;i<len;i++) ump[inorder[i]]=i;
        return build(preorder,inorder,0,0,len-1);
    }
};