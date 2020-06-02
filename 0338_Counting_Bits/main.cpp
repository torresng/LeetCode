// T = O(n), S = O(1)
class Solution {
  public:
    vector<int> countBits(int num) {
        vector<int> d(num + 1);
        d[0] = 0;
        for (int i = 1; i <= num; i++) {
            d[i] = d[(i - 1) & i] + 1;
        }
        return d;
    }
};
