#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

//递归打印选择路径
void print(int start,int end, vector<vector<int>>& path){
    int p=path[start][end];

    if(abs(start-p)>1){
        cout<<start+1<<"-"<<p+1<<endl;
        if(abs(start-p)>2) print(start,p,path);
    }
    if(abs(end-p)>1){
        cout<<p+1<<"-"<<end+1<<endl;
        if(abs(end-p)>2) print(p,end,path);
    }
}

int main(){
    vector<vector<int>> v={
        {0, 14, 25, 27, 10, 11, 24, 16},
        {0, 0, 18, 15, 27, 28, 16, 14},
        {0, 0, 0, 19, 14, 19, 16, 10},
        {0, 0, 0, 0, 22, 23, 15, 14},
        {0, 0, 0, 0, 0, 14, 13, 20},
        {0, 0, 0, 0, 0, 0, 15, 18},
        {0, 0, 0, 0, 0, 0, 0, 27},
        {0, 0, 0, 0, 0, 0, 0, 0}
    };

    vector<vector<int>> dp(8,vector<int>(8));
    vector<vector<int>> path(8,vector<int>(8));

    int n=8;
    //初始化dp数组
    for(int i=0;i<n-2;i++){
        dp[i][i+2]=v[i][i+1]+v[i+1][i+2]+v[i][i+2];
    }

    //动态规划推导
    for(int k=3;k<n;k++){
        for(int start=0;start<n-k;start++){
            int end=start+k;
            dp[start][end]=INT_MAX;
            for(int p=start+1;p<end;p++){
                int temp=dp[start][p]+dp[p][end]+v[start][p]+v[p][end]+v[start][end];
                if(temp<dp[start][end]){
                    dp[start][end]=temp;
                    path[start][end]=p;
                } 
            }
        }
    }

    //打印结果和选择路径
    cout<<"最小权重之和:\n"<<dp[0][7]<<endl;
    cout<<"弦的集合T:"<<endl;
    print(0,7,path);
    return 0;
}