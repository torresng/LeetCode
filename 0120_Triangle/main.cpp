#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        if (triangle.empty())
            return 0;
        vector<int> dp(triangle.size(), 0);
        int res = numeric_limits<int>::max();
        dp[0] = triangle[0][0];
        for (int i = 1; i < (int)triangle.size(); ++i) {
            for (int j = i; j >= 0; --j) {
                if (j == 0) {
                    dp[0] = triangle[i][0] + dp[0];
                } else if (j == i) {
                    dp[j] = triangle[i][i] + dp[i - 1];
                } else {
                    dp[j] =
                        min(triangle[i][j] + dp[j - 1], triangle[i][j] + dp[j]);
                }
            }
        }
        for(auto v :dp) {
            if(v < res) {
                res = v;
            }
        }
        return res;
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
