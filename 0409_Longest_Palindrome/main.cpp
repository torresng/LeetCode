// T = O(n), S = O(m)
class Solution {
  public:
    int longestPalindrome(string s) {
        int n = s.size();
        vector<int> d(256);
        for (auto c : s) {
            d[c]++;
        }
        int oddNum = 0;
        for (auto count : d) {
            if (count % 2 == 1) {
                oddNum++;
            }
        }
        int unUsed = max(0, oddNum - 1);
        return n - unUsed;
    }
};
