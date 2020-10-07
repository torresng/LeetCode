// T = O(logx), S = O(1)
func mySqrt(x int) int {
	l, r := 0, x
	for l < r {
		mid := l + (r-l+1)/2
		if mid <= x/mid {
			l = mid
		} else {
			r = mid - 1
		}
	}
	return l
}