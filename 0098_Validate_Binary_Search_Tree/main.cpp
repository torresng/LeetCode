/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
  public:
    bool isValidBST(TreeNode *root) { return dfs(root, nullptr, nullptr); }

    bool dfs(TreeNode *root, TreeNode *lower, TreeNode *upper) {
        if (root == nullptr) {
            return true;
        }
        if (lower != nullptr && lower->val >= root->val) {
            return false;
        }
        if (upper != nullptr && upper->val <= root->val) {
            return false;
        }
        return dfs(root->left, lower, root) && dfs(root->right, root, upper);
    }
};
