package solution

func twoSum(nums []int, target int) []int {
	if len(nums) == 0 {
		return nil
	}
	hash := make(map[int]int)
	for i1, v1 := range nums {
		v2 := target - nums[i1]
		i2, ok := hash[v2]
		if ok {
			return []int{i1, i2}
		}
		hash[v1] = i1
	}
	return nil
}
