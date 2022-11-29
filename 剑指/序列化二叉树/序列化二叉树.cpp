/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "_";
        queue<TreeNode*> q;
        q.emplace(root);
        string ret=to_string(root->val)+"_";
        while(!q.empty()){
            TreeNode* now=q.front();
            q.pop();
            if(now->left){
                q.emplace(now->left);
                ret+=to_string(now->left->val)+"_"; 
            }
            else{
                ret+="n_";
            }

            if(now->right){
                q.emplace(now->right);
                ret+=to_string(now->right->val)+"_"; 
            }
            else{
                ret+="n_";
            }
        }
        //cout<<ret<<endl;
        return ret;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="_") return NULL;
        int p=0,q=0;
        queue<TreeNode*> qu;
        while(data[p]!='_') p++;
        TreeNode* r=new TreeNode(stoi(data.substr(q,p-q)));
        qu.emplace(r);
        q=p+1;
        p=q;
        while(!qu.empty()){
            int l=qu.size();
            for(int i=0;i<l;i++){
                TreeNode* now=qu.front();
                qu.pop();
                if(data[p]=='n'){
                    now->left=NULL;
                    q=p+2;
                    p=q;
                }
                else{
                    while(data[p]!='_') p++;
                    now->left=new TreeNode(stoi(data.substr(q,p-q)));
                    q=p+1;
                    p=q;
                    qu.emplace(now->left);
                }
                

                if(data[p]=='n'){
                    now->right=NULL;
                    q=p+2;
                    p=q;
                }
                else{
                    while(data[p]!='_') p++;
                    now->right=new TreeNode(stoi(data.substr(q,p-q)));
                    q=p+1;
                    p=q;
                    qu.emplace(now->right);
                }
                
            }            
        }
        return r;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));