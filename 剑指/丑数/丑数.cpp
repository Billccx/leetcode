class Solution {
public:
    vector<int> ans;
    int n;

    void dfs(string x,int level){
        if(level==n+1){
            if(x=="") return;
            else ans.push_back(stoi(x));
            return;
        } 
        for(int i=0;i<=9;i++){
            if(x.length()==0 && i==0){
                dfs(x,level+1);
            }
            else dfs(x+to_string(i),level+1);
        }
        return;
    }

    vector<int> printNumbers(int n) {
        this->n=n;
        dfs("",1);
        return ans;
    }
};