#include <vector>

using namespace std;

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        int n = obstacleGrid.size(), m = obstacleGrid[0].size();
        vector<vector<long long>> dp(n, vector<long long>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (obstacleGrid[i][j]) {
                    continue;
                }
                if (!i && !j) {
                    dp[0][0] = 1;
                }
                if (i > 0) {
                    dp[i][j] += dp[i - 1][j];
                }
                if (j > 0) {
                    dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[n - 1][m - 1];
    }
};

void test_case_1() {
    vector<vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    assert(Solution().uniquePathsWithObstacles(obstacleGrid) == 2);
}

void test_case_2() {
    vector<vector<int>> obstacleGrid{{0}};
    assert(Solution().uniquePathsWithObstacles(obstacleGrid) == 1);
}

void test_case_3() {
    vector<vector<int>> obstacleGrid{{0, 1}};
    assert(Solution().uniquePathsWithObstacles(obstacleGrid) == 0);
}

void test_case_4() {
    vector<vector<int>> obstacleGrid{{1, 0}};
    assert(Solution().uniquePathsWithObstacles(obstacleGrid) == 0);
}

void test_case_5() {
    vector<vector<int>> obstacleGrid{{0}, {0}};
    assert(Solution().uniquePathsWithObstacles(obstacleGrid) == 1);
}

void test_case_6() {
    vector<vector<int>> obstacleGrid{{0, 0}};
    assert(Solution().uniquePathsWithObstacles(obstacleGrid) == 1);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();
    test_case_6();
    return 0;
}
