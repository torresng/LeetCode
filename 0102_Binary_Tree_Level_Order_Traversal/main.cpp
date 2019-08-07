#include <iostream>
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode *root) {
        vector<vector<int>> res;
        if (!root) {
            return res;
        }

        TreeNode *p = root;
        queue<TreeNode *> q;
        q.push(p);
        while (!q.empty()) {
            vector<int> level;
            int n = q.size();
            for (int i = 0; i < n; i++) {
                p = q.front();
                q.pop();
                level.push_back(p->val);
                if (p->left) {
                    q.push(p->left);
                }
                if (p->right) {
                    q.push(p->right);
                }
            }
            res.push_back(level);
        }

        return res;
    }
};

bool compare(vector<vector<int>> v1, vector<vector<int>> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    int n = v1.size();
    for (unsigned i = 0; i < v1.size(); i++) {
        for (unsigned j = 0; j < v1[i].size(); j++) {
            if (v1[i][j] != v2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void test_case_1() {
    TreeNode *root = new TreeNode(3);
    TreeNode *p1 = new TreeNode(9);
    TreeNode *p2 = new TreeNode(20);
    TreeNode *p3 = new TreeNode(15);
    TreeNode *p4 = new TreeNode(7);
    root->left = p1;
    root->right = p2;
    p2->left = p3;
    p2->right = p4;
    vector<vector<int>> ans{{3}, {9, 20}, {15, 7}};

    vector<vector<int>> res = Solution().levelOrder(root);

    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
