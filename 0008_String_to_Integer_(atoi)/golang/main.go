import "math"

func myAtoi(s string) int {
	if len(s) == 0 {
		return 0
	}
	n := len(s)
	i := 0
	for i < n && s[i] == ' ' {
		i++
	}
	if i == n {
		return 0
	}
	t := 1
	if s[i] == '+' {
		i++
	} else if s[i] == '-' {
		t = -1
		i++
	}
	for i < n && s[i] == '0' {
		i++
	}
	val := int64(0)
	cnt := 0
	for i < n && s[i] >= '0' && s[i] <= '9' {
		val = val*10 + int64(s[i]-'0')
		i++
		cnt++
		if cnt > 10 {
			break
		}
	}
	val *= int64(t)
	if val > math.MaxInt32 {
		return math.MaxInt32
	}
	if val < math.MinInt32 {
		return math.MinInt32
	}
	return int(val)
}