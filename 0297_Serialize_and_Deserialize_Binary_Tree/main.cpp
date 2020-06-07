/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec
{
    void dfs_s(TreeNode *root, string &s)
    {
        if (root == nullptr)
        {
            s += "null ";
            return;
        }
        s += to_string(root->val) + ' ';
        dfs_s(root->left, s);
        dfs_s(root->right, s);
    }

    TreeNode *dfs_d(string s, int &i)
    {
        if (s.size() == i)
        {
            return nullptr;
        }
        while (i < s.size() && s[i] == ' ')
        {
            i++;
        }
        if (s[i] == 'n')
        {
            i += 4;
            return nullptr;
        }
        int t = 1;
        if (s[i] == '-')
        {
            t = -1;
            i++;
        }
        int val = 0;
        while (s[i] != ' ')
        {
            val = val * 10 + s[i] - '0';
            i++;
        }
        TreeNode *root = new TreeNode(val * t);
        root->left = dfs_d(s, i);
        root->right = dfs_d(s, i);
        return root;
    }

public:
    // T = O(n), S = O(n)
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string s;
        dfs_s(root, s);
        return s;
    }

    // T = O(n), S = O(n)
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        int i = 0;
        return dfs_d(data, i);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));