class Solution {
public:
    bool visit(vector<int>& v,int start,int end){
        if(start>=end) return true;
        int p=end,target=v[p];
        int q=p-1;
        while(q>=start){
            if(v[q]>target) q--;
            else break;
        }
        //cout<<"pivtal:"<<q<<endl;
        if(q<start) return visit(v,start,end-1);
        for(int i=start;i<=q;i++){
            if(v[i]>target) return false;
        }
        return visit(v,start,q) && visit(v,q+1,end-1);
    }

    bool verifyPostorder(vector<int>& postorder) {
        int len=postorder.size();
        bool result=visit(postorder,0,len-1);
        return result;
    }
};