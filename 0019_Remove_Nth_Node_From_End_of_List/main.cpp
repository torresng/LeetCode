#include <iostream>

using namespace std;

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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *slow = dummy, *fast = dummy;
        while (n) {
            fast = fast->next;
            --n;
        }
        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return dummy->next;
    }
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
    ListNode *head = new ListNode(1);
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(3);
    ListNode *p3 = new ListNode(4);
    ListNode *p4 = new ListNode(5);
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;
    int n = 2;

    ListNode *ansHead = new ListNode(1);
    ListNode *ansP1 = new ListNode(2);
    ListNode *ansP2 = new ListNode(3);
    ListNode *ansP3 = new ListNode(5);
    ansHead->next = ansP1;
    ansP1->next = ansP2;
    ansP2->next = ansP3;

    ListNode *res = Solution().removeNthFromEnd(head, n);
    assert(compare(res, ansHead) == true);
}

int main(void) {
    test_case_1();

    return 0;
}
