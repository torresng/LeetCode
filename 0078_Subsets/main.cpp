#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> res;
        int n = nums.size();
        for (int i = 0; i < (1 << n); i++) {
            vector<int> now;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    now.push_back(nums[j]);
                }
            }
            res.push_back(now);
        }

        return res;
    }
};

bool compare(vector<vector<int>> v1, vector<vector<int>> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    sort(
        v1.begin(), v1.end(), [](vector<int> vv1, vector<int> vv2) -> auto {
            if (vv1.size() != vv2.size()) {
                return (int)vv1.size() - (int)vv2.size();
            }
            for (unsigned i = 0; i < vv1.size(); i++) {
                if (vv1[i] != vv2[i]) {
                    return vv1[i] - vv2[i];
                }
            }
            return 0;
        });

    return true;
}

void test_case_1() {
    vector<int> nums{1, 2, 3};
    vector<vector<int>> ans{{3},    {1},    {2},    {1, 2, 3},
                            {1, 3}, {2, 3}, {1, 2}, {}};

    vector<vector<int>> res = Solution().subsets(nums);
    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
