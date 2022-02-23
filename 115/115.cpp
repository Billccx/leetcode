#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int sl,tl;
        sl=s.length();
        tl=t.length();
        if(sl<tl) return 0;
        vector<vector<unsigned long long>> dp(sl+1,vector<unsigned long long>(tl+1));
        for(int i=0;i<=sl;i++){
            dp[i][tl]=1;
        }
        for(int i=sl-1;i>=0;i--){
            for(int j=tl-1;j>=0;j--){
                if(s[i]!=t[j]) dp[i][j]=dp[i+1][j];
                else dp[i][j]=dp[i+1][j+1]+dp[i+1][j];
            }
        }
        return dp[0][0];
    }
};

int main(){
    Solution so;
    string s="rabbbit",t="rabbit";
    int result=so.numDistinct(s,t);
    cout<<result<<endl;
}