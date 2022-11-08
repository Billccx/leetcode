#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    vector<vector<int>> v={
        {0,5,15,40,80,90,95,98,100},
        {0,5,15,40,60,70,73,74,75},
        {0,4,26,40,45,50,51,52,53},
    };

    vector<vector<int>> dp(3,vector<int>(10));
    vector<vector<int>> path(3,vector<int>(10));

    //dp[i][j] 对于前i件商品，共投入j元，获得的最大收益
    //path[i][j] 对于前i件商品，共投入j元，获得最大收益时，在第i件商品上的投资
    for(int i=0;i<9;i++) dp[0][i]=v[0][i];
    for(int i=1;i<3;i++){
        for(int j=1;j<9;j++){
            int p=0;
            int maxp=0;
            for(int k=0;k<=j;k++){
                if(maxp<dp[i-1][k]+v[i][j-k]){
                    maxp=dp[i-1][k]+v[i][j-k];
                    p=j-k;
                }
            }
            dp[i][j]=maxp;
            path[i][j]=p;
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<=8;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<=8;j++){
            cout<<path[i][j]<<' ';
        }
        cout<<endl;
    }

    cout<<dp[2][8]<<endl;


    int p=2;
    int sum=8;
    while(p>=0){
        cout<<"项目"<<p+1<<":投入"<<path[p][sum]<<endl;
        sum-=path[p][sum];
        p--;
    }



}