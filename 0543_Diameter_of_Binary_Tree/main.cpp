#include <iostream>

using namespace std;

/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
  public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode *root) {
        dfs(root);
        return ans;
    }

    int dfs(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int l = dfs(root->left);
        int r = dfs(root->right);
        ans = max(ans, l + r);
        return max(l, r) + 1;
    }
};

void test_case_1() {
    TreeNode *root = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(3);
    TreeNode *p3 = new TreeNode(4);
    TreeNode *p4 = new TreeNode(5);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    int ans = 3;

    int res = Solution().diameterOfBinaryTree(root);

    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
