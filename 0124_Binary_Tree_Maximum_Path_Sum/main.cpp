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
    int maxPathSum(TreeNode *root) {
        dfs(root);
        return res;
    }

  private:
    int res = INT_MIN;

    int dfs(TreeNode *p) {
        if (!p) {
            return 0;
        }
        int left = dfs(p->left);
        int right = dfs(p->right);
        res = max(res, p->val + left + right);
        return max(0, max(p->val + left, p->val + right));
    }
};

void test_case_1() {
    TreeNode *root = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(3);
    root->left = p1;
    root->right = p2;
    int ans = 6;

    int res = Solution().maxPathSum(root);
    assert(res == ans);
}

void test_case_2() {
    TreeNode *root = new TreeNode(-10);
    TreeNode *p1 = new TreeNode(9);
    TreeNode *p2 = new TreeNode(20);
    TreeNode *p3 = new TreeNode(15);
    TreeNode *p4 = new TreeNode(7);
    root->left = p1;
    root->right = p2;
    p2->left = p3;
    p2->right = p4;
    int ans = 42;

    int res = Solution().maxPathSum(root);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
