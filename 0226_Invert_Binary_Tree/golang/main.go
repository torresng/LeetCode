/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
// Recursive T = O(n), S = O(n)
func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	dfs(root)
	return root
}

func dfs(root *TreeNode) {
	if root == nil {
		return
	}
	root.Left, root.Right = root.Right, root.Left
	dfs(root.Left)
	dfs(root.Right)
}

// Iteration T = O(n), S = O(n)
func invertTree(root *TreeNode) *TreeNode {
	if root == nil {
		return nil
	}
	st := []*TreeNode{root}
	for len(st) != 0 {
		p := st[len(st)-1]
		st = st[0 : len(st)-1]
		p.Left, p.Right = p.Right, p.Left
		if p.Left != nil {
			st = append(st, p.Left)
		}
		if p.Right != nil {
			st = append(st, p.Right)
		}
	}
	return root
}