/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// T = O(n), S = O(1);
class Solution {
  public:
    bool isPalindrome(ListNode *head) {
        int count = 0;
        for (ListNode *p = head; p; count++, p = p->next)
            ;
        ListNode *cur = head, *pre = nullptr;
        for (int i = 0; i < count / 2; i++) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        if (count % 2) {
            cur = cur->next;
        }
        while (cur) {
            if (pre->val != cur->val) {
                return false;
            }
            cur = cur->next;
            pre = pre->next;
        }
        return true;
    }
};
