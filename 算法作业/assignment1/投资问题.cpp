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

    for(int i=0;i<9;i++) dp[0][i]=v[0][i];
    for(int i=1;i<3;i++){
        for(int j=1;j<9;j++){
            for(int k=0;k<=j;k++){
                dp[i][j]=max(dp[i][j],dp[i-1][k]+v[i][j-k]);
            }
        }
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<8;j++){
            cout<<dp[i][j]<<' ';
        }
        cout<<endl;
    }

    cout<<dp[2][8]<<endl;
}