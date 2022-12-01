func nearestValidPoint(x int, y int, points [][]int) int {
	var ans, dis int
	dis = 10005
	ans = -1
	for i, p := range points {
		if p[0] == x || p[1] == y {
			var temp int
			if p[0] == x {
				if p[1] > y {
					temp = p[1] - y
				} else {
					temp = y - p[1]
				}
			} else if p[1] == y {
				if p[0] > x {
					temp = p[0] - x
				} else {
					temp = x - p[0]
				}
			}
			if temp < dis {
				dis = temp
				ans = i
			}
		}
	}
	return ans
}

/*
func nearestValidPoint(x, y int, points [][]int) int {
    ans := -1
    minDist := math.MaxInt32
    for i, p := range points {
        if p[0] == x || p[1] == y {
            dist := abs(p[0]-x) + abs(p[1]-y)
            if dist < minDist {
                minDist = dist
                ans = i
            }
        }
    }
    return ans
}

func abs(x int) int {
    if x < 0 {
        return -x
    }
    return x
}

作者：力扣官方题解
链接：https://leetcode.cn/problems/find-nearest-point-that-has-the-same-x-or-y-coordinate/solutions/1998633/zhao-dao-zui-jin-de-you-xiang-tong-x-huo-x900/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


*/