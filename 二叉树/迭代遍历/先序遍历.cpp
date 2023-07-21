stack<TreeNode*> s;
s.push(root);
while(!s.empty()){
    TreeNode* p=s.top();
    s.pop();
    if(p->right) s.push(p->right);
    if(p->left) s.push(p->left);
}