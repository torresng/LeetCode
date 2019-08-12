#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
    int n, m;
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

  public:
    bool exist(vector<vector<char>> &board, string word) {
        if (board.empty() || board[0].empty()) {
            return false;
        }
        n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (dfs(board, i, j, word, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

  private:
    bool dfs(vector<vector<char>> &board, int x, int y, string &word, int u) {
        if (board[x][y] != word[u]) {
            return false;
        }
        if ((unsigned)u == word.size() - 1) {
            return true;
        }

        board[x][y] = '.';
        for (int i = 0; i < 4; i++) {
            int a = x + dx[i], b = y + dy[i];
            if (a >= 0 && a < n && b >= 0 && b < m) {
                if (dfs(board, a, b, word, u + 1)) {
                    return true;
                }
            }
        }
        board[x][y] = word[u];

        return false;
    }
};

void test_case_1() {
    vector<vector<char>> board{
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    bool ans = true;

    bool res = Solution().exist(board, word);
    assert(res == ans);
}

void test_case_2() {
    vector<vector<char>> board{
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "SEE";
    bool ans = true;

    bool res = Solution().exist(board, word);
    assert(res == ans);
}

void test_case_3() {
    vector<vector<char>> board{
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    string word = "ABCB";
    bool ans = false;

    bool res = Solution().exist(board, word);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
