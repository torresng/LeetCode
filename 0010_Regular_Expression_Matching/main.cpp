#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        s = ' ' + s, p = ' ' + p;
        vector<vector<bool>> f(n + 1, vector<bool>(m + 1));
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= m; j++) {
                if (!i && !j) {
                    f[i][j] = true;
                } else {
                    if (j + 1 <= m && p[j + 1] == '*') {
                        continue;
                    }
                    if (p[j] != '*') {
                        if (p[j] == '.' || s[i] == p[j]) {
                            if (i > 0 && j > 0) {
                                f[i][j] = f[i - 1][j - 1];
                            }
                        }
                    } else {
                        if (j >= 2) {
                            f[i][j] = f[i][j - 2];
                        }
                        if (i > 0 && j > 0) {
                            if (p[j - 1] == '.' || s[i] == p[j - 1]) {
                                if (f[i - 1][j]) {
                                    f[i][j] = true;
                                }
                            }
                        }
                    }
                }
            }
        }
        return f[n][m];
    }
};

void test_case_1() {
    string s = "aa";
    string p = "a";
    bool ans = false;

    bool res = Solution().isMatch(s, p);
    assert(res == ans);
}

void test_case_2() {
    string s = "aa";
    string p = "a*";
    bool ans = true;

    bool res = Solution().isMatch(s, p);
    assert(res == ans);
}

void test_case_3() {
    string s = "ab";
    string p = ".*";
    bool ans = true;

    bool res = Solution().isMatch(s, p);
    assert(res == ans);
}

void test_case_4() {
    string s = "aab";
    string p = "c*a*b";
    bool ans = true;

    bool res = Solution().isMatch(s, p);
    assert(res == ans);
}

void test_case_5() {
    string s = "mississippi";
    string p = "mis*is*p*.";
    bool ans = false;

    bool res = Solution().isMatch(s, p);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();

    return 0;
}
