func integerBreak(n int) int {
	dp := make([]int, 58)
	dp[2] = 1
	dp[3] = 2
	dp[4] = 4
	dp[5] = 6
	dp[6] = 9
	for i := 7; i <= n; i++ {
		dp[i] = int(math.Max(float64(dp[i-2]*2), float64(dp[i-3]*3)))
	}
	return dp[n]

}