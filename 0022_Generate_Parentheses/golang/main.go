func dfs(s string, left, right int, res *[]string) {
	if left == 0 && right == 0 {
		*res = append(*res, s)
		return
	}
	if left > 0 {
		dfs(s+"(", left-1, right, res)
	}
	if right > left {
		dfs(s+")", left, right-1, res)
	}
}

func generateParenthesis(n int) []string {
	if n == 0 {
		return nil
	}
	res := make([]string, 0)
	dfs("", n, n, &res)
	return res
}