// T = O(n), S = O(1)
class Solution {
  public:
    int climbStairs(int n) {
        int first = 1, second = 1;
        for (int i = 1; i < n; i++) {
            int third = first + second;
            first = second;
            second = third;
        }
        return second;
    }
};
