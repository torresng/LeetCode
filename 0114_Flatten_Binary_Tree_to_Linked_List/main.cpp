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
// T = O(n), S = O(n)
class Solution {
    vector<TreeNode *> v;
    void dfs(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        v.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }

  public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        dfs(root);
        TreeNode *p = root;
        for (int i = 1; i < v.size(); i++) {
            p->left = nullptr;
            p->right = v[i];
            p = p->right;
        }
    }
};

// T = O(n), S = O(n)
class Solution {
    TreeNode *p = nullptr;

  public:
    void flatten(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        flatten(root->right);
        flatten(root->left);
        root->left = nullptr;
        root->right = p;
        p = root;
    }
};
