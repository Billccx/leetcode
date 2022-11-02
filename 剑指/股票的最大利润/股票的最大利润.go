func maxProfit(prices []int) int {
	var dp [100000]int
	l := len(prices)
	if l == 0 {
		return 0
	}
	dp[0] = prices[0]
	ans := 0
	for i := 1; i < l; i++ {
		if dp[i-1] < prices[i] {
			dp[i] = dp[i-1]
		} else {
			dp[i] = prices[i]
		}
		temp := prices[i] - dp[i]
		if temp > ans {
			ans = temp
		}
	}
	return ans
}

/*
空间不够优化
不用开dp数组，直接遍历prices，维护至今最小买入价格，同时计算在i处出售获取的利润，实时更新最大值即可

*/

func maxProfit(prices []int) int {
	l := len(prices)
	if l == 0 {
		return 0
	}
	buy := prices[0]
	ans := 0
	for i := 1; i < l; i++ {
		if buy > prices[i] { //如果今天的价格比史低还低，那么最好的策略是今天买入，然后马上卖出，盈利为0，其他情况都要亏钱
			buy = prices[i]
		}
		temp := prices[i] - buy
		if temp > ans {
			ans = temp
		}
	}
	return ans
}

/*
dp思想，通过维护至今的最低价格，省去每次重新遍历取最小的工作
*/