#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        unsigned long m = obstacleGrid.size();
        if (m == 0)
            return 0;
        unsigned long n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1)
            return 0;

        vector<long long> dp(n, 0);  // long long for prevent calculation overflow
        dp[0] = 1;
        for (unsigned long i = 0; i < m; ++i) {
            for (unsigned long j = 0; j < n; ++j) {
                if (obstacleGrid[i][j]) {
                    dp[j] = 0;
                    continue;
                }
                if (i > 0) {
                    dp[j] = dp[j];
                }
                if (j > 0) {
                    dp[j] += dp[j - 1];
                }
            }
        }
        return dp[n - 1];
    }
};

void test_case_1() {
        cout << endl;
    vector<vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int res = Solution().uniquePathsWithObstacles(obstacleGrid);
    cout << res << endl;
    assert(res == 2);
}

void test_case_2() {
        cout << endl;
    vector<vector<int>> obstacleGrid{{0}};
    int res = Solution().uniquePathsWithObstacles(obstacleGrid);
    cout << res << endl;
    assert(res == 1);
}

void test_case_3() {
        cout << endl;
    vector<vector<int>> obstacleGrid{{0, 1}};
    int res = Solution().uniquePathsWithObstacles(obstacleGrid);
    cout << res << endl;
    assert(res == 0);
}

void test_case_4() {
    vector<vector<int>> obstacleGrid{{1, 0}};
    int res = Solution().uniquePathsWithObstacles(obstacleGrid);
    cout << res << endl;
    assert(res == 0);
}

void test_case_5() {
    vector<vector<int>> obstacleGrid{{0}, {0}};
    int res = Solution().uniquePathsWithObstacles(obstacleGrid);
    cout << res << endl;
    assert(res == 1);
}

void test_case_6() {
    vector<vector<int>> obstacleGrid{{0,0}};
    int res = Solution().uniquePathsWithObstacles(obstacleGrid);
    cout << res << endl;
    assert(res == 1);
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
