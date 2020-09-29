/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func levelOrderBottom(root *TreeNode) [][]int {
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
	n := len(res)
	for i := 0; i < n/2; i++ {
		j := n - i - 1
		res[i], res[j] = res[j], res[i]
	}
	return res
}