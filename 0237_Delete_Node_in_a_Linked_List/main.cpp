#include <iostream>

/**
 * Definition for singly-linked list.
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
    void deleteNode(ListNode *node) { *(node) = *(node->next); }
};

bool compare(ListNode *h1, ListNode *h2) {
    while (h1 && h2) {
        if (h1->val != h2->val) {
            break;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    if (h1 || h2) {
        return false;
    }
    return true;
}

void test_case_1() {
    ListNode *head = new ListNode(4);
    ListNode *p1 = new ListNode(5);
    ListNode *p2 = new ListNode(1);
    ListNode *p3 = new ListNode(9);
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    ListNode *node = p1;

    ListNode *ansHead = new ListNode(4);
    ListNode *ansP1 = new ListNode(1);
    ListNode *ansP2 = new ListNode(9);
    ansHead->next = ansP1;
    ansP1->next = ansP2;

    Solution().deleteNode(node);

    assert(compare(head, ansHead) == true);
}

int main() {
    test_case_1();

    return 0;
}
