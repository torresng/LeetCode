/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// T = O(n * log(k)), S = O(log(k))
class Solution {
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *dummy = new ListNode(-1), *p = dummy;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1) {
            p->next = l1;
        }
        if (l2) {
            p->next = l2;
        }
        return dummy->next;
    }
    ListNode *merge(vector<ListNode *> lists, int start, int end) {
        if (start == end) {
            return lists[start];
        }
        if (start > end) {
            return nullptr;
        }
        int mid = (start + end) >> 1;
        ListNode *left = merge(lists, start, mid);
        ListNode *right = merge(lists, mid + 1, end);
        return mergeTwoLists(left, right);
    }

  public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        return merge(lists, 0, n - 1);
    }
};
