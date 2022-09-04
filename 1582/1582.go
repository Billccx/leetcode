func numSpecial(mat [][]int) int {
	rlen := len(mat)
	clen := len(mat[0])
	rowcnt := make([]int, rlen)
	colcnt := make([]int, clen)

	cnt := 0

	for i := 0; i < rlen; i++ {
		for j := 0; j < clen; j++ {
			if mat[i][j] == 1 {
				rowcnt[i]++
				colcnt[j]++
			}
		}
	}

	for i := 0; i < rlen; i++ {
		for j := 0; j < clen; j++ {
			if mat[i][j] == 1 && rowcnt[i] == 1 && colcnt[j] == 1 {
				cnt++
			}
		}
	}
	return cnt
}