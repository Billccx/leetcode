class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int len=prices.size();
        if(len==0 || k==0) return 0;
        vector<vector<int>> dp(len,vector<int>(2*k+1));
        for(int i=0;i<dp.size();i++){
            for(int j=0;j<dp[0].size();j++){
                dp[i][j]=-2000;
            }
        }


        int m=-prices[0];
        for(int i=0;i<len;i++){
            if(-prices[i]>m) m=-prices[i];
            dp[i][1]=m;
        }

        for(int i=1;i<=k;i++){
            for(int j=0;j<len;j++){
                if(2*i-1<=j+1){
                    if(j-1>=0 && 2*i-2>0)  
                        dp[j][2*i-1]=max(dp[j-1][2*i-1],dp[j-1][2*i-2]-prices[j]);
                }
            }

            for(int j=0;j<len;j++){
                if(2*i<=j+1){
                    if(j-1>=0 && 2*i-1>0) 
                        dp[j][2*i]=max(dp[j-1][2*i],dp[j-1][2*i-1]+prices[j]);
                }
            }
        }

        int ans=0;

        // for(int i=0;i<len;i++){
        //     for(int j=1;j<=2*k;j++){
        //         cout<<dp[i][j]<<' ';
        //     }
        //     cout<<endl;
        // }

        for(int i=1;i<=k;i++){
            if(dp[len-1][2*i]>ans) ans=dp[len-1][2*i];
        }
        return ans;

    }
};