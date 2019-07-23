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
    ListNode *reverseList(ListNode *head) {
        if (!head) {
            return head;
        }

        ListNode *a = head, *b = head->next;
        while (b) {
            ListNode *c = b->next;
            b->next = a;
            a = b, b = c;
        }
        head->next = NULL;

        return a;
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
    vector<int> ans{5, 4, 3, 2, 1};

    ListNode *res = Solution().reverseList(head);

    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
