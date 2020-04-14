// T = O(n*m), S = O(n);
class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        if (obstacleGrid.empty() || obstacleGrid[0].empty()) {
            return 0;
        }
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<long> d(n);
        d[0] = obstacleGrid[0][0] == 1 ? 0 : 1;
        for (int i = 0; i < m; i++) {
            d[0] = obstacleGrid[i][0] == 1 ? 0 : d[0];
            for (int j = 1; j < n; j++) {
                d[j] = obstacleGrid[i][j] == 1 ? 0 : d[j - 1] + d[j];
            }
        }
        return d[n - 1];
    }
};
