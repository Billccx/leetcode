class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> g(101,vector<int>(0));
        cout<<g[1].size()<<endl;
        int len=edges.size();
        for(int i=0;i<len;i++){
            g[edges[i][0]].push_back(edges[i][1]);
            g[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> vis(101);
        queue<pair<int,double>> q;
        q.push(make_pair(1,1));
        vis[1]=true;
        int t_=0;
        while(t_<t){
            vector<pair<int,double>> v;
            while(!q.empty()){
                auto temp=q.front();
                v.push_back(temp);
                q.pop();
            }
            for(int i=0;i<v.size();i++){
                int p=v[i].first;
                vis[p]=true;
                int cnt=0;
                vector<int> next; 
                for(int j=0;j<g[p].size();j++){
                    if(!vis[g[p][j]]){
                        cnt++;
                        next.push_back(g[p][j]);
                    }
                }
                
                if(!cnt){
                    q.push(v[i]);
                }
                else{
                    double prob=v[i].second/cnt;
                    for(int j=0;j<next.size();j++){
                        q.push(make_pair(next[j],prob));
                    }
                }
            }
            t_++;
        }
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            if(p.first==target) return p.second;
        }
        return 0;
    }
};