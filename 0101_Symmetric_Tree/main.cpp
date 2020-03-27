/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursive  T = O(n), S = O(n)
class Solution {
    bool isSymmetric(TreeNode *a, TreeNode *b) {
        if (a != nullptr && b != nullptr) {
            return a->val == b->val && isSymmetric(a->left, b->right) &&
                   isSymmetric(a->right, b->left);
        } else {
            return a == nullptr && b == nullptr;
        }
    }

  public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        return isSymmetric(root->left, root->right);
    }
};

// Iteration  T = O(n), S = O(n)
class Solution {
  public:
    bool isSymmetric(TreeNode *root) {
        if (root == nullptr) {
            return true;
        }
        stack<TreeNode *> st;
        st.push(root->left);
        st.push(root->right);
        while (!st.empty()) {
            TreeNode *a = st.top();
            st.pop();
            TreeNode *b = st.top();
            st.pop();
            if (a == nullptr && b == nullptr) {
                continue;
            }
            if (a == nullptr || b == nullptr) {
                return false;
            }
            if (a->val != b->val) {
                return false;
            }
            st.push(a->left);
            st.push(b->right);
            st.push(a->right);
            st.push(b->left);
        }
        return true;
    }
};
