// T = O(logn), S = O(1)
func singleNonDuplicate(nums []int) int {
	if nums == nil || len(nums) == 0 {
		return -1
	}
	n := len(nums)
	l, r := 0, n-1
	for l <= r {
		mid := l + (r-l)/2
		if mid-1 >= 0 && nums[mid] == nums[mid-1] {
			mid--
		} else if mid+1 < n && nums[mid] == nums[mid+1] {

		} else {
			return nums[mid]
		}
		if mid&1 == 1 {
			r = mid - 1
		} else {
			l = mid + 2
		}
	}
	return -1
}