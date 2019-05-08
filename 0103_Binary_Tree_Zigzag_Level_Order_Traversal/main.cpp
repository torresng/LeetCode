#include <stack>
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
        stack<TreeNode *> s1, s2;
        s1.push(root);
        while (!s1.empty() || !s2.empty()) {
            vector<int> temp;
            while (!s1.empty()) {
                TreeNode *p = s1.top();
                s1.pop();
                temp.push_back(p->val);
                if (p->left)
                    s2.push(p->left);
                if (p->right)
                    s2.push(p->right);
            }
            if (!temp.empty())
                res.push_back(temp);
            temp.clear();
            while (!s2.empty()) {
                TreeNode *p = s2.top();
                s2.pop();
                temp.push_back(p->val);
                if (p->right)
                    s1.push(p->right);
                if (p->left)
                    s1.push(p->left);
            }
            if (!temp.empty())
                res.push_back(temp);
            temp.clear();
        }
        return res;
    }
};

bool compare(vector<vector<int>> &a, vector<vector<int>> &b) {
    if (a.size() != b.size())
        return false;
    for (unsigned long i = 0; i < a.size(); ++i) {
        vector<int> &v1 = a[i];
        vector<int> &v2 = b[i];
        if (v1.size() != v2.size())
            return false;
        for (unsigned long j = 0; j < v1.size(); ++j) {
            if (v1[j] != v2[j])
                return false;
        }
    }
    return true;
}

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

    assert(compare(ans, res));
}

int main(void) {
    test_case_1();
    return 0;
}
