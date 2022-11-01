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
    bool visit(TreeNode* A,TreeNode* B){
        if(!B) return true;
        else if(!A) return false;

        if(A->val!=B->val) return false;
        bool lr=visit(A->left,B->left);
        bool rr=visit(A->right,B->right);
        if(lr && rr) return true;
        else return false;
    }

    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if(!B) return false;
        bool r=visit(A,B);
        if(r) return true;
        if(A->left){
            bool lr=isSubStructure(A->left,B);
            if(lr) return true;
        }
        if(A->right){
            bool rr=isSubStructure(A->right,B);
            if(rr) return true;
        }
        return false;
    }
};

/*
思路
visit函数用于判断从当前节点开始，B是不是位于当前节点的子结构

isSubStructure函数用于判断A中是否包含B这样的子结构

visit是硬性的，中间不可有任何差异的

*/