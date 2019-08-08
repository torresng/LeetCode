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
    int diameterOfBinaryTree(TreeNode *root) {
        dfs(root);
        return res;
    }

  private:
    int res = 0;

    int dfs(TreeNode *p) {
        if (!p) {
            return 0;
        }

        int left = dfs(p->left);
        int right = dfs(p->right);

        res = max(res, left + right);
        return max(left + 1, right + 1);
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
