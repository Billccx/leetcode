func printBin(num float64) string {
	cnt := 0
	temp := num
	ans := ""
	for cnt < 7 && temp != 0 {
		t := temp * 2
		if t >= 1 {
			ans += "1"
			temp = t - 1
		} else {
			temp = t
			ans += "0"
		}
		cnt++
	}
	if cnt >= 7 {
		return "ERROR"
	} else {
		return "0." + ans
	}
}