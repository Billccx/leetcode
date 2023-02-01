func minimumOperations(root *TreeNode) (ans int) {
	q := []*TreeNode{root}

	//BFS遍历树
	for len(q) > 0 {
		n := len(q)
		a := make([]int, n)
		tmp := q
		q = nil
		for i, node := range tmp {
			a[i] = node.Val
			if node.Left != nil {
				q = append(q, node.Left)
			}
			if node.Right != nil {
				q = append(q, node.Right)
			}
		}

		id := make([]int, n) // 离散化后的数组
		for i := range id {
			id[i] = i
		}		sort.Slice(id, func(i, j int) bool { return a[id[i]] < a[id[j]] })
		/*
			离散化:
			对于一个元素互异的数组：3，7，6，8
			我们将其映射为从小到大排序后下表的数组
			3，7，6，8
			0，2，1，3 （映射后）

			a[id[i]]表示未排序的离散化数组的第i个元素所对应的a中的元素值


			python写法：
			n = len(a)
			a = sorted(range(n), key=lambda i: a[i])


			C++写法：
			sort(sorted_index.begin(), sorted_index.end(),
				[&](int& a, int& b) -> bool {return floor[a] < floor[b]; }
			);

		*/

		/*
			置换环的数量r，序列长度n
			置换次数n-r

			找环的方法：从第一个数开始，把这个数字当成下标去访问数组，不断循环直到回到这个数本身。

			0，2，1，3

			0 - 0 结束 第一个环
			2 - 1 - 2 结束 第二个环
			3 - 3 结束 第三个环

			4-3=1 最少需要交换1次
		*/
		ans += n
		vis := make([]bool, n)
		for _, v := range id {
			if !vis[v] {
				for ; !vis[v]; v = id[v] {
					vis[v] = true
				}
				ans--
			}
		}
	}
	return
}

/*
作者：灵茶山艾府
链接：https://leetcode.cn/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/solutions/1965422/by-endlesscheng-97i9/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/