// T = O(n), S = O(1)
class Solution {
  public:
    int fib(int N) {
        int first = 0, second = 1;
        while (N--) {
            int sum = first + second;
            first = second;
            second = sum;
        }
        return first;
    }
};
