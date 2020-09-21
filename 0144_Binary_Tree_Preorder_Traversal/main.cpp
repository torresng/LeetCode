/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// Recursive
// T = O(n), S = O(n)
class Solution {
  public:
    vector<int> res;
    void preorder(TreeNode *root) {
        if (root == nullptr) {
            return;
        }
        res.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    vector<int> preorderTraversal(TreeNode *root) {
        preorder(root);
        return res;
    }
};

// Iterate
// T = O(n), S = O(n)
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        stack<TreeNode *> st;
        while (root != nullptr || !st.empty()) {
            while (root != nullptr) {
                res.push_back(root->val);
                st.push(root);
                root = root->left;
            }
            root = st.top()->right;
            st.pop();
        }
        return res;
    }
};

// Iterate
// T = O(n), S = O(n)
class Solution {
  public:
    vector<int> preorderTraversal(TreeNode *root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        stack<TreeNode *> st;
        st.push(root);
        while (!st.empty()) {
            TreeNode *p = st.top();
            st.pop();
            res.push_back(p->val);
            if (p->right != nullptr) {
                st.push(p->right);
            }
            if (p->left != nullptr) {
                st.push(p->left);
            }
        }
        return res;
    }
};
