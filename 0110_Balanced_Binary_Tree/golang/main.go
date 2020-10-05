/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func abs(a int) int {
	if a < 0 {
		return -a
	}
	return a
}

func dfs(root *TreeNode, ans *bool) int {
	if root == nil {
		return 0
	}
	left, right := dfs(root.Left, ans), dfs(root.Right, ans)
	if abs(left-right) > 1 {
		*ans = false
	}
	return max(left, right) + 1
}

func isBalanced(root *TreeNode) bool {
	if root == nil {
		return true
	}
	ans := true
	dfs(root, &ans)
	return ans
}