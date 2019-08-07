#include <iostream>
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
    vector<int> inorderTraversal(TreeNode *root) {
        vector<int> res;

        stack<TreeNode *> stk;

        TreeNode *p = root;
        while (p || !stk.empty()) {
            while (p) {
                stk.push(p);
                p = p->left;
            }
            p = stk.top();
            stk.pop();
            res.push_back(p->val);
            p = p->right;
        }

        return res;
    }
};

bool compare(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() != nums2.size()) {
        return false;
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    for (unsigned i = 0; i < nums1.size(); ++i) {
        if (nums1[i] != nums2[i]) {
            return false;
        }
    }

    return true;
}

void test_case_1() {
    TreeNode *head = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(3);
    head->right = p1;
    p1->left = p2;
    vector<int> ans{1, 3, 2};

    vector<int> res = Solution().inorderTraversal(head);

    assert(compare(ans, res) == true);
}

int main() {
    test_case_1();

    return 0;
}
