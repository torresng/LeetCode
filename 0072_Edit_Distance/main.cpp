#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
  public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++) {
            f[i][0] = i;
        }
        for (int i = 0; i <= m; i++) {
            f[0][i] = i;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
                f[i][j] = min(f[i][j],
                              f[i - 1][j - 1] + (word1[i - 1] != word2[j - 1]));
            }
        }
        return f[n][m];
    }
};

void test_case_1() {
    string word1 = "horse";
    string word2 = "ros";
    int ans = 3;

    int res = Solution().minDistance(word1, word2);
    assert(res == ans);
}

void test_case_2() {
    string word1 = "intention";
    string word2 = "execution";
    int ans = 5;

    int res = Solution().minDistance(word1, word2);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();
    return 0;
}
