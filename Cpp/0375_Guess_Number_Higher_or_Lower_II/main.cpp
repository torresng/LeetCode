#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
        for (int j = 2; j <= n; ++j) {
            for (int i = j - 1; i > 0; --i) {
                int global_min = INT_MAX;
                for (int k = i + 1; k < j; ++k) {
                    int local_max = k + max(dp[i][k - 1], dp[k + 1][j]);
                    global_min = min(global_min, local_max);
                }
                dp[i][j] = (i + 1 == j) ? i : global_min;
            }
        }
        return dp[1][n];
    }
};

void test_case_1() { assert(Solution().getMoneyAmount(10) == 16); }

int main(void) {
    test_case_1();
    return 0;
}
