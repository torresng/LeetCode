func majorityElement(nums []int) int {
	if len(nums) == 0 {
		return -1
	}
	res := 0
	cnt := 0
	for _, num := range nums {
		if cnt == 0 {
			res = num
			cnt = 1
		} else {
			if num == res {
				cnt++
			} else {
				cnt--
			}
		}
	}
	return res
}