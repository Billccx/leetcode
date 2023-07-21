//二叉树的后序遍历(迭代)
class Solution3 {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> sta;
        vector<int> result;
        if (root == nullptr) return result;
        else sta.push(root);
        while (!sta.empty()) {
            TreeNode* node = sta.top();
            sta.pop();
            result.push_back(node->val);
            if(node->left != nullptr) sta.push(node->left);
            if(node->right != nullptr) sta.push(node->right);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};