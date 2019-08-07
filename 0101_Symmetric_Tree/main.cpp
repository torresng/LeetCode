#include <iostream>
#include <stack>

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
    // Iteration
    bool isSymmetric(TreeNode *root) {
        if (!root) {
            return true;
        }
        stack<TreeNode *> left, right;
        TreeNode *l = root->left, *r = root->right;
        while (l || r || !left.empty() || !right.empty()) {
            while (l && r) {
                left.push(l);
                right.push(r);
                l = l->left;
                r = r->right;
            }
            if (l || r) {
                return false;
            }

            l = left.top();
            left.pop();
            r = right.top();
            right.pop();
            if (l->val != r->val) {
                return false;
            }
            l = l->right, r = r->left;
        }

        return true;
    }
    /*
     * // Recursive
     *  public:
     *    bool isSymmetric(TreeNode *root) {
     *        if (!root) {
     *            return true;
     *        }
     *        return dfs(root->left, root->right);
     *    }
     *
     *  private:
     *    bool dfs(TreeNode *p, TreeNode *q) {
     *        if (!p || !q) {
     *            return !p && !q;
     *        }
     *        return p->val == q->val && dfs(p->left, q->right) &&
     *               dfs(p->right, q->left);
     *    }
     */
};

void test_case_1() {
    TreeNode *head = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(4);
    TreeNode *p5 = new TreeNode(4);
    TreeNode *p6 = new TreeNode(3);
    head->left = p1;
    head->right = p2;
    p1->left = p3;
    p1->right = p4;
    p2->left = p5;
    p2->right = p6;
    bool ans = true;

    bool res = Solution().isSymmetric(head);

    assert(res == ans);
}

void test_case_2() {
    TreeNode *head = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(2);
    TreeNode *p3 = new TreeNode(3);
    TreeNode *p4 = new TreeNode(3);
    head->left = p1;
    head->right = p2;
    p1->right = p3;
    p2->right = p4;
    bool ans = false;

    bool res = Solution().isSymmetric(head);

    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
