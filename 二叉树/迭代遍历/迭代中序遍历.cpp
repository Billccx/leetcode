//二叉树的中序遍历(迭代)
class Solution2 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> sta;
        vector<int> result;
        TreeNode* node = root;
        while (node != nullptr || !sta.empty()) {
            if (node != nullptr) {
                sta.push(node);
                node = node->left;
            } else {
                node = sta.top();
                sta.pop();
                result.push_back(node->val);
                node = node->right;
            }
        }
        return result;
    }
};