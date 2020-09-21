#include <cassert>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findMin(vector<int> &nums) {
        int n = nums.size();
        if (nums[0] < nums[n - 1]) {
            return nums[0];
        }

        int l = 0;
        int r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] > nums[r]) {
                l = mid + 1;
            } else if (nums[mid] < nums[r]) {
                r = mid;
            } else {
                // 注意這里不能改為 ++l，因為上面只判斷是了右序列是否有序，
                // 沒有判斷左序列是否有序
                --r;
            }
        }
        return nums[l];
    }
};

void test_case_1() {
    vector<int> nums{1, 3, 5};
    assert(Solution().findMin(nums) == 1);
}

void test_case_2() {
    vector<int> nums{2, 2, 2, 0, 1};
    assert(Solution().findMin(nums) == 0);
}

int main(void) {
    test_case_1();
    test_case_2();

    return 0;
}
