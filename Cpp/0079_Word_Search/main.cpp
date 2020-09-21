// T = O(m*n*3^k), S = O(m*n)
class Solution {
    vector<vector<bool>> v;
    int n, m;
    bool dfs(vector<vector<char>> &board, int x, int y, string &word,
             int index) {
        if (word.size() == index) {
            return true;
        }
        if (x < 0 || x >= n || y < 0 || y >= m || v[x][y] == true ||
            board[x][y] != word[index]) {
            return false;
        }

        v[x][y] = true;
        int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (dfs(board, a, b, word, index + 1)) {
                return true;
            }
        }
        v[x][y] = false;
        return false;
    }

  public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        n = board.size(), m = board[0].size();
        v = vector<vector<bool>>(n, vector<bool>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};
