#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }

        int n = nums.size();
        vector<int> helper(n);
        int maxLen = 1;

        helper[0] = nums[0];
        for (int i = 1; i < n; ++i) {
            int x = nums[i];
            int l = 0, r = maxLen - 1;
            while (l < r) {
                int mid = (l + r) >> 1;
                if (helper[mid] >= x) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            if (helper[r] >= x) {
                helper[r] = x;
                continue;
            }
            helper[r + 1] = x;

            if (r + 2 > maxLen) {
                maxLen = r + 2;
            }
        }
        return maxLen;
    }
};

void test_case_1() {
    vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
    int ans = 4;
    int res = Solution().lengthOfLIS(nums);
    cout << res << endl;
    assert(res == ans);
}

void test_case_2() {
    vector<int> nums{10, 9, 2, 5, 3, 4};
    int ans = 3;
    int res = Solution().lengthOfLIS(nums);
    cout << res << endl;
    assert(res == ans);
}

void test_case_3() {
    vector<int> nums{3, 5, 6, 2, 5, 4, 19, 5, 6, 7, 12};
    int ans = 6;
    int res = Solution().lengthOfLIS(nums);
    cout << res << endl;
    assert(res == ans);
}

int main(void) {
    /*
     *test_case_1();
     *test_case_2();
     */
    test_case_3();

    return 0;
}
