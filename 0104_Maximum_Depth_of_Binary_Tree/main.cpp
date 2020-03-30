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
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

// T = O(n), S = O(n)
class Solution {
  public:
    int maxDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int res = 0;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *p = q.front();
                q.pop();
                if (p->left != nullptr) {
                    q.push(p->left);
                }
                if (p->right != nullptr) {
                    q.push(p->right);
                }
            }
            res++;
        }
        return res;
    }
};
