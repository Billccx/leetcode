class Solution {
public:
    vector<string> ans;
    string mp;
    void dfs(vector<int>&vis,string s,int len){
        if(s.length()==len){
            ans.push_back(s);
            return;
        }
        int i=0;
        while(i<len){
            if(!vis[i]){
                vis[i]=1;
                string temp=s+mp[i];
                dfs(vis,temp,len);
                vis[i]=0;
                while(i+1<len && mp[i+1]==mp[i])i++;
            }
            i++;
        }
        return;
    }

    vector<string> permutation(string s) {
        vector<int> vis(8);
        sort(s.begin(),s.end());
        
        int len=s.length();
        mp=s;
        cout<<mp<<endl;
        dfs(vis,"",len);
        return ans;
    }
};


/*
a b b b c c c
  * --> *
当dfs for循环到b处时，下一个直接搜索c位置，防止重复
*/