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
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (!root || root == p || root == q) {
            return root;
        }
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        if (!left) {
            return right;
        }
        if (!right) {
            return left;
        }
        return root;
    }
};

void test_case_1() {
    TreeNode *root = new TreeNode(3);
    TreeNode *p1 = new TreeNode(5);
    TreeNode *p2 = new TreeNode(1);
    TreeNode *p3 = new TreeNode(6);
    TreeNode *p4 = new TreeNode(2);
    TreeNode *p5 = new TreeNode(0);
    TreeNode *p6 = new TreeNode(8);
    TreeNode *p7 = new TreeNode(7);
    TreeNode *p8 = new TreeNode(4);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    p4->left = p7;
    p4->right = p8;
    TreeNode *p = p1;
    TreeNode *q = p2;
    TreeNode *ans = root;

    TreeNode *res = Solution().lowestCommonAncestor(root, p, q);
    assert(res == ans);
}

void test_case_2() {
    TreeNode *root = new TreeNode(3);
    TreeNode *p1 = new TreeNode(5);
    TreeNode *p2 = new TreeNode(1);
    TreeNode *p3 = new TreeNode(6);
    TreeNode *p4 = new TreeNode(2);
    TreeNode *p5 = new TreeNode(0);
    TreeNode *p6 = new TreeNode(8);
    TreeNode *p7 = new TreeNode(7);
    TreeNode *p8 = new TreeNode(4);
    root->left = p1;
    root->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    p4->left = p7;
    p4->right = p8;
    TreeNode *p = p1;
    TreeNode *q = p8;
    TreeNode *ans = p1;

    TreeNode *res = Solution().lowestCommonAncestor(root, p, q);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
