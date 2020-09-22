func myPow(x float64, n int) float64 {
	if x == 0 {
		return 0
	}
	if n == 0 {
		return 1
	}
	N := n
	if N < 0 {
		N = -N
	}
	res := float64(1)
	for N != 0 {
		if N&1 != 0 {
			res *= x
		}
		N >>= 1
		x *= x
	}
	if n < 0 {
		return 1 / res
	}
	return res
}