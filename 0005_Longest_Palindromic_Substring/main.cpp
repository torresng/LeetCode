// T = O(n^2) S = O(n ^ 2)
class Solution {
  public:
    string longestPalindrome(string s) {
        int n = s.size(), maxLen = 0, start = 0;
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (i == j) {
                    dp[i][j] = true;
                } else if (i + 1 == j) {
                    dp[i][j] = s[i] == s[j];
                } else {
                    dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                }

                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    start = i;
                }
            }
        }
        return s.substr(start, maxLen);
    }
};

// T = O(n^2), S = O(1)
class Solution {
  public:
    int expend(string s, int i, int j) {
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            i--, j++;
        }
        // (j - 1) - (i + 1) - 1;
        return j - i - 1;
    }
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int maxLen = 0, start = 0;
        for (int i = 0; i < s.size(); i++) {
            int len1 = expend(s, i, i);
            int len2 = expend(s, i, i + 1);
            int len = max(len1, len2);
            if (len > maxLen) {
                maxLen = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substr(start, maxLen);
    }
};
