func lengthOfLongestSubstring(s string) int {
    l:=len(s)
    dp:=make([]int,l)
    pre:=make(map[rune]int)
    ans:=0
    for index,item:=range s{
        if preindex,ok:=pre[item];ok{
            if index-preindex>dp[index-1]{
                dp[index]=dp[index-1]+1
            } else{
                dp[index]=index-preindex
            }
        } else{
            if index==0{
                dp[index]=1
            } else{
                dp[index]=dp[index-1]+1
            } 
        }
        if dp[index]>ans{
            ans=dp[index]
        }
        pre[item]=index
    }
    return ans
}

/*
func lengthOfLongestSubstring(s string) int {
	str := []byte(s)
	dict := map[byte]int{}
	dp := make([]int, len(str))
	maxLen := 0
	for i, val := range str {
		if i == 0 {
			dp[i] = 1
			dict[val] = 0
		} else if closeIndex, ok := dict[val]; !ok {
			dp[i] = dp[i-1] + 1
		} else if dp[i-1] < i-closeIndex {
			dp[i] = dp[i-1] + 1
		} else {
			dp[i] = i - closeIndex
		}
		dict[val] = i
		maxLen = max(dp[i], maxLen)
	}
	return maxLen
}

func max(val1, val2 int) int {
	if val1 > val2 {
		return val1
	}
	return val2
}


作者：jinxycandotailwhip
链接：https://leetcode.cn/problems/zui-chang-bu-han-zhong-fu-zi-fu-de-zi-zi-fu-chuan-lcof/solutions/620978/jian-zhi-offer48zui-chang-bu-han-zhong-f-bpd2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/