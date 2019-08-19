#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        int k = 1;
        for (int j = 1; j < n; j++) {
            if (nums[j] != nums[j - 1]) {
                nums[k++] = nums[j];
            }
        }
        return k;
    }
};

bool compare(vector<int> v1, int n, vector<int> v2, int m) {
    if (n != m) {
        return false;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (int i = 0; i < n; i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

void test_case_1() {
    vector<int> nums{1, 1, 2};
    int ans = 2;
    vector<int> ansNums{1, 2};

    int res = Solution().removeDuplicates(nums);
    vector<int> &resAns = nums;
    assert(res == ans);
    assert(compare(nums, res, ansNums, 2) == true);
}

int main() {
    test_case_1();

    return 0;
}
