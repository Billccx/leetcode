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

/*
func decodeMessage(key string, message string) string {
    cur := byte('a')
    rules := map[rune]byte{}

    for _, c := range key {
        if c != ' ' && rules[c] == 0 {
            rules[c] = cur
            cur++
        }
    }

    m := []byte(message)
    for i, c := range message {
        if c != ' ' {
            m[i] = rules[c]
        }
    }

    return string(m)
}

作者：力扣官方题解
链接：https://leetcode.cn/problems/decode-the-message/solutions/2084137/jie-mi-xiao-xi-by-leetcode-solution-wckx/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

