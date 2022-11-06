class Solution {
public:
	int minScoreTriangulation(vector<int>& A) {
		int dp[55][55], len = A.size();
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < len - 2; i++) {
			dp[i][i + 2] = A[i] * A[i + 1] * A[i + 2];
		}
		for (int k = 3; k < len; k++) {
			for (int i = 0; i < len - k; i++) {
				int j = i + k, temp = 1e9;
				for (int l = i + 1; l < j; l++) {
					temp = min(temp, dp[i][l] + dp[l][j] + A[i] * A[j] * A[l]);
				}
				dp[i][j] = temp;
			}
		}
		return dp[0][len - 1];
	}
};