#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> step={{1,0},{0,1},{-1,0},{0,-1}};
    unordered_map<int,int> ump;
    vector<vector<int>> vis;
    int n;

    int dfs(int x,int y,int tag,vector<vector<int>>& grid){
        vis[x][y]=tag;
        int sum=1;
        for(int i=0;i<4;i++){
            int nextx=x+step[i][0];
            int nexty=y+step[i][1];
            if(nextx>=0 && nextx<n && nexty>=0 && nexty<n && grid[nextx][nexty]==1 && vis[nextx][nexty]==0){
                sum+=dfs(nextx,nexty,tag,grid);
            }
        }
        return sum;
    }


    int largestIsland(vector<vector<int>>& grid) {
        int tag=1;
        int ans=0;
        n=grid.size();
        for(int i=0;i<n;i++){
            vis.push_back(vector<int>(n));
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    int area=dfs(i,j,tag,grid);
                    ump[tag]=area;
                    tag++;
                    if(area>ans) ans=area;
                }
            }
        }

        // for(int i=0;i<n;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<vis[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }

        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int area=1;
                    unordered_set<int> st;
                    for(int k=0;k<4;k++){
                        int nextx=i+step[k][0];
                        int nexty=j+step[k][1];
                        if(nextx>=0 && nextx<n && nexty>=0 && nexty<n && grid[nextx][nexty]==1){
                            int t=vis[nextx][nexty];
                            if(!st.count(t)){
                                st.insert(t);
                                area+=ump[t];
                            }  
                        }
                        if(area>ans) ans=area;
                    }
                }
            }
        }
        return ans;
        
    }
};

int main(){
    vector<vector<int>> grid={{1,1},{0,1}};
    Solution s;
    int result=s.largestIsland(grid);
    cout<<result<<endl;
}