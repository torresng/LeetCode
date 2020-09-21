// T = O(n*m), S = O(n*m)
class Solution {
  public:
    int minDistance(string word1, string word2) {
        if (word1.empty() && word2.empty()) {
            return 0;
        }
        int n = word1.size(), m = word2.size();
        vector<vector<int>> d(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++) {
            d[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            d[0][j] = j;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    d[i][j] = d[i - 1][j - 1];
                } else {
                    d[i][j] =
                        min(d[i - 1][j - 1], min(d[i - 1][j], d[i][j - 1])) + 1;
                }
            }
        }
        return d[n][m];
    }
};

// T = O(n*m), S = (m)
class Solution {
  public:
    int minDistance(string word1, string word2) {
        if (word1.empty() && word2.empty()) {
            return 0;
        }
        int n = word1.size(), m = word2.size();
        vector<int> d(m + 1);
        for (int j = 0; j <= m; j++) {
            d[j] = j;
        }
        for (int i = 1; i <= n; i++) {
            int pre = d[0]; // d[i-1][j-1]
            d[0] = i;
            for (int j = 1; j <= m; j++) {
                int temp = d[j];
                if (word1[i - 1] == word2[j - 1]) {
                    d[j] = pre;
                } else {
                    d[j] = min(pre, min(d[j], d[j - 1])) + 1;
                }
                pre = temp;
            }
        }
        return d[m];
    }
};
