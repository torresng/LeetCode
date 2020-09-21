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
  public:
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (root == nullptr) {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            vector<int> v;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *p = q.front();
                q.pop();
                v.push_back(p->val);
                if (p->left) {
                    q.push(p->left);
                }
                if (p->right) {
                    q.push(p->right);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};
