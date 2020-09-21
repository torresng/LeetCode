/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// T = O(n^2), S = O(n)
class Solution
{
    int maxPathSumFrom(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = max(0, maxPathSumFrom(root->left));
        int right = max(0, maxPathSumFrom(root->right));
        return root->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode *root)
    {
        if (root == nullptr)
        {
            return INT_MIN;
        }
        int left = max(0, maxPathSumFrom(root->left));
        int right = max(0, maxPathSumFrom(root->right));
        return max(root->val + left + right,
                   max(maxPathSum(root->left), maxPathSum(root->right)));
    }
};

// T = O(n), S = O(n)
class Solution
{
    int res = INT_MIN;
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        res = max(res, root->val + left + right);
        return max(0, max(root->val + left, root->val + right));
    }

public:
    int maxPathSum(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        dfs(root);
        return res;
    }
};