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
        vector<int> helper;
        for (int i = 0; i < n; ++i) {
            int index = binarySearch(helper, nums[i]);
            if (index < (int)helper.size()) {
                helper[index] = nums[i];
            } else {
                helper.push_back(nums[i]);
            }
        }

        return helper.size();
    }

    int binarySearch(vector<int> &nums, int key) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= key) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return l;
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
