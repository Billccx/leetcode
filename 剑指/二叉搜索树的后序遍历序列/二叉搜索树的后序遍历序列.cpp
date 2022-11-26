class Solution {
public:
    bool visit(vector<int>& v,int start,int end){
        int p=end;
        for(int i=p-1;i>=0&& postorder[i]>postorder[p];i--){
            if(postorder[i]>postorder[p] && postorder[i-1]<postorder[p]){
                return verifyPostorder(v,start,i-1) && verifyPostorder(v,i+1,p-1);
            }
        }

    }

    bool verifyPostorder(vector<int>& postorder) {
        int len=postorder.size();
        bool result=visit(postorder,0,len-1);
        return result;
    }
};