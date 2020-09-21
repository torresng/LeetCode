#include <iostream>
#include <vector>

using namespace std;

class Solution {
    // y = x, y = -x
    // => y - x = 0, y + x = 0
    int _n, res = 0;
    vector<bool> col, d, ud;

  public:
    int totalNQueens(int n) {
        _n = n;
        col = vector<bool>(n);
        d = ud = vector<bool>(2 * n);

        dfs(0);
        return res;
    }

  private:
    void dfs(int u) {
        if (u == _n) {
            res++;
            return;
        }
        for (int i = 0; i < _n; i++) {
            if (!col[i] && !d[u + i] && !ud[u - i + _n]) {
                col[i] = d[u + i] = ud[u - i + _n] = true;
                dfs(u + 1);
                col[i] = d[u + i] = ud[u - i + _n] = false;
            }
        }
    }
};

void test_case_1() {
    int n = 4;
    int ans = 2;

    int res = Solution().totalNQueens(n);
    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
