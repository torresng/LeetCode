// T = O(n), S = O(1)
class Solution {
    bool isValidTwoDigit(char a, char b) {
        return (a == '1' && b <= '9') || (a == '2' && b <= '6');
    }

  public:
    int numDecodings(string s) {
        int n = s.size();
        int first = 1;                    // dp[0]
        int second = s[0] != '0' ? 1 : 0; // dp[1];
        for (int i = 2; i <= n; i++) {
            int third = 0;
            third += s[i - 1] != '0' ? second : 0;
            if (isValidTwoDigit(s[i - 2], s[i - 1])) {
                third += first;
            }
            first = second;
            second = third;
        }
        return second;
    }
};
