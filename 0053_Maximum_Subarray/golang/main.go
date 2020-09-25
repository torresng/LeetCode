const MaxUint = ^uint(0)
const MinUint = 0
const MaxInt = int(MaxUint >> 1)
const MinInt = -MaxInt - 1

func max(a int, b int) int {
	if a >= b {
		return a
	}
	return b
}

func maxSubArray(nums []int) int {
	if len(nums) == 0 {
		return 0
	}
	res, sum := MinInt, 0
	for _, num := range nums {
		if sum < 0 {
			sum = num
		} else {
			sum += num
		}
		res = max(res, sum)
	}
	return res
}