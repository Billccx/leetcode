func pivotIndex(nums []int) int {
	l := len(nums)
	a := make([]int, l)
	b := make([]int, l)
	sum := 0
	for i := 0; i < l; i++ {
		a[i] = sum
		sum += nums[i]
	}
	sum = 0
	for i := 0; i < l; i++ {
		b[i] = sum
		sum += nums[l-1-i]
	}

	for i := 0; i < l; i++ {
		if a[i] == b[l-1-i] {
			return i
		}
	}
	return -1
}