func uniqueLetterString(s string) int {
	mp := make(map[rune][]int)
	for i, c := range s {
		if _, ok := mp[c]; ok {
			mp[c] = append(mp[c], i)
		} else {
			mp[c] = append(mp[c], -1)
			mp[c] = append(mp[c], i)
		}
	}

	l := len(s)

	//fmt.Println("len:",l)

	ans := 0

	for k, v := range mp {
		mp[k] = append(v, l)
	}

	//fmt.Println(mp)

	for _, v := range mp {
		for i := 1; i < len(v)-1; i++ {
			ans += (v[i] - v[i-1]) * (v[i+1] - v[i])
		}
	}

	return ans
}

/*
func uniqueLetterString(s string) (ans int) {
    idx := map[rune][]int{}
    for i, c := range s {
        idx[c] = append(idx[c], i)
    }
    for _, arr := range idx {
        arr = append(append([]int{-1}, arr...), len(s))
        for i := 1; i < len(arr)-1; i++ {
            ans += (arr[i] - arr[i-1]) * (arr[i+1] - arr[i])
        }
    }
    return
}

作者：LeetCode-Solution
链接：https://leetcode.cn/problems/count-unique-characters-of-all-substrings-of-a-given-string/solution/tong-ji-zi-chuan-zhong-de-wei-yi-zi-fu-b-h9pj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/