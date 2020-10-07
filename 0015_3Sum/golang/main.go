import "sort"

// T = O(n ^ 2), S = O(1)
func threeSum(nums []int) [][]int {
	if nums == nil || len(nums) == 0 {
		return nil
	}
	sort.Ints(nums)
	res := make([][]int, 0)
	n := len(nums)
	for k := n - 1; k >= 2; k-- {
		target := -nums[k]
		i, j := 0, k-1
		for i < j {
			sum := nums[i] + nums[j]
			if sum == target {
				res = append(res, []int{nums[i], nums[j], nums[k]})
				i++
				j--
				for i < j && nums[i] == nums[i-1] {
					i++
				}
				for i < j && nums[j] == nums[j+1] {
					j--
				}
			} else if sum < target {
				i++
				for i < j && nums[i] == nums[i-1] {
					i++
				}
			} else {
				j--
				for i < j && nums[j] == nums[j+1] {
					j--
				}
			}
			for k >= 2 && nums[k] == nums[k-1] {
				k--
			}
		}
	}
	return res
}