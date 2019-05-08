/**************************************************************

Given a binary tree, return the zigzag level order traversal of its nodes'
values. (ie, from left to right, then right to left for the next level and
alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],

    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:

[
  [3],
  [20,9],
  [15,7]
]

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (root == nullptr)
            return res;
        vector<TreeNode *> curr, temp;
        curr.push_back(root);
        bool z = false;
        while (!curr.empty()) {
            vector<int> vec;
            for (auto t : curr) {
                vec.push_back(t->val);
                if (t->left) {
                    temp.push_back(t->left);
                }
                if (t->right) {
                    temp.push_back(t->right);
                }
            }
            if(z) {
                reverse(vec.begin(), vec.end());
                z = false;
            } else {
                z = true;
            }
            res.push_back(vec);
            curr.clear();
            swap(curr, temp);
        }

        return res;
    }
};

void test_case_1() {
    TreeNode *root = new TreeNode(3);
    TreeNode *node1 = new TreeNode(9);
    TreeNode *node2 = new TreeNode(20);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(7);
    root->left = node1;
    root->right = node2;
    node2->left = node3;
    node2->right = node4;

    vector<vector<int>> ans = {{3}, {20, 9}, {15, 7}};

    vector<vector<int>> res = Solution().zigzagLevelOrder(root);
    for (auto v : res) {
        for (auto val : v) {
            cout << val << ",";
        }
        cout << endl;
    }
}

int main(void) {
    test_case_1();
    return 0;
}
