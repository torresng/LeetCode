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
    vector<vector<int>> res;
    vector<int> path;
    void dfs(TreeNode *root, int sum) {
        if (root == nullptr) {
            return;
        }
        path.push_back(root->val);
        sum -= root->val;
        if (root->left == nullptr && root->right == nullptr && sum == 0) {
            res.push_back(path);
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back();
    }

  public:
    vector<vector<int>> pathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return {};
        }
        dfs(root, sum);
        return res;
    }
};
