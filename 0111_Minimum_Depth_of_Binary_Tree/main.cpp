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
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        if (root->left == nullptr) {
            return minDepth(root->right) + 1;
        }
        if (root->right == nullptr) {
            return minDepth(root->left) + 1;
        }
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};

// T = O(n), S = O(n)
class Solution {
  public:
    int minDepth(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        queue<TreeNode *> q;
        int res = 1;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode *p = q.front();
                q.pop();
                if (p->left == nullptr && p->right == nullptr) {
                    return res;
                }
                if (p->left != nullptr) {
                    q.push(p->left);
                }
                if (p->right != nullptr) {
                    q.push(p->right);
                }
            }
            res++;
        }
        return -1;
    }
};
