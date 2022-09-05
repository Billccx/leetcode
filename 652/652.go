/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func findDuplicateSubtrees(root *TreeNode) []*TreeNode {
	mp := map[[3]int]int{}
	var dfs func(*TreeNode) int
	type subTree struct {
		p   *TreeNode
		cnt int
	}

	subTrees := map[int]subTree{}
	var cnt int

	dfs = func(p *TreeNode) int {
		if p == nil {
			return -1
		}
		key := [3]int{p.Val, dfs(p.Left), dfs(p.Right)}
		index, ok := mp[key]
		if ok == true {
			k := subTrees[index].cnt + 1
			p_ := subTrees[index].p
			subTrees[index] = subTree{p: p_, cnt: k}
			return index
		}

		fmt.Println(key)

		mp[key] = cnt
		subTrees[cnt] = subTree{p: p, cnt: 1}
		cnt++
		return cnt - 1
	}

	dfs(root)

	var ans []*TreeNode
	for _, v := range subTrees {
		if v.cnt > 1 {
			ans = append(ans, v.p)
		}
	}
	return ans

}