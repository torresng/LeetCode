#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // 枚舉當前位置放哪個數字
    int n;
    vector<bool> st;
    vector<int> path;
    vector<vector<int>> res;

  public:
    vector<vector<int>> permute(vector<int> &nums) {
        n = nums.size();
        st = vector<bool>(n);
        dfs(nums, 0);

        return res;
    }

  private:
    void dfs(vector<int> &nums, int u) {
        if (u == n) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < n; i++) {
            if (!st[i]) {
                st[i] = true;
                path.push_back(nums[i]);
                dfs(nums, u + 1);
                path.pop_back();
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
    vector<int> nums{1, 2, 3};
    vector<vector<int>> ans{{1, 2, 3}, {1, 3, 2}, {2, 1, 3},
                            {2, 3, 1}, {3, 1, 2}, {3, 2, 1}};

    vector<vector<int>> res = Solution().permute(nums);
}

int main() {
    test_case_1();

    return 0;
}
