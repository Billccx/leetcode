func minScoreTriangulation(values []int) int {
	n := len(values)
	dp := make([][]int, n)
	for i := 0; i < n; i++ {
		dp[i] = make([]int, n, n)
	}

	for i := 0; i < n-2; i++ {
		dp[i][i+2] = values[i] * values[i+1] * values[i+2]
	}

	//重要的是构造连续的区间表示，以此来应用区间dp
	for k := 3; k < n; k++ {
		for start := 0; start < n-k; start++ {
			end := start + k
			dp[start][end] = math.MaxInt
			for p := start + 1; p < end; p++ {
				temp := dp[start][p] + dp[p][end] + values[start]*values[p]*values[end]
				if temp < dp[start][end] {
					dp[start][end] = temp
				}
			}
		}
	}

	return dp[0][n-1]
}