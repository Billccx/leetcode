class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> dis(101,vector<int>(101,INT_MAX));
        vector<vector<int>> next={{0,1},{1,1},{1,0},
                                  {1,-1},{0,-1},{-1,-1},
                                  {-1,0},{-1,1}};

        queue<pair<int,int>> q;
        if(grid[0][0]) return -1;
        q.push(make_pair(0,0));
        dis[0][0]=1;
        while(!q.empty()){
            auto now=q.front();
            q.pop();
            for(int i=0;i<8;i++){
                int x=now.first+next[i][0];
                int y=now.second+next[i][1];
                if(x<0 || x>=n ||y<0 ||y>=n) continue;
                int d=dis[now.first][now.second]+1;
                if(grid[x][y]==0 && d<dis[x][y]){
                    q.push(make_pair(x,y));
                    dis[x][y]=d;
                }
            }
        }

        return dis[n-1][n-1]==INT_MAX?-1:dis[n-1][n-1];
    }
};