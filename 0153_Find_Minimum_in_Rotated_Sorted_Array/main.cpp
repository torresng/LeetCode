#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (nums[0] < nums[n - 1]) {
            return nums[0];
        }
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[0] > nums[mid]) {
                // 如果nums[0] > nums[mid]，说明解就在nums[0, mid]中
                r = mid;
            } else {
                // 否则nums[mid]肯定不是解，解在nums[mid + 1, r]中
                l = mid + 1;
            }
        }
        return nums[l];
    }
};

void test_case_1() {
    vector<int> nums{3, 4, 5, 1, 2};
    int ans = 1;
    int res = Solution().findMin(nums);
    assert(res == ans);
}

void test_case_2() {
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int ans = 0;
    int res = Solution().findMin(nums);
    assert(res == ans);
}

void test_case_3() {
    vector<int> nums{1};
    int ans = 1;
    int res = Solution().findMin(nums);
    assert(res == ans);
}

void test_case_4() {
    vector<int> nums{3, 1, 2};
    int ans = 1;
    int res = Solution().findMin(nums);
    assert(res == ans);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();

    return 0;
}
