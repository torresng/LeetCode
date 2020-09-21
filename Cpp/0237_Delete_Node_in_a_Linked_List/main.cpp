/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// T = O(1), S = O(1)
class Solution {
  public:
    void deleteNode(ListNode *node) { *node = *(node->next); }
};
