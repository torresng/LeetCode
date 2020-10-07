// T = O(n * m), S = O(n * m)
func minPathSum(grid [][]int) int {
	if grid == nil || len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}
	n, m := len(grid), len(grid[0])
	d := make([][]int, n)
	for i := 0; i < n; i++ {
		d[i] = make([]int, m)
	}
	d[0][0] = grid[0][0]
	for i := 1; i < n; i++ {
		d[i][0] = d[i-1][0] + grid[i][0]
	}
	for j := 1; j < m; j++ {
		d[0][j] = d[0][j-1] + grid[0][j]
	}
	for i := 1; i < n; i++ {
		for j := 1; j < m; j++ {
			d[i][j] = min(d[i-1][j], d[i][j-1]) + grid[i][j]
		}
	}
	return d[n-1][m-1]
}

// T = O(n * m), S = O(n * m)
func minPathSum(grid [][]int) int {
	if grid == nil || len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}
	n, m := len(grid), len(grid[0])
	d := make([]int, m)
	d[0] = grid[0][0]
	for j := 1; j < m; j++ {
		d[j] = d[j-1] + grid[0][j]
	}
	for i := 1; i < n; i++ {
		d[0] = d[0] + grid[i][0]
		for j := 1; j < m; j++ {
			d[j] = min(d[j], d[j-1]) + grid[i][j]
		}
	}
	return d[m-1]
}

func min(a, b int) int {
	if a <= b {
		return a
	}
	return b
}