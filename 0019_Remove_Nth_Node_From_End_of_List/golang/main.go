/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNthFromEnd(head *ListNode, n int) *ListNode {
	if head == nil {
		return nil
	}
	p := head
	for i := 0; i < n; i++ {
		p = p.Next
	}
	dummy := new(ListNode)
	q := dummy
	dummy.Next = head
	for p != nil {
		q = q.Next
		p = p.Next
	}
	q.Next = q.Next.Next
	return dummy.Next
}