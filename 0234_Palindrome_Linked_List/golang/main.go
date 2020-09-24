/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func isPalindrome(head *ListNode) bool {
	if head == nil || head.Next == nil {
		return true
	}
	p := head
	n := 0
	for p != nil {
		n++
		p = p.Next
	}
	var pre *ListNode = nil
	p = head
	for i := 0; i < n/2; i++ {
		next := p.Next
		p.Next = pre
		pre = p
		p = next
	}
	if n%2 == 1 {
		p = p.Next
	}
	for pre != nil {
		if pre.Val != p.Val {
			return false
		}
		pre = pre.Next
		p = p.Next
	}
	return true
}