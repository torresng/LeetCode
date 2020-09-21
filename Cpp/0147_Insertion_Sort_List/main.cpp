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
// T = O(n^2), S = O(1)
class Solution
{
public:
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == nullptr)
        {
            return nullptr;
        }
        ListNode *dummy = new ListNode(-1);
        ListNode *p = dummy, *cur = head;
        while (cur)
        {
            ListNode *next = cur->next;
            if (p->next && p->next->val > cur->val)
            {
                p = dummy;
            }
            while (p->next && p->next->val < cur->val)
            {
                p = p->next;
            }
            cur->next = p->next;
            p->next = cur;
            cur = next;
        }
        return dummy->next;
    }
};