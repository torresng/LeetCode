func singleNumber(nums []int) int {
	if len(nums) == 0 {
		return -1
	}
	res := 0
	for _, num := range nums {
		res ^= num
	}
	return res
}