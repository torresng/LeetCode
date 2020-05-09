/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// T = O(n), S = O(1)
class Solution {
  public:
    Node *copyRandomList(Node *head) {
        if (head == nullptr) {
            return nullptr;
        }
        Node *p = head;
        while (p != nullptr) {
            Node *next = p->next;
            Node *node = new Node(p->val);
            node->next = next;
            p->next = node;
            p = next;
        }

        p = head;
        while (p != nullptr) {
            if (p->random != nullptr) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }

        Node *dummy = new Node(-1), *q = dummy;
        p = head;
        while (p != nullptr) {
            q->next = p->next;
            q = q->next;
            p->next = p->next->next;
            p = p->next;
        }
        return dummy->next;
    }
};
