#include <iostream>
#include <string>

using namespace std;

// 回文串可以用馬拉車算法，O(n)時間內求解
class Solution {
  public:
    string longestPalindrome(string s) {
        string res;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            for (int j = i, k = i; j >= 0 && k < n && s[j] == s[k]; j--, k++) {
                if ((int)res.size() < k - j + 1) {
                    res = s.substr(j, k - j + 1);
                }
            }
            for (int j = i, k = i + 1; j >= 0 && k < n && s[j] == s[k];
                 j--, k++) {
                if ((int)res.size() < k - j + 1) {
                    res = s.substr(j, k - j + 1);
                }
            }
        }
        return res;
    }
};

void test_case_1() {
    string s = "babad";
    string ans = "bab";

    string res = Solution().longestPalindrome(s);
    assert(res == ans);
}

void test_case_2() {
    string s = "cbbd";
    string ans = "bb";

    string res = Solution().longestPalindrome(s);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
