#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int rob(vector<int> &nums) {
        int n = nums.size();
        vector<int> f(n + 1), g(n + 1);
        for (int i = 1; i <= n; i++) {
            f[i] = max(f[i - 1], g[i - 1]);
            g[i] = f[i - 1] + nums[i - 1];
        }
        return max(f[n], g[n]);
    }
};

void test_case_1() {
    vector<int> nums{1, 2, 3, 1};
    int ans = 4;

    int res = Solution().rob(nums);
    assert(res == ans);
}

void test_case_2() {
    vector<int> nums{2, 7, 9, 3, 1};
    int ans = 12;

    int res = Solution().rob(nums);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
