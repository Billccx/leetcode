func arrayStringsAreEqual(word1 []string, word2 []string) bool {
	var p1, p2, i, j int
	for p1 < len(word1) && p2 < len(word2) {
		if word1[p1][i] != word2[p2][j] {
			return false
		} else {
			i++
			j++
			if i == len(word1[p1]) {
				i = 0
				p1++
			}
			if j == len(word2[p2]) {
				j = 0
				p2++
			}
		}
	}
	if p1 < len(word1) || p2 < len(word2) {
		return false
	}
	return true
}