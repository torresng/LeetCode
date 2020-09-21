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

class BSTIterator {
  public:
    BSTIterator(TreeNode *root) {
        TreeNode *p = root;
        while (p) {
            stk.push(p);
            p = p->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        TreeNode *p = stk.top();
        stk.pop();
        int res = p->val;

        p = p->right;
        while (p) {
            stk.push(p);
            p = p->left;
        }

        return res;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !stk.empty(); }

  private:
    stack<TreeNode *> stk;
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */

void test_case_1() {
    TreeNode *root = new TreeNode(7);
    TreeNode *p1 = new TreeNode(3);
    TreeNode *p2 = new TreeNode(15);
    TreeNode *p3 = new TreeNode(9);
    TreeNode *p4 = new TreeNode(20);
    root->left = p1;
    root->right = p2;
    p2->left = p3;
    p2->right = p4;

    BSTIterator iterator = BSTIterator(root);
    assert(iterator.next() == 3);
    assert(iterator.next() == 7);
    assert(iterator.hasNext() == true);
    assert(iterator.next() == 9);
    assert(iterator.hasNext() == true);
    assert(iterator.next() == 15);
    assert(iterator.hasNext() == true);
    assert(iterator.next() == 20);
    assert(iterator.hasNext() == false);
}

int main() {
    test_case_1();

    return 0;
}
