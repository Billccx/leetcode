#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <queue>
using namespace std;
class Solution {
private:
    vector<vector<int>> step={{1,0},{-1,0},{0,1},{0,-1}};
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> vis(isWater.size(), vector<int>(isWater[0].size()));
        vector<vector<int>> dis(isWater.size(), vector<int>(isWater[0].size()));
        queue<vector<int>> q;

        for(int i=0;i<isWater.size();i++){
            for(int j=0;j<isWater[0].size();j++){
                if(isWater[i][j]){
                    q.push(vector<int>{i,j});
                    vis[i][j]=1;
                }  
            }
        }

        while(!q.empty()){
            //cout<<"now in queue: "<<q.size()<<endl;
            
            vector<int> now=q.front();
            q.pop();
            //cout<<"{"<<now[0]<<","<<now[1]<<"}"<<endl;
            for(int i=0;i<4;i++){
                int x=now[0]+step[i][0];
                int y=now[1]+step[i][1];
                if(x>=isWater.size() || x<0 || y<0 || y>=isWater[0].size() || vis[x][y]==1){
                    //cout<<"{"<<x<<","<<y<<"}  discard"<<endl;
                    continue;
                }
                else{
                    vis[x][y]=1;
                    dis[x][y]=dis[now[0]][now[1]]+1;
                    q.push(vector<int>{x,y});
                    //cout<<"{"<<x<<","<<y<<"}"<<"push"<<endl;
                }
            }
        }
        return dis;
    }
    
};

int main(){
    Solution s;
    vector<vector<int>> v={{0,0,1},{1,0,0},{0,0,0}};
    vector<vector<int>> result=s.highestPeak(v);
    for(int i=0;i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<' ';
        }
        cout<<endl;
    }
}