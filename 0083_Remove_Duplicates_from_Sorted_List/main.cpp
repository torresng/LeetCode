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
    ListNode *deleteDuplicates(ListNode *head) {
        if (head == NULL) {
            return head;
        }
        ListNode *p = head;
        while (p->next) {
            if (p->val == p->next->val) {
                p->next = p->next->next;
            } else {
                p = p->next;
            }
        }

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
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(1);
    ListNode *p3 = new ListNode(2);
    head->next = p1;
    p1->next = p2;
    p2->next = p3;

    vector<int> ans{1, 2};

    ListNode *res = Solution().deleteDuplicates(head);
    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
