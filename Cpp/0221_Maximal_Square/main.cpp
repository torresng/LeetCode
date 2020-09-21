// T = O(n*m), S = O(n*m)
class Solution {
    int _min(int a, int b, int c) { return min(a, min(b, c)); }

  public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int n = matrix.size(), m = matrix[0].size();
        int res = 0;
        vector<vector<int>> d(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    d[i][j] = matrix[i][j] == '1' ? 1 : 0;
                } else {
                    d[i][j] =
                        _min(d[i - 1][j], d[i][j - 1], d[i - 1][j - 1]) + 1;
                }
                res = max(res, d[i][j]);
            }
        }
        return res * res;
    }
};

// T = O(n*m), S = O(m)
class Solution {
    int _min(int a, int b, int c) { return min(a, min(b, c)); }

  public:
    int maximalSquare(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int n = matrix.size(), m = matrix[0].size();
        int res = 0, pre = 0;
        ;
        vector<int> d(m);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int tmp = d[j];
                if (i == 0 || j == 0 || matrix[i][j] == '0') {
                    d[j] = matrix[i][j] == '1' ? 1 : 0;
                } else {
                    d[j] = _min(pre, d[j], d[j - 1]) + 1;
                }
                res = max(res, d[j]);
                pre = tmp;
            }
        }
        return res * res;
    }
};
