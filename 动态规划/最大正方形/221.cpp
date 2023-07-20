class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m=matrix.size(),n=matrix[0].size();
        vector<vector<int>> dp(m+1,vector<int>(n+1));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(matrix[i-1][j-1]=='1'){
                    //dp[i][j]表示以（i，j)为正方形的右下顶点，最大边长是多少
                    //dp[i][j]状态转移需要考虑，(i-1,j),(i-1,j-1),(i,j-1)3个点
                    dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
                }
            }
        }
        int ans=0;
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(dp[i][j]>ans) ans=dp[i][j];
            }
        }
        return ans*ans;
    }
};