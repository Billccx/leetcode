#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;

int main(){

}


long long dfs2(int p){
        vis[p]=1;
        int l=ump[p].size();
        for(int i=0;i<l;i++){
            int nx=ump[p][i];
            
            
            

            
            if(!vis[nx]){
                long long cnt=mp[nx]/(long long)seats;
                if(cnt*(long long)seats!=mp[nx]) cnt++;
                ans+=cnt;
            }
        }
    }