/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

// T = O(n), S = O(log(n))
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr || root->left == nullptr)
        {
            return root;
        }
        root->left->next = root->right;
        if (root->next)
        {
            root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

// T = O(n), S = O(1)
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        Node *leftmost = root, *p;
        while (leftmost->left)
        {
            p = leftmost;
            while (p)
            {
                p->left->next = p->right;
                if (p->next)
                {
                    p->right->next = p->next->left;
                }
                p = p->next;
            }
            leftmost = leftmost->left;
        }
        return root;
    }
};