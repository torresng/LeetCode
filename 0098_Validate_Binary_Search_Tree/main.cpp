#include <iostream>
#include <vector>

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
    bool isValidBST(TreeNode *root) { return dfs(root, INT_MIN, INT_MAX); }

  private:
    bool dfs(TreeNode *root, long long minv, long long maxv) {
        if (root == NULL) {
            return true;
        }
        if (root->val < minv || root->val > maxv) {
            return false;
        }

        return dfs(root->left, minv, root->val - 1ll) &&
               dfs(root->right, root->val + 1ll, maxv);
    }
};

void test_case_1() {
    TreeNode *root = new TreeNode(2);
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(3);
    root->left = p1;
    root->right = p2;
    bool ans = true;

    auto res = Solution().isValidBST(root);

    assert(res == ans);
}

void test_case_2() {
    TreeNode *root = new TreeNode(5);
    TreeNode *p1 = new TreeNode(1);
    TreeNode *p2 = new TreeNode(4);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(6);
    root->left = p1;
    root->right = p2;
    p2->left = p3;
    p2->right = p4;
    bool ans = false;

    auto res = Solution().isValidBST(root);

    assert(res == ans);
}

void test_case_3() {
    TreeNode *root = new TreeNode(1);
    TreeNode *p1 = new TreeNode(1);
    root->left = p1;
    bool ans = false;

    auto res = Solution().isValidBST(root);

    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
