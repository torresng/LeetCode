func setZeroes(matrix [][]int) {
	if matrix == nil || len(matrix) == 0 || len(matrix[0]) == 0 {
		return
	}
	n, m := len(matrix), len(matrix[0])
	row, col := false, false
	for i := 0; i < n; i++ {
		if matrix[i][0] == 0 {
			row = true
			break
		}
	}
	for j := 0; j < m; j++ {
		if matrix[0][j] == 0 {
			col = true
			break
		}
	}
	for i := 1; i < n; i++ {
		for j := 1; j < m; j++ {
			if matrix[i][j] == 0 {
				matrix[i][0] = 0
				matrix[0][j] = 0
			}
		}
	}
	for i := 1; i < n; i++ {
		for j := 1; j < m; j++ {
			if matrix[i][0] == 0 || matrix[0][j] == 0 {
				matrix[i][j] = 0
			}
		}
	}
	if row == true {
		for i := 0; i < n; i++ {
			matrix[i][0] = 0
		}
	}
	if col == true {
		for j := 0; j < m; j++ {
			matrix[0][j] = 0
		}
	}
}