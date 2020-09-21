// T = O(logx), S = O(1)
class Solution {
  public:
    int mySqrt(int x) {
        long l = 0, r = x;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (mid <= x / mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

// T = O(logx), S = O(1)
class Solution {
  public:
    int mySqrt(int x) {
        long n = x;
        while (n * n > x) {
            n = (n + x / n) >> 1;
        }
        return n;
    }
};
