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
        unordered_map<int, vector<int> > ump;
        int s=arr.size();
        for(int i=0;i<s;i++){
            ump[arr[i]].push_back(i);
        }

        queue<int> q;
        int vis[60000],dis[60000];
        memset(vis,0,sizeof(int));
        memset(dis,0,sizeof(int));
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

            for(auto item:ump[arr[now]]){
                if(!vis[item]){
                    vis[item]=1;
                    dis[item]=dis[now]+1;
                    q.push(item);
                }
            }
        }
        return dis[s-1];
    }
};

int main(){
    vector<int> v={7,6,9,6,9,6,9,7};
    Solution s;
    int result=s.minJumps(v);
    cout<<result<<endl;
}