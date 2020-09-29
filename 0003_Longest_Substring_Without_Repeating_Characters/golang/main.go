func max(a int, b int) int {
	if a >= b {
		return a
	}
	return b
}

func lengthOfLongestSubstring(s string) int {
	if len(s) == 0 {
		return 0
	}
	n := len(s)
	mMap := make(map[byte]int)
	res := 0
	i := 0
	j := 0
	for j < n {
		mMap[s[j]]++
		for i < j && mMap[s[j]] > 1 {
			mMap[s[i]]--
			i++
		}
		res = max(res, j-i+1)
		j++
	}
	return res
}