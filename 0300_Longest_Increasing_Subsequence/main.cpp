#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> f(n);

        for (int i = 0; i < n; i++) {
            f[i] = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j] + 1);
                }
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            res = max(res, f[i]);
        }
        return res;
    }
};

void test_case_1() {
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    int ans = 4;
    int res = Solution().lengthOfLIS(nums);
    assert(res == ans);
}

void test_case_2() {
    vector<int> nums{10, 9, 2, 5, 3, 4};
    int ans = 3;
    int res = Solution().lengthOfLIS(nums);
    assert(res == ans);
}

void test_case_3() {
    vector<int> nums{3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
    int ans = 6;
    int res = Solution().lengthOfLIS(nums);
    assert(res == ans);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
