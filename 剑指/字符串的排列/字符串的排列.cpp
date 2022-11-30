class Solution {
public:
    set<string> ans;
    string mp;
    void dfs(vector<int>&vis,string s,int len){
        if(s.length()==len){
            ans.insert(s);
            return;
        }
        for(int i=0;i<len;i++){
            if(!vis[i]){
                vis[i]=1;
                string temp=s+mp[i];
                dfs(vis,temp,len);
                vis[i]=0;
            }
        }
        return;
    }

    vector<string> permutation(string s) {
        vector<int> vis(8);
        int len=s.length();
        mp=s;
        dfs(vis,"",len);
        vector<string> ret;
        for(auto item:ans) ret.push_back(item);
        return ret;
    }
};