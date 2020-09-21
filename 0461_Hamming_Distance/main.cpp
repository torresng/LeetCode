class Solution {
  public:
    int lowbit(int n) { return n & -n; }
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int count = 0;
        while (n != 0) {
            n -= lowbit(n);
            count++;
        }
        return count;
    }
};
