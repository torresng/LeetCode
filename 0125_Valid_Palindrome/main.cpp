class Solution {
    bool isAlphanumeric(char c) {
        return ((c >= 'A') && (c <= 'Z')) || ((c >= 'a') && (c <= 'z')) ||
               ((c >= '0') && (c <= '9'));
    }
    bool isEqualIgnoreCase(char a, char b) {
        if (a >= 'A' && a <= 'Z') {
            a += 32;
        }
        if (b >= 'A' && b <= 'Z') {
            b += 32;
        }
        return a == b;
    }

  public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        for (; i < j; i++, j--) {
            while (i < j && !isAlphanumeric(s[i])) {
                i++;
            }
            while (i < j && !isAlphanumeric(s[j])) {
                j--;
            }
            if (i < j && !isEqualIgnoreCase(s[i], s[j])) {
                return false;
            }
        }
        return true;
    }
};
