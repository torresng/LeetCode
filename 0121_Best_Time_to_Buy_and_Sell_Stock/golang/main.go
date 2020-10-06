func maxProfit(prices []int) int {
	if prices == nil || len(prices) == 0 {
		return 0
	}
	n := len(prices)
	buy := prices[0]
	res := 0
	for i := 1; i < n; i++ {
		if prices[i] < buy {
			buy = prices[i]
		} else {
			res = max(res, prices[i]-buy)
		}
	}
	return res
}

func max(a, b int) int {
	if a >= b {
		return a
	}
	return b
}