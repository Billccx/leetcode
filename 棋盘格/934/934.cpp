class Solution {
public:
    vector<vector<int>> step={{1,0},{0,1},{-1,0},{0,-1}};
    int n;

    void dfs(vector<vector<int>>& grid,vector<pair<int,int>>& v0, vector<vector<int>>& vis,int x,int y,int label){

        vis[x][y]=label;
        bool isEdge=false;
        for(int i=0;i<4;i++){
            int nextx=x+step[i][0];
            int nexty=y+step[i][1];

            if(nexty>=0 && nexty<n && nextx>=0 &&nextx<n){
                if(grid[nextx][nexty]==0) isEdge=true;
                else if(grid[nextx][nexty]==1 && vis[nextx][nexty]==0){
                    dfs(grid,v0,vis,nextx,nexty,label);
                }
            }

        }
        if(isEdge) v0.push_back(make_pair(x,y));
    }

    int bfs(vector<vector<int>>& vis,vector<vector<int>>& grid, vector<pair<int,int>>& edge){
        queue<vector<int>> q;
        
        for(int i=0;i<edge.size();i++){
            q.emplace(vector<int>{edge[i].first,edge[i].second,0});
        }

        while(!q.empty()){
            vector<int> now=q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int nextx=now[0]+step[i][0];
                int nexty=now[1]+step[i][1];
                if(nexty>=0 && nexty<n && nextx>=0 &&nextx<n){
                    if(grid[nextx][nexty]==0 && vis[nextx][nexty]==0){
                        vis[nextx][nexty]=1; 
                        q.emplace(vector<int>{nextx,nexty,now[2]+1});
                    }
                    else if(grid[nextx][nexty]==1 && vis[nextx][nexty]==0 ) return now[2];
                }
            }
        }
        return 0;
    }

    int shortestBridge(vector<vector<int>>& grid) {
        vector<pair<int,int>> v0;
        n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n));
        int label=1;
        bool isFind=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    dfs(grid,v0,vis,i,j,label);
                    isFind=true;
                    break;
                }
            }
            if(isFind) break;
        }

        
        int ans=bfs(vis,grid,v0);
        return ans;
    }
};