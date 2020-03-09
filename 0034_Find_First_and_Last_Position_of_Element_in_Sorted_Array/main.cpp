#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> searchRange(vector<int> &nums, int target) {
        if (nums.empty()) {
            return {-1, -1};
        }
        vector<int> res;
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] >= target) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }

        if (nums[l] != target) {
            return {-1, -1};
        }
        res.push_back(l);

        l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        res.push_back(l);

        return res;
    }
};

bool compare(vector<int> &v1, vector<int> &v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    for (int i = 0; i < (int)v1.size(); ++i) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

void test_case_1() {
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 8;
    vector<int> ans{3, 4};
    vector<int> res = Solution().searchRange(nums, target);
    assert(compare(res, ans) == true);
}

void test_case_2() {
    vector<int> nums{5, 7, 7, 8, 8, 10};
    int target = 6;
    vector<int> ans{-1, -1};
    vector<int> res = Solution().searchRange(nums, target);
    assert(compare(res, ans) == true);
}

int main(void) {
    test_case_1();
    test_case_2();

    return 0;
}
