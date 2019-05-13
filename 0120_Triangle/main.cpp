#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        vector<int> dp(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; --i) {
            for (unsigned long j = 0; j < triangle[i].size(); ++j) {
                dp[j] = min(triangle[i][j] + dp[j], triangle[i][j] + dp[j + 1]);
            }
        }
        return dp[0];
    }
};

void test_case_1() {
    vector<vector<int>> triangle{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    assert(Solution().minimumTotal(triangle) == 11);
}

int main(void) {
    test_case_1();

    return 0;
}
