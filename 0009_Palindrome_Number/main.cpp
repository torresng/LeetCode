// T = O(n), S = O(1)
class Solution {
  public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {
                return false;
            }
            i++, j--;
        }
        return true;
    }
};

// Solve it without converting the integer to a string
// T = O(n), S = O(1)
class Solution {
  public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int temp = x;
        long y = 0;
        while (temp) {
            int k = temp % 10;
            y = y * 10 + k;
            temp /= 10;
        }
        return x == y;
    }
};
