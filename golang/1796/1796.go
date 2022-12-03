func secondHighest(s string) int {
	first, second := -1, -1
	for _, v := range s {
		if unicode.IsDigit(v) {
			num := int(v - '0')
			if num > first {
				second = first
				first = num
			} else if second < num && num < first {
				second = num
			}
		}
	}
	return second
}