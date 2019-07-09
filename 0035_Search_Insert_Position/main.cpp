#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (nums[l] < target) {
            return l + 1;
        }
        return l;
    }
};

void test_case_1() {
    vector<int> nums{1, 3, 5, 6};
    int target = 5;
    int ans = 2;
    int res = Solution().searchInsert(nums, target);
    assert(res == ans);
}

void test_case_2() {
    vector<int> nums{1, 3, 5, 6};
    int target = 2;
    int ans = 1;
    int res = Solution().searchInsert(nums, target);
    assert(res == ans);
}

void test_case_3() {
    vector<int> nums{1, 3, 5, 6};
    int target = 7;
    int ans = 4;
    int res = Solution().searchInsert(nums, target);
    assert(res == ans);
}

void test_case_4() {
    vector<int> nums{1, 3, 5, 6};
    int target = 0;
    int ans = 0;
    int res = Solution().searchInsert(nums, target);
    assert(res == ans);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();

    return 0;
}
