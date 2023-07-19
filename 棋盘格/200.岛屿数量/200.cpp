class Solution {
public:
    void solve(vector<vector<char>>& grid,vector<vector<int>>& vis,int x,int y){
        vector<vector<int>> d={{1,0},{0,-1},{-1,0},{0,1}};
        int m=grid.size(),n=grid[0].size(); 
        queue<pair<int,int>> q;
        q.push(make_pair(x,y));
        vis[x][y]=1;
        while(!q.empty()){
            auto now=q.front();
            q.pop();
            for(int i=0;i<4;i++){
                int nx=now.first+d[i][0];
                int ny=now.second+d[i][1];
                if(nx<0 || nx>=m || ny<0 || ny>=n || vis[nx][ny] || grid[nx][ny]=='0' ) continue;
                else{
                    vis[nx][ny]=1;
                    q.push(make_pair(nx,ny));
                }
            }
        }
        return;
    }


    int numIslands(vector<vector<char>>& grid) {
        int m=grid.size(),n=grid[0].size(),ans=0;
        vector<vector<int>> vis(m,vector<int>(n));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                    solve(grid,vis,i,j);
                    ans++;
                }
            }
        }
        return ans;
    }
};