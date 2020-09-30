func search(nums []int, target int) int {
	if nums == nil || len(nums) == 0 {
		return -1
	}
	n := len(nums)
	l, r := 0, n-1
	for l < r {
		mid := l + (r-l+1)/2
		if nums[mid] <= target {
			l = mid
		} else {
			r = mid - 1
		}
	}
	if nums[l] == target {
		return l
	}
	return -1
}