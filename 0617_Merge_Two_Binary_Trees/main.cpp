/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// T = O(n), S = O(n)
class Solution {
    TreeNode *dfs(TreeNode *t1, TreeNode *t2) {
        if (t1 == nullptr && t2 == nullptr) {
            return nullptr;
        }
        if (t1 == nullptr) {
            return t2;
        }
        if (t2 == nullptr) {
            return t1;
        }
        t1->val += t2->val;
        t1->left = dfs(t1->left, t2->left);
        t1->right = dfs(t1->right, t2->right);
        return t1;
    }

  public:
    TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2) { return dfs(t1, t2); }
};
