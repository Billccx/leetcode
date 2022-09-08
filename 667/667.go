func constructArray(n int, k int) (ans []int) {
	p := n - k + 1
	q := n
	for i := 1; i <= n-k; i++ {
		ans = append(ans, i)
	}
	for i := 1; i <= k; i++ {
		if i%2 == 1 {
			ans = append(ans, q)
			q--
		} else {
			ans = append(ans, p)
			p++
		}
	}
	return ans
}