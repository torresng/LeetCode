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
// T = O(n), S = O(logn)
class Solution {
  public:
    TreeNode *dfs(vector<int> &nums, int l, int r) {
        if (l > r) {
            return nullptr;
        }
        int mid = (l + r) >> 1;
        TreeNode *root = new TreeNode(nums[mid]);
        root->left = dfs(nums, l, mid - 1);
        root->right = dfs(nums, mid + 1, r);
        return root;
    }
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty()) {
            return nullptr;
        }
        return dfs(nums, 0, nums.size() - 1);
    }
};

// Iterate
// T = O(n), S = O(n)
class Solution {
    struct Item {
        TreeNode *parent;
        int l, r;
        bool isLeft;
        Item(TreeNode *parent, int l, int r, bool isLeft) {
            this->parent = parent;
            this->l = l;
            this->r = r;
            this->isLeft = isLeft;
        }
    };

  public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        if (nums.empty()) {
            return nullptr;
        }
        stack<Item *> st;
        TreeNode *dummy = new TreeNode(-1);
        st.push(new Item(dummy, 0, nums.size() - 1, true));
        while (!st.empty()) {
            Item *p = st.top();
            st.pop();
            if (p->l <= p->r) {
                int mid = (p->l + p->r) >> 1;
                TreeNode *root = new TreeNode(nums[mid]);
                if (p->isLeft == true) {
                    p->parent->left = root;
                } else {
                    p->parent->right = root;
                }
                st.push(new Item(root, p->l, mid - 1, true));
                st.push(new Item(root, mid + 1, p->r, false));
            }
        }
        return dummy->left;
    }
};
