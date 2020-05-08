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
// Quick Sort
// T = O(nlog(n)), S = O(n), 432ms
class Solution {
    void quickSort(ListNode *start, ListNode *end) {
        if (start == end || start->next == end) {
            return;
        }
        int pivor = start->val;
        ListNode *slow = start, *fast = start->next;
        while (fast != end) {
            if (fast->val <= pivor) {
                slow = slow->next;
                swap(slow->val, fast->val);
            }
            fast = fast->next;
        }
        swap(start->val, slow->val);
        quickSort(start, slow);
        quickSort(slow->next, end);
    }

  public:
    ListNode *sortList(ListNode *head) {
        quickSort(head, nullptr);
        return head;
    }
};

// Merge Sort
// T = O(nlog(n)), S = O(log(n)), 48ms
class Solution {
    ListNode *mergeTwoList(ListNode *l1, ListNode *l2) {
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

  public:
    ListNode *sortList(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *right = sortList(slow->next);
        slow->next = nullptr;
        ListNode *left = sortList(head);
        return mergeTwoList(left, right);
    }
};
