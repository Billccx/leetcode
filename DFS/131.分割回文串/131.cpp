class Solution {
public:
    vector<vector<string>> ans;
    void dfs(int x, string s,vector<string>& v){
        if(x==1){
            v.emplace_back(s);
            dfs(0,"",v);
            v.pop_back();
        }
        else if(x==0){
            bool flag=true;
            for(auto item:v){
                string item2=item;
                reverse(item2.begin(),item2.end());
                if(item!=item2){
                    flag=false;
                    break;
                }
            }
            if(flag) ans.emplace_back(v);
        }
        else{
            int l=s.length();
            for(int i=1;i<=l-x+1;i++){
                string sub=s.substr(0,i);
                string rest=s.substr(i);
                v.emplace_back(sub);
                dfs(x-1,rest,v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        int n=s.length();
        for(int i=1;i<=n;i++){
            vector<string> tmp;
            dfs(i,s,tmp);
        }
        return ans;
    }
};