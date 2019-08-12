#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // 枚舉當前數字放在哪個位置，
    // 也可以跟No.0046一樣枚舉當前位置放哪個數
    int n;
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> res;

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        n = nums.size();
        st = vector<bool>(n);
        path = vector<int>(n);
        sort(nums.begin(), nums.end());

        dfs(nums, 0, 0);
        return res;
    }

  private:
    void dfs(vector<int> &nums, int u, int start) {
        if (u == n) {
            res.push_back(path);
            return;
        }
        for (int i = start; i < n; i++) {
            if (!st[i]) {
                st[i] = true;
                path[i] = nums[u];
                dfs(nums, u + 1,
                    u + 1 < n && nums[u] == nums[u + 1] ? i + 1 : 0);
                st[i] = false;
            }
        }
    }
};

bool compare(vector<vector<int>> v1, vector<vector<int>> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    sort(v1.begin(), v1.end(), [](auto v11, auto v12) -> int {
        for (unsigned i = 0; i < v11.size(); i++) {
            if (v11[i] < v12[i]) {
                return -1;
            } else if (v11[i] > v12[i]) {
                return 1;
            }
        }
        return 0;
    });

    sort(v2.begin(), v2.end(), [](auto v11, auto v12) -> int {
        for (unsigned i = 0; i < v11.size(); i++) {
            if (v11[i] < v12[i]) {
                return -1;
            } else if (v11[i] > v12[i]) {
                return 1;
            }
        }
        return 0;
    });

    for (unsigned i = 0; i < v1.size(); i++) {
        for (unsigned j = 0; j < v1[i].size(); j++) {
            if (v1[i][j] != v2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void test_case_1() {
    vector<int> nums{1, 1, 2};
    vector<vector<int>> ans{{1, 1, 2}, {1, 2, 1}, {2, 1, 1}};

    vector<vector<int>> res = Solution().permuteUnique(nums);
    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
