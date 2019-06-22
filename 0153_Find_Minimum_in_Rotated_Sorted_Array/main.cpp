#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int l = 0;
        int r = nums.size() - 1;

        int res = numeric_limits<int>::max();
        while (l <= r) {
            int mid = (l + r) >> 1;
            res = min(res, nums[mid]);

            if (nums[l] <= nums[mid]) {
                res = min(res, nums[l]);
                l = mid + 1;
            } else {
                res = min(res, nums[mid + 1]);
                r = mid - 1;
            }
        }

        return res;
    }
};

void test_case_1() {
    vector<int> nums{3, 4, 5, 1, 2};
    assert(Solution().findMin(nums) == 1);
}

void test_case_2() {
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    assert(Solution().findMin(nums) == 0);
}

void test_case_3() {
    vector<int> nums{1};
    assert(Solution().findMin(nums) == 1);
}

void test_case_4() {
    vector<int> nums{3,1,2};
    assert(Solution().findMin(nums) == 1);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();

    return 0;
}
