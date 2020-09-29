// T = O(n*m), S = O(n*m)
func minDistance(word1 string, word2 string) int {
	if len(word1) == 0 && len(word2) == 0 {
		return 0
	}
	n, m := len(word1), len(word2)
	d := make([][]int, n+1)
	for i := 0; i <= n; i++ {
		d[i] = make([]int, m+1)
	}
	for i := 0; i <= n; i++ {
		d[i][0] = i
	}
	for j := 0; j <= m; j++ {
		d[0][j] = j
	}
	for i := 1; i <= n; i++ {
		for j := 1; j <= m; j++ {
			if word1[i-1] == word2[j-1] {
				d[i][j] = d[i-1][j-1]
			} else {
				d[i][j] = min3(d[i-1][j-1], d[i-1][j], d[i][j-1]) + 1
			}
		}
	}
	return d[n][m]
}

// T = O(n*m), S = O(m)
func minDistance(word1 string, word2 string) int {
	if len(word1) == 0 && len(word2) == 0 {
		return 0
	}
	n, m := len(word1), len(word2)
	d := make([]int, m+1)
	for j := 0; j <= m; j++ {
		d[j] = j
	}
	for i := 1; i <= n; i++ {
		pre := d[0]
		d[0] = i
		for j := 1; j <= m; j++ {
			tmp := d[j]
			if word1[i-1] == word2[j-1] {
				d[j] = pre
			} else {
				d[j] = min3(pre, d[j], d[j-1]) + 1
			}
			pre = tmp
		}
	}
	return d[m]
}

func min3(a, b, c int) int {
	return min2(a, min2(b, c))
}

func min2(a, b int) int {
	if a < b {
		return a
	}
	return b
}

