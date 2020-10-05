func searchMatrix(matrix [][]int, target int) bool {
	if matrix == nil || len(matrix) == 0 || len(matrix[0]) == 0 {
		return false
	}
	n, m := len(matrix), len(matrix[0])
	l, r := 0, n*m-1
	for l <= r {
		mid := l + (r-l)/2
		i, j := mid/m, mid%m
		if matrix[i][j] == target {
			return true
		}
		if matrix[i][j] < target {
			l = mid + 1
		} else {
			r = mid - 1
		}
	}
	return false
}