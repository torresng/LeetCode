func hammingDistance(x int, y int) int {
	return f(x ^ y)
}

func f(n int) int {
	res := 0
	for n != 0 {
		res++
		n = n & (n - 1)
	}
	return res
}