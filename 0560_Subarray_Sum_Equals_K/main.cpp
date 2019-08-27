#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    int subarraySum(vector<int> &nums, int k) {
        unordered_map<int, int> hash;
        hash[0] = 1;
        int res = 0;

        int sum = 0;
        for (unsigned i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res += hash[sum - k];
            hash[sum]++;
        }
        return res;
    }
};

void test_case_1() {
    vector<int> nums{1, 1, 1};
    int k = 2;
    int ans = 2;

    int res = Solution().subarraySum(nums, k);

    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
