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
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0) {
            return head;
        }
        int n = 0;
        ListNode *p = head;
        while (p) {
            p = p->next;
            ++n;
        }

        k %= n;

        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        ListNode *slow = dummy, *fast = dummy;
        while (k) {
            fast = fast->next;
            --k;
        }

        while (fast->next) {
            slow = slow->next;
            fast = fast->next;
        }

        fast->next = head;
        head = slow->next;
        slow->next = NULL;

        return head;
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
    int k = 2;

    vector<int> ans{4, 5, 1, 2, 3};

    ListNode *res = Solution().rotateRight(head, k);
    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
