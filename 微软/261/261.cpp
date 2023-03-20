class Solution {
public:
    vector<vector<int>> mp;
    vector<int> vis;
    int n_;

    int dfs(int x){
        //cout<<"vis "<<x<<endl;
        vis[x]=1;
        int cnt=1;
        for(int i=0;i<n_;i++){
            if(!vis[i]&&mp[x][i]){
                cnt+=dfs(i);
            }
        }
        return cnt;
    }


    bool validTree(int n, vector<vector<int>>& edges) {
        n_=n;
        int len=edges.size();
        if(n==1 && len==0) return true;
        mp.resize(n,vector<int>(n));
        vis.resize(n);
        if(n!=len+1) return false;
        unordered_set<int> st;
        for(int i=0;i<len;i++){
            st.insert(edges[i][0]);
            st.insert(edges[i][1]);
            mp[edges[i][0]][edges[i][1]]=1;
            mp[edges[i][1]][edges[i][0]]=1;
        }
        for(int i=0;i<n;i++){
            if(!st.count(i)) return false;
        }

        //cout<<"before dfs"<<endl;
        int cnt=dfs(0);
        if(cnt!=n) return false;
        return true;
    }
};