func strStr(haystack string, needle string) int {
	if len(haystack) == 0 && len(needle) == 0 {
		return 0
	}
	n, m := len(haystack), len(needle)
	for i := 0; i <= n-m; i++ {
		j, k := i, 0
		for j < n && k < m && haystack[j] == needle[k] {
			j++
			k++
		}
		if k == m {
			return i
		}
	}
	return -1
}