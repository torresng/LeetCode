// T = O(n), S = O(n)
func isValid(s string) bool {
	if len(s) == 0 {
		return true
	}
	st := []rune{}
	for _, c := range s {
		if c == '(' {
			st = append(st, ')')
		} else if c == '{' {
			st = append(st, '}')
		} else if c == '[' {
			st = append(st, ']')
		} else {
			if len(st) == 0 || st[len(st)-1] != c {
				return false
			}
			st = st[:len(st)-1]
		}
	}
	return len(st) == 0
}