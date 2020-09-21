#include <iostream>
#include <vector>

using namespace std;

class Solution {
  private:
    int n;
    vector<int> path;
    vector<vector<int>> res;

  public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        dfs(nums, 0);
        return res;
    }

  private:
    void dfs(vector<int> &nums, int u) {
        if (u == n) {
            res.push_back(path);
            return;
        }
        int k = 0;
        while (u + k < n && nums[u + k] == nums[u]) {
            k++;
        }
        for (int i = 0; i <= k; i++) {
            dfs(nums, u + k);
            path.push_back(nums[u]);
        }
        for (int i = 0; i < k; i++) {
            path.pop_back();
        }
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
    vector<int> nums{1, 2, 2};
    vector<vector<int>> ans{{2}, {1}, {1, 2, 2}, {2, 2}, {1, 2}, {}};

    vector<vector<int>> res = Solution().subsetsWithDup(nums);
    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
