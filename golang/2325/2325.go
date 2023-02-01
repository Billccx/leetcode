func decodeMessage(key string, message string) string {
	ump := make(map[rune]int)
	cnt := 0
	for _, c := range key {
		if c == ' ' {
			continue
		}
		_, ok := ump[c]
		if !ok {
			ump[c] = cnt
			cnt++
		}
	}

	var ans []rune
	for _, c := range message {
		r := ' '
		if c != ' ' {
			r = rune(ump[c] + 'a')
		}
		ans = append(ans, r)
	}

	return string(ans)

}