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
    vector<int> _inorder;
    vector<int> _postorder;
    unordered_map<int, int> hash;

    TreeNode *build(int il, int ir, int pl, int pr) {
        if (pl > pr) {
            return nullptr;
        }
        int x = _postorder[pr];
        TreeNode *root = new TreeNode(x);
        int k = hash[x];
        TreeNode *left = build(il, k - 1, pl, pl + k - il - 1);
        TreeNode *right = build(k + 1, ir, pl + k - il, pr - 1);
        root->left = left;
        root->right = right;
        return root;
    }
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        _inorder = inorder;
        _postorder = postorder;
        int in = inorder.size();
        int pr = postorder.size();
        for (int i = 0; i < in; i++) {
            hash[inorder[i]] = i;
        }
        return build(0, in - 1, 0, pr - 1);
    }
};
