#include <iostream>
#include <string>

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

class Codec {
  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        string res;
        dfs1(root, res);
        return res;
    }

  private:
    void dfs1(TreeNode *root, string &res) {
        if (!root) {
            res += "#,";
            return;
        }
        res += to_string(root->val) + ',';
        dfs1(root->left, res);
        dfs1(root->right, res);
    }

  public:
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        int i = 0;
        return dfs2(data, i);
    }

  private:
    TreeNode *dfs2(string &data, int &i) {
        if (data[i] == '#') {
            i += 2;
            return NULL;
        }

        int t = 0;
        bool is_minus = false;
        if (data[i] == '-') {
            is_minus = true;
            i++;
        }
        while (data[i] != ',') {
            t = t * 10 + data[i] - '0';
            i++;
        }
        i++;
        if (is_minus) {
            t = -t;
        }

        auto root = new TreeNode(t);
        root->left = dfs2(data, i);
        root->right = dfs2(data, i);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

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
    TreeNode *root = new TreeNode(1);
    TreeNode *p1 = new TreeNode(2);
    TreeNode *p2 = new TreeNode(3);
    TreeNode *p3 = new TreeNode(4);
    TreeNode *p4 = new TreeNode(5);
    root->left = p1;
    root->right = p2;
    p2->left = p3;
    p2->right = p4;
    string ans1 = "1,2,#,#,3,4,#,#,5,#,#,";

    string res1 = Codec().serialize(root);
    assert(res1 == ans1);

    TreeNode *ans2 = root;

    TreeNode *res2 = Codec().deserialize(ans1);
    assert(compare(res2, ans2) == true);
}

int main() { 
    test_case_1();
    
    return 0; }
