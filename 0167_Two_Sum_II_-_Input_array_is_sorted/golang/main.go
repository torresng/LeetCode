package solution

func twoSum(numbers []int, target int) []int {
	if len(numbers) == 0 {
		return nil
	}
	n := len(numbers)
	i, j := 0, n-1
	for i < j {
		sum := numbers[i] + numbers[j]
		if sum == target {
			return []int{i + 1, j + 1}
		}
		if sum < target {
			i++
		} else {
			j--
		}
	}
	return nil
}
