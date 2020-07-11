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
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr || head->next->next == nullptr)
        {
            return head;
        }
        ListNode *evenHead = head->next;
        ListNode *o = head, *e = evenHead;
        while (e != nullptr && e->next != nullptr)
        {
            o->next = e->next;
            o = o->next;
            e->next = o->next;
            e = e->next;
        }
        o->next = evenHead;
        return head;
    }
};