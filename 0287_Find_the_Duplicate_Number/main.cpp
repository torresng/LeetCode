#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int findDuplicate(vector<int> &nums) {
        int n = nums.size();
        int l = 1, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;

            int cnt = 0;
            for (int x : nums) {
                if (l <= x && x <= mid) {
                    ++cnt;
                }
            }
            if (cnt > mid - l + 1) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};

void test_case_1() {
    vector<int> nums{1, 3, 4, 2, 2};
    int ans = 2;
    int res = Solution().findDuplicate(nums);
    assert(res == ans);
}

void test_case_2() {
    vector<int> nums{3, 1, 3, 4, 2};
    int ans = 3;
    int res = Solution().findDuplicate(nums);
    assert(res == ans);
}

void test_case_3() {
    vector<int> nums{1, 4, 4, 2, 4};
    int ans = 4;
    int res = Solution().findDuplicate(nums);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
