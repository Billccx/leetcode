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