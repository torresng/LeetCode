#include <cassert>
#include <iostream>
#include <limits>
#include <set>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxSumSubmatrix(vector<vector<int>> &matrix, int k) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int res = numeric_limits<int>::min();
        int rows = matrix.size(), cols = matrix[0].size();

        for (int l = 0; l < cols; ++l) {
            vector<int> sum(rows, 0);
            for (int r = l; r < cols; ++r) {
                for (int k = 0; k < rows; ++k) {
                    sum[k] += matrix[k][r];
                }

                int m = a(sum, k);
                if (m == k) {
                    return k;
                }
                res = max(res, m);
            }
        }
        return res;
    }

  private:
    // reference
    // https://github.com/torresng/Algorithms_practice/tree/master/cpp/max_sum
    int a(vector<int> &sum, int k) {
        int res = numeric_limits<int>::min();
        int curSum = 0;
        set<int> s{0};
        for (auto a : sum) {
            curSum += a;
            auto it = s.lower_bound(curSum - k);
            if (it != s.end()) {
                res = max(res, curSum - *it);
            }
            s.insert(curSum);
        }
        return res;
    }
};

void test_case_1() {
    vector<vector<int>> matrix{{1, 0, 1}, {0, -2, 3}};
    assert(Solution().maxSumSubmatrix(matrix, 2) == 2);
}

void test_case_2() {
    vector<vector<int>> matrix{{2, 2, -1}};
    assert(Solution().maxSumSubmatrix(matrix, 3) == 3);
}

void test_case_3() {
    vector<vector<int>> matrix{
        {5, -4, -3, 4},
        {-3, -4, 4, 5},
        {5, 1, 5, -4},
    };
    assert(Solution().maxSumSubmatrix(matrix, 3) == 2);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
