/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// T = O(n*m), S = O(h)
class Solution {
    bool dfs(TreeNode *p, TreeNode *q) {
        if (!p || !q) {
            return !p && !q;
        }
        if (p == nullptr || p->val != q->val) {
            return false;
        }
        return dfs(p->left, q->left) && dfs(p->right, q->right);
    }

  public:
    bool isSubtree(TreeNode *s, TreeNode *t) {
        if (!s || !t) {
            return false;
        }
        if (dfs(s, t)) {
            return true;
        }
        return isSubtree(s->left, t) || isSubtree(s->right, t);
    }
};
