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
// T = O(n), S = O(1)
class Solution {
  public:
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *heads = new ListNode(-1), *headg = new ListNode(-1);
        ListNode *sp = heads, *sg = headg;
        for (ListNode *p = head; p != nullptr; p = p->next) {
            if (p->val < x) {
                sp->next = p;
                sp = sp->next;
            } else {
                sg->next = p;
                sg = sg->next;
            }
        }
        sp->next = headg->next;
        sg->next = nullptr;
        return heads->next;
    }
};
