/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursive T = O(n), S = O(n)
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> left = inorderTraversal(root->left);
        vector<int> right = inorderTraversal(root->right);
        left.push_back(root->val);
        left.insert(left.end(), right.begin(), right.end());
        return left;
    }
};

// Iteration T = O(n), S = O(n)
class Solution {
  public:
    vector<int> inorderTraversal(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<int> res;
        stack<TreeNode *> q;
        while (root != nullptr || !q.empty()) {
            while (root != nullptr) {
                q.push(root);
                root = root->left;
            }
            TreeNode *p = q.top();
            q.pop();
            res.push_back(p->val);
            root = p->right;
        }
        return res;
    }
};
