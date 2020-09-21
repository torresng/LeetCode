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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy, *cur = dummy->next;
        while (cur != nullptr) {
            while (cur->next != nullptr && cur->val == cur->next->val) {
                cur = cur->next;
            }
            if (prev->next != cur) {
                prev->next = cur->next;
            } else {
                prev = prev->next;
            }
            cur = prev->next;
        }
        return dummy->next;
    }
};
