package solution

func twoSum(numbers []int, target int) []int {
	if len(numbers) == 0 {
		return nil
	}
	n := len(numbers)
	for i, j := 0, n-1; i < j; {
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
