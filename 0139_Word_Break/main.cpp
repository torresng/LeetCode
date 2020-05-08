// T = O(n^2), S = O(n+m)
class Solution {
  public:
    bool wordBreak(string s, vector<string> &wordDict) {
        unordered_set set(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> d(n + 1, false);
        d[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= 0; j--) {
                if (d[j] && set.find(s.substr(j, i - j)) != set.end()) {
                    d[i] = true;
                    break;
                }
            }
        }
        return d[n];
    }
};
