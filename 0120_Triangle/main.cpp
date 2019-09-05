#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
  public:
    int minimumTotal(vector<vector<int>> &triangle) {
        int n = triangle.size();
        vector<vector<long long>> f(2, vector<long long>(n));
        f[0][0] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                f[i & 1][j] = INT_MAX;
                if (j > 0) {
                    f[i & 1][j] =
                        min(f[i & 1][j], f[i - 1 & 1][j - 1] + triangle[i][j]);
                }
                if (j < i) {
                    f[i & 1][j] =
                        min(f[i & 1][j], f[i - 1 & 1][j] + triangle[i][j]);
                }
            }
        }
        long long res = INT_MAX;
        for (int i = 0; i < n; i++) {
            res = min(res, f[n - 1 & 1][i]);
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
