#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    string minWindow(string s, string t) {
        unordered_map<char, int> hash;
        for (auto c : t) {
            hash[c]++;
        }
        int cnt = hash.size();

        int n = s.size();
        string res;
        for (int i = 0, j = 0, c = 0; i < n; i++) {
            if (hash[s[i]] == 1) {
                c++;
            }
            hash[s[i]]--;
            while (hash[s[j]] < 0) {
                hash[s[j++]]++;
            }
            if (c == cnt) {
                if (res.empty() || (int)res.size() > i - j + 1) {
                    res = s.substr(j, i - j + 1);
                }
            }
        }
        return res;
    }
};

void test_case_1() {
    string s = "ADOBECODEBANC", t = "ABC";
    string ans = "BANC";

    string res = Solution().minWindow(s, t);
    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
