#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (hash.count(target - nums[i])) {
                return {hash[target - nums[i]], i};
            }
            hash[nums[i]] = i;
        }
        return {-1, -1};
    }
};

bool compare(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) {
        return false;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

void test_case_1() {
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    vector<int> ans{0, 1};
    vector<int> res = Solution().twoSum(nums, target);
}

int main(void) {
    test_case_1();

    return 0;
}
