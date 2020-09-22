/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

// recursion
func isSameTree(p *TreeNode, q *TreeNode) bool {
	if p == nil || q == nil {
		return p == nil && q == nil
	}
	if p.Val != q.Val {
		return false
	}
	return isSameTree(p.Left, q.Left) && isSameTree(p.Right, q.Right)
}

// iteration
func isSameTree(p *TreeNode, q *TreeNode) bool {
	st := []*TreeNode{}
	st = append(st, p, q)
	for len(st) != 0 {
		p = st[len(st)-1]
		st = st[:len(st)-1]
		q = st[len(st)-1]
		st = st[:len(st)-1]
		if p == nil && q == nil {
			continue
		}
		if p == nil || q == nil || p.Val != q.Val {
			return false
		}
		st = append(st, p.Left, q.Left, p.Right, q.Right)
	}
	return true
}