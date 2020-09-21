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
    vector<int> _preorder;
    vector<int> _inorder;
    unordered_map<int, int> hash;
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        _preorder = preorder;
        _inorder = inorder;
        int pn = preorder.size();
        int in = inorder.size();
        for (int i = 0; i < pn; i++) {
            hash[inorder[i]] = i;
        }
        return build(0, pn - 1, 0, in - 1);
    }

    TreeNode *build(int pl, int pr, int il, int ir) {
        if (pl > pr) {
            return nullptr;
        }
        int x = _preorder[pl];
        TreeNode *root = new TreeNode(x);
        int k = hash[x];
        TreeNode *left = build(pl + 1, pl + k - il, il, k - 1);
        TreeNode *right = build(pl + k - il + 1, pr, k + 1, ir);
        root->left = left;
        root->right = right;
        return root;
    }
};
