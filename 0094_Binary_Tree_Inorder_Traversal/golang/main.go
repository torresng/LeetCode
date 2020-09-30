/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
// Recursive T = O(n), S = O(n)
func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	res := []int{}
	dfs(root, &res)
	return res
}

func dfs(root *TreeNode, res *[]int) {
	if root == nil {
		return
	}
	dfs(root.Left, res)
	*res = append(*res, root.Val)
	dfs(root.Right, res)
}

// Iteration T = O(n), S = O(n)
func inorderTraversal(root *TreeNode) []int {
	if root == nil {
		return nil
	}
	st := []*TreeNode{}
	p := root
	res := []int{}
	for len(st) != 0 || p != nil {
		for p != nil {
			st = append(st, p)
			p = p.Left
		}
		n := len(st)
		p = st[n-1]
		st = st[:n-1]
		res = append(res, p.Val)
		p = p.Right
	}
	return res
}