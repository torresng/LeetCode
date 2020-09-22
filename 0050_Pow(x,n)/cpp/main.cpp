class Solution {
  public:
    double myPow(double x, int n) {
        double res = 1;
        long N = abs((long)n);
        while (N) {
            if (N & 1) {
                res *= x;
            }
            x *= x;
            N >>= 1;
        }
        return n < 0 ? 1 / res : res;
    }
};
