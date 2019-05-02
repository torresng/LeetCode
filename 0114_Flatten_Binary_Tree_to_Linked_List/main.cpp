/**************************************************************
Given a binary tree, flatten it to a linked list in-place.

For example, given the following tree:

    1
   / \
  2   5
 / \   \
3   4   6

The flattened tree should look like:

1
 \
  2
   \
    3
     \
      4
       \
        5
         \
          6

***************************************************************/

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
    void flatten(TreeNode *root) {
        if (root == nullptr)
            return;
        if (root->left)
            flatten(root->left);
        if (root->right)
            flatten(root->right);
        TreeNode *p = root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right)
            root = root->right;
        root->right = p;
    }
};

bool compare(TreeNode *root, vector<int> &ans) {
    for (int val : ans) {
        if (root == nullptr)
            return false;
        if (root->val != val)
            return false;
        if (root->left != nullptr)
            return false;
        root = root->right;
    }
    return true;
}

void test_case_1() {
    TreeNode *root = new TreeNode(1);
    TreeNode *node1 = new TreeNode(2);
    TreeNode *node2 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(6);
    root->left = node1;
    root->right = node2;
    node1->left = node3;
    node1->right = node4;
    node2->right = node5;
    vector<int> ans = {1, 2, 3, 4, 5, 6};

    Solution().flatten(root);
    assert(compare(root, ans));
}

int main(void) {
    test_case_1();
    return 0;
}
