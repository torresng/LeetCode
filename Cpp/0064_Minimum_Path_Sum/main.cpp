// T = O(n * m), S = O(m)
class Solution {
  public:
    int minPathSum(vector<vector<int>> &grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> d(m);

        d[0] = grid[0][0];
        for (int i = 1; i < m; i++) {
            d[i] = d[i - 1] + grid[0][i];
        }
        for (int i = 1; i < n; i++) {
            d[0] += grid[i][0];
            for (int j = 1; j < m; j++) {
                d[j] = min(d[j - 1], d[j]) + grid[i][j];
            }
        }
        return d[m - 1];
    }
};
