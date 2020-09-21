// T = O(n), S = O(1)
class Solution {
  public:
    int nthUglyNumber(int n) {
        vector<int> v(1, 1);
        int p1 = 0, p2 = 0, p3 = 0;
        for (int i = 1; i < n; i++) {
            int minv = min(v[p1] * 2, min(v[p2] * 3, v[p3] * 5));
            v.push_back(minv);
            if (minv == v[p1] * 2) {
                p1++;
            }
            if (minv == v[p2] * 3) {
                p2++;
            }
            if (minv == v[p3] * 5) {
                p3++;
            }
        }
        return v[n - 1];
    }
};
