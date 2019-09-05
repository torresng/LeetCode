#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        for (int i = 1; i <= n; i++) {
            if (s[i - 1] != '0') {
                dp[i] += dp[i - 1];
            }
            if (i >= 2) {
                int t = (s[i - 2] - '0') * 10 + s[i - 1] - '0';
                if (t >= 10 && t <= 26) {
                    dp[i] += dp[i - 2];
                }
            }
        }
        return dp[n];
    }
};

void test_case_1() {
    string s = "12";
    int ans = 2;

    int res = Solution().numDecodings(s);

    assert(res == ans);
}

void test_case_2() {
    string s = "226";
    int ans = 3;

    int res = Solution().numDecodings(s);

    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
