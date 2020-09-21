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
    int res = 0;
    void dfs(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return;
        }
        if (root->val == sum)
        {
            res++;
        }
        dfs(root->left, sum - root->val);
        dfs(root->right, sum - root->val);
    }

public:
    int pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return 0;
        }
        dfs(root, sum);
        pathSum(root->left, sum);
        pathSum(root->right, sum);
        return res;
    }
};

// T = O(n), S = O(n)
class Solution
{
    unordered_map<int, int> map;
    int dfs(TreeNode *root, int cur, int sum)
    {
        if (root == nullptr)
        {
            return 0;
        }
        cur += root->val;
        int cnt = map[cur - sum];
        map[cur]++;
        cnt += dfs(root->left, cur, sum);
        cnt += dfs(root->right, cur, sum);
        map[cur]--;
        return cnt;
    }

public:
    int pathSum(TreeNode *root, int sum)
    {
        if (root == nullptr)
        {
            return 0;
        }
        map[0] = 1;
        return dfs(root, 0, sum);
    }
};