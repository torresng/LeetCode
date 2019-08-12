#include <iostream>
#include <string>

using namespace std;

class Solution {
    string small[20] = {"Zero",    "One",       "Two",      "Three",
                        "Four",    "Five",      "Six",      "Seven",
                        "Eight",   "Nine",      "Ten",      "Eleven",
                        "Twelve",  "Thirteen",  "Fourteen", "Fifteen",
                        "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    string decade[10] = {"",      "",      "Twenty",  "Thirty", "Forty",
                         "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    string big[4] = {"Billion", "Million", "Thousand", ""};

  public:
    string numberToWords(int num) {
        if (num == 0) {
            return small[0];
        }

        string res;
        for (int i = 1000000000, j = 0; i > 0; i /= 1000, j++) {
            if (num >= i) {
                res += get_part(num / i) + big[j] + ' ';
                num %= i;
            }
        }
        while (res.back() == ' ') {
            res.pop_back();
        }
        return res;
    }

  private:
    string get_part(int num) {
        string res;
        if (num >= 100) {
            res += small[num / 100] + " Hundred ";
            num %= 100;
        }
        if (num == 0) {
            return res;
        }
        if (num >= 20) {
            res += decade[num / 10] + ' ';
            num %= 10;
        }
        if (num == 0) {
            return res;
        }
        res += small[num] + ' ';
        return res;
    }
};

void test_case_1() {
    int num = 123;
    string ans = "One Hundred Twenty Three";

    string res = Solution().numberToWords(num);
    assert(ans == res);
}

void test_case_2() {
    int num = 12345;
    string ans = "Twelve Thousand Three Hundred Forty Five";

    string res = Solution().numberToWords(num);
    assert(ans == res);
}

void test_case_3() {
    int num = 1234567;
    string ans =
        "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven";

    string res = Solution().numberToWords(num);
    assert(ans == res);
}

void test_case_4() {
    int num = 1234567891;
    string ans = "One Billion Two Hundred Thirty Four Million Five Hundred "
                 "Sixty Seven Thousand Eight Hundred Ninety One";

    string res = Solution().numberToWords(num);
    assert(ans == res);
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();

    return 0;
}
