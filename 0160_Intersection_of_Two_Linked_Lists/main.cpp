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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p = headA, *q = headB;
        while (p != q) {
            if (p) {
                p = p->next;
            } else {
                p = headB;
            }
            if (q) {
                q = q->next;
            } else {
                q = headA;
            }
        }
        return p;
    }
};

void test_case_1() {
    ListNode *headA = new ListNode(4);
    ListNode *p1 = new ListNode(1);
    ListNode *p2 = new ListNode(8);
    ListNode *p3 = new ListNode(4);
    ListNode *p4 = new ListNode(5);
    headA->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    ListNode *headB = new ListNode(5);
    ListNode *p5 = new ListNode(0);
    ListNode *p6 = new ListNode(1);
    headB->next = p5;
    p5->next = p6;
    p6->next = p2;

    ListNode *ans = p2;

    ListNode *res = Solution().getIntersectionNode(headA, headB);
    assert(res == ans);
}

void test_case_2() {
    ListNode *headA = new ListNode(0);
    ListNode *p1 = new ListNode(9);
    ListNode *p2 = new ListNode(1);
    ListNode *p3 = new ListNode(2);
    ListNode *p4 = new ListNode(4);
    headA->next = p1;
    p1->next = p2;
    p2->next = p3;
    p3->next = p4;

    ListNode *headB = new ListNode(3);
    headB->next = p3;

    ListNode *ans = p3;

    ListNode *res = Solution().getIntersectionNode(headA, headB);
    assert(res == ans);
}

void test_case_3() {
    ListNode *headA = new ListNode(2);
    ListNode *p1 = new ListNode(6);
    ListNode *p2 = new ListNode(4);
    headA->next = p1;
    p1->next = p2;

    ListNode *headB = new ListNode(1);
    ListNode *p3 = new ListNode(5);
    headB->next = p3;

    ListNode *ans = NULL;

    ListNode *res = Solution().getIntersectionNode(headA, headB);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
