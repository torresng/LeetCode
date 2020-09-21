#include <iostream>
#include <vector>

using namespace std;

class Solution {
  private:
    vector<vector<int>> res;
    vector<int> path;

  public:
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, 1, n);
        return res;
    }

  private:
    void dfs(int k, int start, int n) {
        if (k == 0) {
            if (n == 0) {
                res.push_back(path);
            }
            return;
        }
        // 9 - i + 1 >= k
        // => 10 - i >= k
        // => 10 - k >= i
        for (int i = start; i <= 10 - k; i++) {
            path.push_back(i);
            dfs(k - 1, i + 1, n - i);
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
    int k = 3, n = 7;
    vector<vector<int>> ans{{1, 2, 4}};

    vector<vector<int>> res = Solution().combinationSum3(k, n);
    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
