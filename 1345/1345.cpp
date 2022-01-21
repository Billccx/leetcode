#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <string>
using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {

        // if(arr.size()==8 && arr[0]==7 &&arr[1]==6){
        //     return 1;
        // }

        unordered_map<int, vector<int> > ump;
        int s=arr.size();
        for(int i=0;i<s;i++){
            ump[arr[i]].push_back(i);
        }

        queue<int> q;
        vector<int> vis(60000),dis(60000);
        vis[0]=1;
        dis[0]=0;
        q.push(0);
        while(!q.empty()){
            int now=q.front();
            q.pop();
            if(now==s-1){
                break;
            }
            if(now-1>=0 && !vis[now-1]){
                vis[now-1]=1;
                dis[now-1]=dis[now]+1;
                q.push(now-1);
            }
            if(now+1<s && !vis[now+1]){
                vis[now+1]=1;
                dis[now+1]=dis[now]+1;
                q.push(now+1);
            }

            if(ump.count(arr[now])){
                for(auto item:ump[arr[now]]){
                    if(!vis[item]){
                        vis[item]=1;
                        dis[item]=dis[now]+1;
                        q.push(item);
                    }
                }
                ump.erase(arr[now]); //优化BFS过程
                //源时间复杂度 edge*edge
                //对于同一个数字构成的完全图，访问过其中任意一个顶点后，再访问到其他的顶点时，再次遍历必然全是false,因为在第一遍都已经访问过了
                //所以把这个图删掉，防止第二次再进行遍历查询vis
            }

            
        }
        return dis[s-1];
    }
};

int main(){
    vector<int> v={11,22,7,7,7,7,7,7,7,22,13};
    Solution s;
    int result=s.minJumps(v);
    cout<<result<<endl;
}