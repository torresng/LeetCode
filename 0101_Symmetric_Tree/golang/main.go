/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// recursion
func dfs(p *TreeNode, q *TreeNode) bool {
	if p == nil || q == nil {
		return p == nil && q == nil
	}
	if p.Val != q.Val {
		return false
	}
	return dfs(p.Left, q.Right) && dfs(p.Right, q.Left)
}
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return dfs(root.Left, root.Right)
}

// iteration
func isSymmetric(root *TreeNode) bool {
	if root == nil {
		return true
	}
	st := []*TreeNode{}
	st = append(st, root.Left, root.Right)
	for len(st) != 0 {
		p := st[len(st)-1]
		st = st[:len(st)-1]
		q := st[len(st)-1]
		st = st[:len(st)-1]
		if p == nil && q == nil {
			continue
		}
		if p == nil || q == nil || p.Val != q.Val {
			return false
		}
		st = append(st, p.Left, q.Right, p.Right, q.Left)
	}
	return true
}