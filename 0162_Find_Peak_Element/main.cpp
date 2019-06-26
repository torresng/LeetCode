#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findPeakElement(vector<int> &nums) {
        if (nums.size() == 1) {
            return 0;
        }

        int n = nums.size() - 1;
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid == l) {
                if (nums[mid] > nums[mid + 1]) {
                    return mid;
                } else {
                    l = mid + 1;
                    continue;
                }
            }
            if (mid == r) {
                if (nums[mid] > nums[mid - 1]) {
                    return mid;
                } else {
                    r = mid - 1;
                    continue;
                }
            }
            if ((nums[mid] > nums[mid - 1]) && (nums[mid] > nums[mid + 1])) {
                return mid;
            }

            if (nums[mid] > nums[mid - 1]) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return l;
    }
};

void test_case_1() {
    vector<int> nums{1, 2, 3, 1};
    int res = Solution().findPeakElement(nums);
    assert(res == 2);
}

void test_case_2() {
    vector<int> nums{1, 2, 1, 3, 5, 6, 4};
    int res = Solution().findPeakElement(nums);
    assert(res == 1 || res == 5);
}

void test_case_3() {
    vector<int> nums{1, 2};
    int res = Solution().findPeakElement(nums);
    assert(res == 1);
}

void test_case_4() {
    vector<int> nums{2, 1};
    int res = Solution().findPeakElement(nums);
    assert(res == 0);
}

void test_case_5() {
    vector<int> nums{1,2,3};
    int res = Solution().findPeakElement(nums);
    assert(res == 2);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();

    return 0;
}
