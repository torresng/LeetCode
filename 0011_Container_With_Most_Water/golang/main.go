func maxArea(height []int) int {
	if len(height) <= 1 {
		return 0
	}
	n := len(height)
	l, r := 0, n-1
	res := 0
	for l < r {
		h := min(height[l], height[r])
		res = max(res, (r-l)*h)
		if height[l] <= height[r] {
			l++
		} else {
			r--
		}
	}
	return res
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}