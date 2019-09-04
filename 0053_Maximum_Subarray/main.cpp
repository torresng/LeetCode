#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int res = INT_MIN, last = 0;
        for (int i = 0; i < (int)nums.size(); i++) {
            int now = max(last, 0) + nums[i];
            res = max(res, now);
            last = now;
        }
        return res;
    }
};

void test_case_1() {
    vector<int> nums{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = 6;

    int res = Solution().maxSubArray(nums);
    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
