// T = O(n*m), S = O(n*m)
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<bool>> v(n, vector<bool>(m));
        vector<int> res;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1}, d = 1;
        int x = 0, y = 0;
        for (int i = 0; i < n * m; i++) {
            res.push_back(matrix[x][y]);
            v[x][y] = true;
            int a = x + dx[d], b = y + dy[d];
            if (a < 0 || a >= n || b < 0 || b >= m || v[a][b] == true) {
                d = (d + 1) % 4;
                a = x + dx[d];
                b = y + dy[d];
            }
            x = a, y = b;
        }
        return res;
    }
};
