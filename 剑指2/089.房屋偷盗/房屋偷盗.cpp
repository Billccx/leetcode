class Solution {
public:
    int rob(vector<int>& nums) {
        int len=nums.size();
        vector<vector<int>> dp(105,vector<int>(2));
        for(int i=1;i<=len;i++){
            if(i==1) dp[i][1]=nums[i-1];
            else{
                dp[i][0]=max(dp[i-1][1],dp[i][0]);
                dp[i][0]=max(dp[i-1][0],dp[i][0]);

                dp[i][1]=max(dp[i-1][0]+nums[i-1],dp[i][1]);
                dp[i][1]=max(dp[i-2][1]+nums[i-1],dp[i][1]);
            }
        }
        return max(dp[len][0],dp[len][1]);
    }
};

/*
这种写法不好
一维DP即可解决
用 dp[i] 表示前 i 间房屋能偷窃到的最高总金额
dp[i]=max(dp[i-1],dp[i-2]+nums[i])
*/