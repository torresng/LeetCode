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
    int dfs(TreeNode *root, int sum) {
        if (root == nullptr) {
            return sum;
        }
        int cur = dfs(root->right, sum);
        root->val += cur;
        return dfs(root->left, root->val);
    }

  public:
    TreeNode *convertBST(TreeNode *root) {
        dfs(root, 0);
        return root;
    }
};

// T = O(n), S = O(n)
class Solution {
  public:
    TreeNode *convertBST(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        int sum = 0;
        stack<TreeNode *> q;
        TreeNode *p = root;
        while (p || !q.empty()) {
            while (p) {
                q.push(p);
                p = p->right;
            }
            p = q.top();
            q.pop();
            p->val += sum;
            sum = p->val;
            p = p->left;
        }
        return root;
    }
};
