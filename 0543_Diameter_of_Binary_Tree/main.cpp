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
// T = O(n), S = O(n)
class Solution
{
    int res = 0;
    int dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int left = dfs(root->left);
        int right = dfs(root->right);
        res = max(res, left + right);
        return max(left, right) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        dfs(root);
        return res;
    }
};

// T = O(n), S = O(n)
class Solution
{
public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        unordered_map<TreeNode *, int> map;
        stack<TreeNode *> st;
        st.push(root);
        int res = 0;
        while (!st.empty())
        {
            TreeNode *p = st.top();
            if (p->left && map.find(p->left) == map.end())
            {
                st.push(p->left);
            }
            else if (p->right && map.find(p->right) == map.end())
            {
                st.push(p->right);
            }
            else
            {
                st.pop();
                int left = map[p->left], right = map[p->right];
                res = max(res, left + right);
                map[p] = max(left, right) + 1;
            }
        }
        return res;
    }
};