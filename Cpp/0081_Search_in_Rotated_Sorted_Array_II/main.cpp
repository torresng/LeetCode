#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return false;
        }

        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;

            if (nums[mid] == target) {
                return true;
            }

            if (nums[l] < nums[mid] || nums[mid] > nums[r]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else if (nums[mid] < nums[r] || nums[mid] < nums[l]) {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            } else {
                --r;
            }
        }

        return false;
    }
};

void test_case_1() {
    vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    assert(Solution().search(nums, 0) == true);
}

void test_case_2() {
    vector<int> nums{2, 5, 6, 0, 0, 1, 2};
    assert(Solution().search(nums, 3) == false);
}

void test_case_3() {
    vector<int> nums{1};
    assert(Solution().search(nums, 1) == true);
}

void test_case_4() {
    vector<int> nums{1, 3, 1, 1, 1};
    assert(Solution().search(nums, 3) == true);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();

    return 0;
}
