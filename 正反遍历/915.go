func partitionDisjoint(nums []int) int {
	l := len(nums)
	v := make([]int, l)
	v2 := make([]int, l)
	m := nums[0]
	for i := 0; i < l; i++ {
		if nums[i] > m {
			m = nums[i]
		}
		v[i] = m
	}

	m = nums[l-1]
	for i := l - 1; i >= 0; i-- {
		if nums[i] < m {
			m = nums[i]
		}
		v2[i] = m
	}

	ans := 0
	for i := 0; i < l; i++ {
		if v[i] <= v2[i+1] {
			ans = i + 1
			break
		}
	}

	return ans
}