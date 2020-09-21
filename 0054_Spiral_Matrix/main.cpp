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

// T = O(n*m), S = O(1)
class Solution {
  public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return {};
        }
        int n = matrix.size(), m = matrix[0].size();
        vector<int> res;
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        while (true) {
            for (int i = left; i <= right; i++) {
                res.push_back(matrix[top][i]);
            }
            if (++top > bottom) {
                break;
            }

            for (int i = top; i <= bottom; i++) {
                res.push_back(matrix[i][right]);
            }
            if (--right < left) {
                break;
            }

            for (int i = right; i >= left; i--) {
                res.push_back(matrix[bottom][i]);
            }
            if (--bottom < top) {
                break;
            }

            for (int i = bottom; i >= top; i--) {
                res.push_back(matrix[i][left]);
            }
            if (++left > right) {
                break;
            }
        }
        return res;
    }
};
