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
    ListNode *swapPairs(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        for(auto p = dummy; p && p->next && p->next->next; p = p->next->next) {
            auto a = p->next, b = a->next;
            a->next = b->next;
            b->next = a;
            p->next = b;
        }

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

void printListNode(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

void test_case_1() {
    ListNode *head = new ListNode(1);
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(3);
    ListNode *p3 = new ListNode(4);
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    vector<int> ans{2, 1, 4, 3};

    ListNode *res = Solution().swapPairs(head);
    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
