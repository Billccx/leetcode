class Solution {
public:
    vector<double> dicesProbability(int n) {
        vector<vector<double>> dp(12,vector<double>(70));
        for(int i=1;i<=6;i++){
            dp[1][i]=1.0/6.0;
        }
        for(int i=2;i<=n;i++){
            for(int j=i;j<=i*6;j++){
                int t=min(7,j);
                for(int k=1;k<t;k++){
                    dp[i][j]+=dp[i-1][j-k]*1.0/6.0;
                }
            }
        }

    // for(int j=1;j<=3;j++){
    //     for(int i=1;i<=18;i++){
    //         cout<<dp[j][i]<<' ';
    //     }
    //     cout<<endl;
    // }

        vector<double> ans;
        for(int i=n;i<=n*6;i++) ans.push_back(dp[n][i]);
        return ans;
    }
};