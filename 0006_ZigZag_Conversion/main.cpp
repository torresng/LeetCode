#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        string res;
        int n = s.size();
        for (int i = 0; i < numRows; i++) {
            if (i == 0 || i == numRows - 1) {
                for (int j = i; j < n; j += 2 * (numRows - 1)) {
                    res += s[j];
                }
            } else {
                for (int j = i, k = 2 * (numRows - 1) - i; j < n || k < n;
                     j += 2 * (numRows - 1), k += 2 * (numRows - 1)) {
                    if (j < n) {
                        res += s[j];
                    }
                    if (k < n) {
                        res += s[k];
                    }
                }
            }
        }
        return res;
    }
};

void test_case_1() {
    string s = "PAYPALISHIRING";
    int numRows = 3;
    string ans = "PAHNAPLSIIGYIR";

    string res = Solution().convert(s, numRows);
    assert(res == ans);
}

void test_case_2() {
    string s = "PAYPALISHIRING";
    int numRows = 4;
    string ans = "PINALSIGYAHRPI";

    string res = Solution().convert(s, numRows);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
