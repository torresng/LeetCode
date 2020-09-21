/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

// T = O(n*e), S = O(n)
class Solution {
    unordered_map<Node *, Node *> map;

  public:
    Node *cloneGraph(Node *node) {
        if (node == nullptr) {
            return nullptr;
        }
        Node *copy = new Node(node->val);
        map[node] = copy;
        for (Node *p : node->neighbors) {
            unordered_map<Node *, Node *>::const_iterator it = map.find(p);
            if (it != map.end()) {
                copy->neighbors.push_back(it->second);
            } else {
                copy->neighbors.push_back(cloneGraph(p));
            }
        }
        return copy;
    }
};
