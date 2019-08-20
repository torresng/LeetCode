#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int longestValidParentheses(string s) {
        int res = work(s);
        reverse(s.begin(), s.end());
        for (auto &c : s) {
            c ^= 1;
        }
        return max(res, work(s));
    }

  private:
    int work(string &s) {
        int res = 0;
        int n = s.size();
        for (int i = 0, start = 0, cnt = 0; i < n; i++) {
            if (s[i] == '(') {
                cnt++;
            } else {
                cnt--;
                if (cnt < 0) {
                    start = i + 1;
                    cnt = 0;
                } else if (!cnt) {
                    res = max(res, i - start + 1);
                }
            }
        }
        return res;
    }
};

void test_case_1() {
    string s = "(()";
    int ans = 2;

    int res = Solution().longestValidParentheses(s);
    assert(res == ans);
}

void test_case_2() {
    string s = ")()())";
    int ans = 4;

    int res = Solution().longestValidParentheses(s);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
