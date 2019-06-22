#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) {
                return mid;
            }
            // 也判斷等於是為了處理nums=[3,1]，target=1的情況
            if (nums[l] <= nums[mid]) {
                if (target >= nums[l] && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (target > nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }

        return -1;
    }
};

void test_case_1() {
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    assert(Solution().search(nums, 0) == 4);
}

void test_case_2() {
    vector<int> nums{2, 4, 5, 6, 7, 0, 1};
    assert(Solution().search(nums, 0) == 5);
}

void test_case_3() {
    vector<int> nums{5, 6, 7, 0, 1, 2, 4};
    assert(Solution().search(nums, 0) == 3);
}

void test_case_4() {
    vector<int> nums{7, 0, 1, 2, 4, 5, 6};
    assert(Solution().search(nums, 0) == 1);
}

void test_case_5() {
    vector<int> nums{3,1};
    assert(Solution().search(nums, 1) == 1);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();

    return 0;
}
