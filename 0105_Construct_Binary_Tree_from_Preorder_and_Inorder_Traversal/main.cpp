#include <iostream>
#include <unordered_map>
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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        int n = preorder.size();
        for (int i = 0; i < n; i++) {
            pos[inorder[i]] = i;
        }

        return dfs(preorder, inorder, 0, preorder.size() - 1, 0,
                   inorder.size() - 1);
    }

  private:
    unordered_map<int, int> pos;

    TreeNode *dfs(vector<int> &preorder, vector<int> &inorder, int pl, int pr,
                  int il, int ir) {
        if (pl > pr) {
            return NULL;
        }
        int val = preorder[pl];
        int k = pos[val];
        int len = k - il;
        TreeNode *p = new TreeNode(val);
        p->left = dfs(preorder, inorder, pl + 1, pl + len, il, k - 1);
        p->right = dfs(preorder, inorder, pl + len + 1, pr, k + 1, ir);

        return p;
    }
};

bool compare(TreeNode *p, TreeNode *q) {
    if (!p || !q) {
        return !p && !q;
    }
    if (p->val != q->val) {
        return false;
    }

    return compare(p->left, q->left) && compare(p->right, q->right);
}

void test_case_1() {
    vector<int> preorder{3, 9, 20, 15, 7}, inorder{9, 3, 15, 20, 7};
    TreeNode *ans = new TreeNode(3);
    TreeNode *p1 = new TreeNode(9);
    TreeNode *p2 = new TreeNode(20);
    TreeNode *p3 = new TreeNode(15);
    TreeNode *p4 = new TreeNode(7);
    ans->left = p1;
    ans->right = p2;
    p2->left = p3;
    p2->right = p4;

    TreeNode *res = Solution().buildTree(preorder, inorder);
    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
