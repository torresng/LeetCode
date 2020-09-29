/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrder(root *TreeNode) [][]int {
	if root == nil {
		return nil
	}
	q := []*TreeNode{root}
	res := [][]int{}
	for len(q) != 0 {
		tmp := []*TreeNode{}
		v := []int{}
		for _, p := range q {
			v = append(v, p.Val)
			if p.Left != nil {
				tmp = append(tmp, p.Left)
			}
			if p.Right != nil {
				tmp = append(tmp, p.Right)
			}
		}
		res = append(res, v)
		q = tmp
	}
	return res
}