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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast) {
            slow = slow->next;
            fast = fast->next;
            if (fast) {
                fast = fast->next;
            } else {
                break;
            }
            if (slow == fast) {
                slow = head;
                while (slow != fast) {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};

void test_case_1() {
    ListNode *head = new ListNode(3);
    ListNode *p1 = new ListNode(2);
    ListNode *p2 = new ListNode(0);
    ListNode *p3 = new ListNode(-4);
    head->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p1;
    ListNode *ans = p1;

    ListNode *res = Solution().detectCycle(head);
    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
