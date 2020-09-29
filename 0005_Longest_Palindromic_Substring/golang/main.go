// way 1 dp
func longestPalindrome(s string) string {
	if len(s) == 0 {
		return ""
	}
	n := len(s)
	d := make([][]bool, n)
	for i := 0; i < n; i++ {
		d[i] = make([]bool, n)
	}
	start := 0
	len := 0
	for i := n - 1; i >= 0; i-- {
		for j := i; j < n; j++ {
			if i == j {
				d[i][j] = true
			} else if i+1 == j {
				d[i][j] = s[i] == s[j]
			} else {
				d[i][j] = d[i+1][j-1] && s[i] == s[j]
			}
			if d[i][j] == true && len < j-i+1 {
				start = i
				len = j - i + 1
			}
		}
	}
	return s[start : start+len]
}

// way 2
func longestPalindrome(s string) string {
	if len(s) == 0 {
		return ""
	}
	n := len(s)
	start := 0
	maxLen := 0
	for i := 0; i < n; i++ {
		len1 := extend(s, i, i)
		len2 := extend(s, i, i+1)
		mlen := max(len1, len2)
		if maxLen < mlen {
			start = i - (mlen-1)/2
			maxLen = mlen
		}
	}
	return s[start : start+maxLen]
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}

func extend(s string, i, j int) int {
	n := len(s)
	for i >= 0 && j < n && s[i] == s[j] {
		i--
		j++
	}
	return j - i - 1
}