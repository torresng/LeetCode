#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid) {
        unsigned long len = obstacleGrid[0].size();
        if (obstacleGrid[obstacleGrid.size() - 1][len - 1] == 1)
            return 0;
        vector<unsigned long> dp(len + 1, 0);
        if(obstacleGrid[0][0] == 0) {
            dp[0] = 1;
            for(unsigned long i = 1; i < len; ++i) {
                if(obstacleGrid[0][i] == 0) {
                    dp[i] = 1;
                } else {
                    break;
                }
            }

        }
        if (obstacleGrid[0][0] == 0) {
            dp[0] = 1;
        } else {
            dp[0] = 0;
        }
        for (unsigned long i = 1; i < obstacleGrid.size(); ++i) {
            if (obstacleGrid[i][0] == 0) {
                dp[0] = dp[0];
            } else {
                dp[0] = 0;
            }
            for (unsigned long j = 1; j < len; ++j) {
                if (obstacleGrid[i][j] == 0) {
                    dp[j] = dp[j - 1] + dp[j];
                } else {
                    dp[j] = 0;
                }
            }
        }
        return dp[len - 1];
    }
};

void test_case_1() {
    vector<vector<int>> obstacleGrid{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    int res = Solution().uniquePathsWithObstacles(obstacleGrid);
    cout << res << endl;
    assert(res == 2);
}

void test_case_2() {
    vector<vector<int>> obstacleGrid{{0}};
    int res = Solution().uniquePathsWithObstacles(obstacleGrid);
    cout << res << endl;
    assert(res == 1);
}

void test_case_3() {
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

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();
    return 0;
}
