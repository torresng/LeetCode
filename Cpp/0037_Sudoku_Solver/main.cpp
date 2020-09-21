#include <iostream>
#include <vector>

using namespace std;

class Solution {
    bool row[9][9] = {false}, col[9][9] = {false}, cell[3][3][9] = {false};

  public:
    void solveSudoku(vector<vector<char>> &board) {
        // init
        for (unsigned i = 0; i < 9; i++) {
            for (unsigned j = 0; j < 9; j++) {
                char c = board[i][j];
                if (c != '.') {
                    int t = c - '1';
                    row[i][t] = col[j][t] = cell[i / 3][j / 3][t] = true;
                }
            }
        }
        dfs(board, 0, 0);
    }

  private:
    bool dfs(vector<vector<char>> &board, int x, int y) {
        if (y == 9) {
            x++, y = 0;
        }
        if (x == 9) {
            return true;
        }
        if (board[x][y] != '.') {
            return dfs(board, x, y + 1);
        }
        for (int i = 0; i < 9; i++) {
            if (!row[x][i] && !col[y][i] && !cell[x / 3][y / 3][i]) {
                board[x][y] = '1' + i;
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = true;
                if (dfs(board, x, y + 1)) {
                    return true;
                }
                row[x][i] = col[y][i] = cell[x / 3][y / 3][i] = false;
                board[x][y] = '.';
            }
        }
        return false;
    }
};

bool compare(vector<vector<char>> v1, vector<vector<char>> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }

    for (unsigned i = 0; i < v1.size(); i++) {
        if (v1[i].size() != v2.size()) {
            return false;
        }
        for (unsigned j = 0; j < v1[i].size(); j++) {
            if (v1[i][j] != v2[i][j]) {
                return false;
            }
        }
    }
    return true;
}

void test_case_1() {
    vector<vector<char>> board{
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };

    vector<vector<char>> ans{
        {'5', '3', '4', '6', '7', '8', '9', '1', '2'},
        {'6', '7', '2', '1', '9', '5', '3', '4', '8'},
        {'1', '9', '8', '3', '4', '2', '5', '6', '7'},
        {'8', '5', '9', '7', '6', '1', '4', '2', '3'},
        {'4', '2', '6', '8', '5', '3', '7', '9', '1'},
        {'7', '1', '3', '9', '2', '4', '8', '5', '6'},
        {'9', '6', '1', '5', '3', '7', '2', '8', '4'},
        {'2', '8', '7', '4', '1', '9', '6', '3', '5'},
        {'3', '4', '5', '2', '8', '6', '1', '7', '9'},
    };

    Solution().solveSudoku(board);
    vector<vector<char>> res = board;

    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
