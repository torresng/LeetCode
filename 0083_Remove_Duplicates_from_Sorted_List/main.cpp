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
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *cur = head, *next = head->next;
        while (next) {
            if (cur->val == next->val) {
                cur->next = next->next;
            } else {
                cur = cur->next;
            }
            next = next->next;
        }
        return head;
    }
};
