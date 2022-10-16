class Solution {
public:
    bool dfs(int index,int group,vector<vector<int>>& v, vector<int>& mp){
        mp[index]=group;
        int l=v[index].size();
        for(int i=0;i<l;i++){
            if(mp[v[index][i]] && mp[v[index][i]]==group) return false;
            else if(!mp[v[index][i]]){
                bool res=dfs(v[index][i],3-group,v,mp);
                if(!res) return false;
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int m=dislikes.size();
        vector<vector<int>> v(n+1); //临界矩阵
        vector<int> mp(n+1); //记录染色情况
        for(int i=0;i<m;i++){
            v[dislikes[i][0]].push_back(dislikes[i][1]);
            v[dislikes[i][1]].push_back(dislikes[i][0]);
        }

        for(int i=1;i<=n;i++){
            if(!mp[i]){
                bool res=dfs(i,1,v,mp);
                if(!res) return false;
            }
        }
        return true;
    }
};


/*
思路

本题是一个二分图
互相排斥的两个人建一条边，边只存在于两个集合之间

我们知道，点集由几个团组成，如果有散点的话，那么分到哪边都是可行的
而团与团之间的染色情况是互不影响的

因此我们只需要遍历所有的点，如果发现这个点是一个新团的开始，则随意为其染色，然后dfs检查该团中剩下的点
染色是否会出现冲突，若没有，我们便一次性解决了这个团的染色问题。之后继续遍历，遇到下一个团的开始，如此往复。

只要遍历完成后仍没有冲突，则可以染色

*/