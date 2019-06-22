#include <cassert>
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class Solution {
  public:
    // 4ms
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (nums[0] < nums[n - 1]) {
            return nums[0];
        }

        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;

            if (mid + 1 < n && nums[mid] > nums[mid + 1]) {
                return nums[mid + 1];
            }
            if (mid - 1 < n && nums[mid - 1] > nums[mid]) {
                return nums[mid];
            }
            if (nums[l] < nums[mid]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return nums[l];
    }

    // 0ms
    /*
    int findMin(vector<int> &nums) {
        int n = nums.size();
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return nums[l];
    }
    */
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
    vector<int> nums{3, 1, 2};
    assert(Solution().findMin(nums) == 1);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();

    return 0;
}
