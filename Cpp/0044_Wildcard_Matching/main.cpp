#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    // Greedy 4ms
    bool isMatch(string s, string p) {
        size_t i = 0;
        size_t j = 0;
        int si = -1;
        int sj = -1;
        while (i < s.size()) {
            if ((s[i] == p[j]) || p[j] == '?') {
                ++i;
                ++j;
            } else if (p[j] == '*') {
                si = i;
                sj = j++;
            } else if (sj != -1) {
                j = sj;
                i = ++si;
            } else {
                return false;
            }
        }

        while (j < p.size() && p[j] == '*') {
            ++j;
        }
        return (j == p.size());
    }

    // Dynamic Programming 100ms
    /*
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        dp[0][0] = true;

        for (int i = 0; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (p[j - 1] != '*') {
                    dp[i][j] = (i > 0) && dp[i - 1][j - 1] &&
                               ((s[i - 1] == p[j - 1]) || (p[j - 1] ==
    '?')); } else { dp[i][j] = ((i > 0) && dp[i - 1][j]) || dp[i][j - 1];
                }
            }
        }
        return dp[n][m];
    }
    */
};

void test_case_1() { assert(Solution().isMatch("aa", "a") == false); }

void test_case_2() { assert(Solution().isMatch("aa", "*") == true); }

void test_case_3() { assert(Solution().isMatch("cb", "?a") == false); }

void test_case_4() { assert(Solution().isMatch("adceb", "*a*b") == true); }

void test_case_5() { assert(Solution().isMatch("acdcb", "a*c?b") == false); }

void test_case_6() {
    assert(Solution().isMatch("abefcdgiescdfimde", "ab*cd?i*de") == true);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();
    test_case_6();

    return 0;
}
