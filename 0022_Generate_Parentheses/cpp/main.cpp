// T = O(4^n / sqrt(n)), S = (n)
class Solution {
  public:
    void generate(vector<string> &res, string s, int left, int right) {
        if (left == 0 && right == 0) {
            res.push_back(s);
        }
        if (left != 0) {
            generate(res, s + '(', left - 1, right);
        }
        if (right > left) {
            generate(res, s + ')', left, right - 1);
        }
    }
    vector<string> generateParenthesis(int n) {
        if (n < 0) {
            return {};
        }
        vector<string> res;
        generate(res, "", n, n);
        return res;
    }
};

// DP T = O(4^n / n*sqrt(n)), S = O(4^n / n*sqrt(n))
class Solution {
  public:
    vector<string> generateParenthesis(int n) {
        if (n < 0) {
            return {};
        }
        vector<vector<string>> dp(n + 1);
        dp[0].push_back("");
        for (int i = 1; i < n + 1; i++) {
            for (int j = 0; j < i; j++) {
                for (auto left : dp[j]) {
                    for (auto right : dp[i - j - 1])
                        dp[i].push_back("(" + left + ")" + right);
                }
            }
        }
        return dp[n];
    }
};
