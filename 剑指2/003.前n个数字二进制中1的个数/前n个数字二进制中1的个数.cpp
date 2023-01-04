class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> dp(n+1);
        for(int i=1;i<=n;i++){
            if(i&(i-1)){
                dp[i]=dp[i&(i-1)]+1;
            }
            else dp[i]=1;
        }
        return dp;
    }
};

/*
n&(n-1)的作用是将n二进制表示中为1的最低位改为0
譬如
n=1000110
n&(n-1)=1000100

由此可知，i和i&(i-1)的二进制为1的个数相差1,因此直接dp记录子问题即可

*/