/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func max(a int, b int) int {
	if a >= b {
		return a
	}
	return b
}

// recursion
func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	left := maxDepth(root.Left)
	right := maxDepth(root.Right)
	return max(left, right) + 1
}

// iteration
func maxDepth(root *TreeNode) int {
	if root == nil {
		return 0
	}
	q := []*TreeNode{root}
	res := 0
	for len(q) != 0 {
		res++
		tmp := []*TreeNode{}
		for _, p := range q {
			if p.Left != nil {
				tmp = append(tmp, p.Left)
			}
			if p.Right != nil {
				tmp = append(tmp, p.Right)
			}
		}
		q = tmp
	}
	return res
}