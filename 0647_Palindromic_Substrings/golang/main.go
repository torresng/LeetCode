// way 1
func countSubstrings(s string) int {
	if len(s) == 0 {
		return 0
	}
	n := len(s)
	d := make([][]bool, n)
	for i := 0; i < n; i++ {
		d[i] = make([]bool, n)
	}
	res := 0
	for i := n - 1; i >= 0; i-- {
		for j := i; j < n; j++ {
			if i == j {
				d[i][j] = true
			} else if i+1 == j {
				d[i][j] = s[i] == s[j]
			} else {
				d[i][j] = d[i+1][j-1] && s[i] == s[j]
			}
			if d[i][j] {
				res++
			}
		}
	}
	return res
}

// way 2
func extend(s string, i int, j int) int {
	n := len(s)
	res := 0
	for i >= 0 && j < n && s[i] == s[j] {
		i--
		j++
		res++
	}
	return res
}
func countSubstrings(s string) int {
	if len(s) == 0 {
		return 0
	}
	n := len(s)
	res := 0
	for i := 0; i < n; i++ {
		res += extend(s, i, i) + extend(s, i, i+1)
	}
	return res
}