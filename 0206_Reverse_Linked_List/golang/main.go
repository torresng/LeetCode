/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func reverseList(head *ListNode) *ListNode {
	if head == nil || head.Next == nil {
		return head
	}
	var pre, p *ListNode = nil, head
	for p != nil {
		next := p.Next
		p.Next = pre
		pre = p
		p = next
	}
	return pre
}