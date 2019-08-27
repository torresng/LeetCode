#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> p;

    int find(int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

    int findCircleNum(vector<vector<int>> &M) {
        int n = M.size();
        for (int i = 0; i < n; i++) {
            p.push_back(i);
        }
        int res = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (M[i][j] == 0) {
                    continue;
                }
                if (find(i) != find(j)) {
                    p[find(i)] = find(j);
                    res--;
                }
            }
        }
        return res;
    }
};

void test_case_1() {
    vector<vector<int>> M{{1, 1, 0}, {1, 1, 0}, {0, 0, 1}};
    int ans = 2;

    int res = Solution().findCircleNum(M);
    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
