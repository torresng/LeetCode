// T = O(min(m, n)), S = O(1)
class Solution {
  public:
    int uniquePaths(int m, int n) {
        if (m < 1 || n < 1) {
            return 0;
        }
        int total = m + n - 2;
        int small = min(m - 1, n - 1);
        long res = 1;
        for (int i = 0; i < small; i++) {
            res = res * (total - i) / (i + 1);
        }
        return res;
    }
};
