#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int strangePrinter(string s) {
        if (s.empty()) {
            return 0;
        }
        int n = s.size();
        vector<vector<int>> f(n + 1, vector<int>(n + 1));
        for (int len = 1; len <= n; len++) {
            for (int l = 0; l + len - 1 < n; l++) {
                int r = l + len - 1;
                f[l][r] = f[l + 1][r] + 1;
                for (int k = l + 1; k <= r; k++) {
                    if (s[k] == s[l]) {
                        f[l][r] = min(f[l][r], f[l][k - 1] + f[k + 1][r]);
                    }
                }
            }
        }
        return f[0][n - 1];
    }
};

void test_case_1() {
    string s = "aaabbb";
    int ans = 2;
    int res = Solution().strangePrinter(s);
    assert(res == ans);
}

void test_case_2() {
    string s = "aba";
    int ans = 2;
    int res = Solution().strangePrinter(s);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
