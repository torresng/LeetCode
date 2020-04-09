/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursive
// T = O(n), S = O(n)
class Solution {
  public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return false;
        }
        if (root->left == nullptr && root->right == nullptr &&
            root->val == sum) {
            return true;
        }
        return hasPathSum(root->left, sum - root->val) ||
               hasPathSum(root->right, sum - root->val);
    }
};

// Iterate
// T = O(n), S = O(n)
class Solution {
  public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return false;
        }
        stack<TreeNode *> st;
        stack<int> sumSt;
        st.push(root);
        sumSt.push(sum);

        while (!st.empty()) {
            TreeNode *p = st.top();
            st.pop();
            int s = sumSt.top();
            sumSt.pop();
            if (p->left == nullptr && p->right == nullptr && p->val == s) {
                return true;
            }
            if (p->left != nullptr) {
                st.push(p->left);
                sumSt.push(s - p->val);
            }
            if (p->right != nullptr) {
                st.push(p->right);
                sumSt.push(s - p->val);
            }
        }
        return false;
    }
};
