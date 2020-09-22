func isValid(c byte) bool {
	return (c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
}

func isSame(a byte, b byte) bool {
	if a >= 'A' && a <= 'Z' {
		a += 32
	}
	if b >= 'A' && b <= 'Z' {
		b += 32
	}
	return a == b
}

func isPalindrome(s string) bool {
	if len(s) == 0 {
		return true
	}
	var n = len(s)
	for i, j := 0, n-1; i < j; i, j = i+1, j-1 {
		for i < j && !isValid(s[i]) {
			i++
		}
		for i < j && !isValid(s[j]) {
			j--
		}
		if !isSame(s[i], s[j]) {
			return false
		}
	}
	return true
}
