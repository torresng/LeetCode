/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
// T = O(n), S = O(n)
func isValidBST(root *TreeNode) bool {
	if root == nil {
		return true
	}
	return dfs(root, nil, nil)
}

func dfs(root *TreeNode, minNode *TreeNode, maxNode *TreeNode) bool {
	if root == nil {
		return true
	}
	if minNode != nil && root.Val <= minNode.Val {
		return false
	}
	if maxNode != nil && root.Val >= maxNode.Val {
		return false
	}
	return dfs(root.Left, minNode, root) && dfs(root.Right, root, maxNode)
}