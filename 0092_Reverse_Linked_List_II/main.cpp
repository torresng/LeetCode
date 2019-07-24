#include <iostream>
#include <vector>

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        auto a = dummy, d = dummy;
        for (int i = 0; i < m - 1; ++i) {
            a = a->next;
        }
        for (int i = 0; i < n; ++i) {
            d = d->next;
        }

        auto b = a->next, c = d->next;
        auto p = b, q = b->next;
        while (q != c) {
            auto o = q->next;
            q->next = p;
            p = q, q = o;
        }

        a->next = d;
        b->next = c;

        return dummy->next;
    }
};

bool compare(ListNode *head, vector<int> &ans) {
    int n = ans.size();

    int i = 0;
    while (head && i < n) {
        if (head->val != ans[i]) {
            break;
        }
        head = head->next;
        ++i;
    }
    if (head || i < n) {
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
    int m = 2, n = 4;
    vector<int> ans{1, 4, 3, 2, 5};

    ListNode *res = Solution().reverseBetween(head, m, n);
    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
