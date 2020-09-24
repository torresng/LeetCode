func missingNumber(nums []int) int {
	if nums == nil || len(nums) == 0 {
		return 0
	}
	res := len(nums)
	for i := 0; i < len(nums); i++ {
		res = res ^ i ^ nums[i]
	}
	return res
}