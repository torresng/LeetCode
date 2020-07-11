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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        vector<vector<int>> res;
        queue<TreeNode *> q;
        q.push(root);
        bool r = false;
        while (!q.empty())
        {
            int n = q.size();
            vector<int> v;
            for (int i = 0; i < n; i++)
            {
                TreeNode *p = q.front();
                q.pop();
                v.push_back(p->val);
                if (p->left)
                {
                    q.push(p->left);
                }
                if (p->right)
                {
                    q.push(p->right);
                }
            }
            if (r)
            {
                reverse(v.begin(), v.end());
            }
            r = !r;
            res.push_back(v);
        }
        return res;
    }
};