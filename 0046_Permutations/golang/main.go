func dfs(nums []int, i int, state int, res [][]int, v []int) [][]int {
	if len(nums) == i {
		temp := make([]int, len(nums))
		copy(temp, v)
		return append(res, temp)
	}
	for k := 0; k < len(nums); k++ {
		if ((state >> k) & 1) == 0 {
			v[k] = nums[i]
			res = dfs(nums, i+1, state+(1<<k), res, v)
		}
	}
	return res
}

func permute(nums []int) [][]int {
	if nums == nil && len(nums) == 0 {
		return nil
	}
	res := [][]int{}
	v := make([]int, len(nums))
	return dfs(nums, 0, 0, res, v)
}