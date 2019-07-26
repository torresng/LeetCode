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
    ListNode *sortList(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;

        int n = 0;
        for (ListNode *p = head; p; p = p->next) {
            ++n;
        }

        for (int i = 1; i < n; i *= 2) {
            ListNode *begin = dummy;
            for (int j = 0; j + i < n; j += i * 2) {
                ListNode *first = begin->next, *second = begin->next;
                for (int k = 0; k < i; ++k) {
                    second = second->next;
                }
                int f = 0, s = 0;
                while (f < i && s < i && second) {
                    if (first->val <= second->val) {
                        begin = begin->next = first;
                        first = first->next;
                        ++f;
                    } else {
                        begin = begin->next = second;
                        second = second->next;
                        ++s;
                    }
                }

                while (f < i) {
                    begin = begin->next = first;
                    first = first->next;
                    ++f;
                }
                while (s < i && second) {
                    begin = begin->next = second;
                    second = second->next;
                    ++s;
                }
                begin->next = second;
            }
        }

        return dummy->next;
    }
};

ListNode *initList(vector<int> vec) {
    ListNode dummy = ListNode(-1);
    ListNode *p = &dummy;
    for (auto v : vec) {
        p->next = new ListNode(v);
    }
    return dummy.next;
}

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
    ListNode *head = initList({4, 2, 1, 3});
    vector<int> ans{1, 2, 3, 4};
    ListNode *res = Solution().sortList(head);
    assert(compare(res, ans) == true);
}

void test_case_2() {
    ListNode *head = initList({-1, 5, 3, 4, 0});
    vector<int> ans{-1, 0, 3, 4, 5};
    ListNode *res = Solution().sortList(head);
    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
