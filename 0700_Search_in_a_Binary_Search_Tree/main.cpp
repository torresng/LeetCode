/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// T = O(n), S = O(1)
class Solution {
  public:
    TreeNode *searchBST(TreeNode *root, int val) {
        while (root != nullptr && root->val != val) {
            if (root->val > val) {
                root = root->left;
            } else if (root->val < val) {
                root = root->right;
            }
        }
        return root;
    }
};
