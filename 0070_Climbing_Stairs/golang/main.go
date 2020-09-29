// T = O(n), S = O(n)
func climbStairs(n int) int {
	if n == 0 {
		return 0
	}
	if n == 1 {
		return 1
	}
	d := make([]int, n)
	d[0] = 1
	d[1] = 2
	for i := 2; i < n; i++ {
		d[i] = d[i-2] + d[i-1]
	}
	return d[n-1]
}

// T = O(n), S = O(1)
func climbStairs(n int) int {
	if n == 0 {
		return 0
	}
	if n == 1 {
		return 1
	}
	first, second := 1, 2
	for i := 2; i < n; i++ {
		third := first + second
		first = second
		second = third
	}
	return second
}