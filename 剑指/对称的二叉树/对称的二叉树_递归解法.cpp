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
    bool dfs(TreeNode* A,TreeNode* B){
        if(!A && !B) return true;
        else if(!A || !B) return false;
        if(A->val!=B->val) return false;
        bool lr=dfs(A->left,B->right);
        bool rr=dfs(A->right,B->left);
        if(lr && rr) return true;
        else return false;
    }

    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        bool result=dfs(root->left,root->right);
        return result;
    }
};

/*
上述解法采用程序遍历，然后检查每层的节点是否对称
但这并不是最简单的迭代解法

我们可以"每次"检查一层中对称的两个位置上的节点值是否相同

下列解法中

q.push(u->left); 
q.push(v->right);
//将两个对称位置的节点压入队列

                x
        u               v       
    ul      ur      vl      vr

q(ul,vr)    
        

q.push(u->right); 
q.push(v->left);
q(ul,vr,ur,vl)

while下一轮，弹出队列前两个，还是处于对称位置的
*/



/*
class Solution {
public:
    bool check(TreeNode *u, TreeNode *v) {
        queue <TreeNode*> q;
        q.push(u); q.push(v);
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) continue;
            if ((!u || !v) || (u->val != v->val)) return false;

            q.push(u->left); 
            q.push(v->right);

            q.push(u->right); 
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/symmetric-tree/solution/dui-cheng-er-cha-shu-by-leetcode-solution/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/