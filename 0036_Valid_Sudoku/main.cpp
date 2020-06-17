// T = O(1), S = O(1)
class Solution {
  public:
    bool isValidSudoku(vector<vector<char>> &board) {
        bool rowSeen[9][9] = {false};
        bool colSeen[9][9] = {false};
        bool boxSeen[9][9] = {false};
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                int x = board[i][j] - '1';
                int k = (i / 3) * 3 + j / 3;
                if (rowSeen[i][x] || colSeen[j][x] || boxSeen[k][x]) {
                    return false;
                }
                rowSeen[i][x] = colSeen[j][x] = boxSeen[k][x] = true;
            }
        }
        return true;
    }
};
