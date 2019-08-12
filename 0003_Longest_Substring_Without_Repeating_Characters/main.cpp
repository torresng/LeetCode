#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> hash;
        for (int i = 0, j = 0; i < s.size(); i++) {
            hash[s[i]]++;
            while (hash[s[i]] > 1) {
                hash[s[j++]]--;
            }
            res = max(res, i - j + 1);
        }
        return res;
    }
};

void test_case_1() {
    string s = "abcabcbb";
    int ans = 3;

    int res = Solution().lengthOfLongestSubstring(s);
    assert(res == ans);
}

void test_case_2() {
    string s = "bbbbb";
    int ans = 1;

    int res = Solution().lengthOfLongestSubstring(s);
    assert(res == ans);
}

void test_case_3() {
    string s = "pwwkew";
    int ans = 3;

    int res = Solution().lengthOfLongestSubstring(s);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
