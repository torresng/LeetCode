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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *p = dummy, *q = dummy;
        for (; q->next != nullptr && n > 0; n--) {
            q = q->next;
        }
        if (n != 0) {
            return dummy->next;
        }
        while (q->next != nullptr) {
            q = q->next;
            p = p->next;
        }
        p->next = p->next->next;
        return dummy->next;
    }
};
