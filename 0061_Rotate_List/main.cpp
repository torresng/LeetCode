/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// T = O(n), S = O(1)
class Solution {
  public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == nullptr || head->next == nullptr || k <= 0) {
            return head;
        }
        ListNode *p = head;
        int n = 1;
        for (; p->next; p = p->next) {
            n++;
        }
        p->next = head;
        k = k % n;
        ListNode *newEnd = head;
        for (int i = 0; i < n - k - 1; i++) {
            newEnd = newEnd->next;
        }
        ListNode *newHead = newEnd->next;
        newEnd->next = nullptr;
        return newHead;
    }
};
