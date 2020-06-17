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
    vector<int> res;
    void dfs(TreeNode *root)
    {
        if (root == nullptr)
        {
            return;
        }
        dfs(root->left);
        dfs(root->right);
        res.push_back(root->val);
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        dfs(root);
        return res;
    }
};

// T = O(n), S = O(n)
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        vector<int> res;
        stack<TreeNode *> st;
        TreeNode *pre = nullptr;
        while (root || !st.empty())
        {
            if (root != nullptr)
            {
                st.push(root);
                root = root->left;
            }
            else
            {
                root = st.top()->right;
                if (root == nullptr || root == pre)
                {
                    root = st.top();
                    st.pop();
                    res.push_back(root->val);
                    pre = root;
                    root = nullptr;
                }
            }
        }
        return res;
    }
};

// T = O(n), S = O(n)
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (root == nullptr)
        {
            return {};
        }
        list<TreeNode *> l;
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty())
        {
            root = st.top();
            st.pop();
            l.push_front(root);
            if (root->left)
            {
                st.push(root->left);
            }
            if (root->right)
            {
                st.push(root->right);
            }
        }
        vector<int> res;
        for (auto x : l)
        {
            res.push_back(x->val);
        }
        return res;
    }
};