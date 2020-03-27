// Recursive  T = O(n), S = O(n)
class Solution {
  public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, (unsigned)(a & b) << 1);
    }
};

// Iteration  T = O(n), S = O(n)
class Solution {
  public:
    int getSum(int a, int b) {
        while (b != 0) {
            long sum = a ^ b;
            long carry = (unsigned int)(a & b) << 1;
            a = sum;
            b = carry;
        }
        return a;
    }
};
