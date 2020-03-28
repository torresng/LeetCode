/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursion T = O(n), S = O(n)
class Solution {
  public:
    bool dfs(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) {
            return true;
        }
        if (p == nullptr || q == nullptr) {
            return false;
        }
        return p->val == q->val && dfs(p->left, q->left) &&
               dfs(p->right, q->right);
    }
    bool isSameTree(TreeNode *p, TreeNode *q) { return dfs(p, q); }
};

// Iteration T = O(n), S = O(n)
class Solution {
  public:
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode *> st;
        st.push(p);
        st.push(q);
        while (!st.empty()) {
            TreeNode *s = st.top();
            st.pop();
            TreeNode *t = st.top();
            st.pop();
            if (s == nullptr && t == nullptr) {
                continue;
            }
            if (s == nullptr || t == nullptr) {
                return false;
            }
            if (s->val != t->val) {
                return false;
            }
            st.push(s->left);
            st.push(t->left);
            st.push(s->right);
            st.push(t->right);
        }
        return true;
    }
};
