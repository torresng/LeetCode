#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &matrix, int target) {
        if (matrix.empty() || matrix[0].empty()) {
            return false;
        }
        int n = matrix.size(), m = matrix[0].size();

        int l = 0, r = n * m - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (matrix[mid / m][mid % m] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return matrix[l / m][l % m] == target;
    }
};

void test_case_1() {
    vector<vector<int>> matrix{
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    int target = 3;
    bool ans = true;
    bool res = Solution().searchMatrix(matrix, target);
    assert(res == ans);
}

void test_case_2() {
    vector<vector<int>> matrix{
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    int target = 13;
    bool ans = false;
    bool res = Solution().searchMatrix(matrix, target);
    assert(res == ans);
}

void test_case_3() {
    vector<vector<int>> matrix{};
    int target = 0;
    bool ans = false;
    bool res = Solution().searchMatrix(matrix, target);
    assert(res == ans);
}

void test_case_4() {
    vector<vector<int>> matrix{
        {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
    int target = 5;
    bool ans = true;
    bool res = Solution().searchMatrix(matrix, target);
    assert(res == ans);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();

    return 0;
}
