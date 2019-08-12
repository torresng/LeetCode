#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    string reverseWords(string s) {
        int k = 0;
        for (unsigned i = 0; i < s.size(); i++) {
            while (i < s.size() && s[i] == ' ') {
                i++;
            }
            if (i == s.size()) {
                break;
            }
            unsigned j = i;
            while (j < s.size() && s[j] != ' ') {
                j++;
            }
            reverse(s.begin() + i, s.begin() + j);
            if (k) {
                s[k++] = ' ';
            }
            while (i != j) {
                s[k++] = s[i++];
            }
        }
        s.erase(s.begin() + k, s.end());
        reverse(s.begin(), s.end());
        return s;
    }
};

void test_case_1() {
    string s = "the sky is blue";
    string ans = "blue is sky the";

    string res = Solution().reverseWords(s);
    assert(res == ans);
}

void test_case_2() {
    string s = "  hello world!  ";
    string ans = "world! hello";

    string res = Solution().reverseWords(s);
    assert(res == ans);
}

void test_case_3() {
    string s = "a good   example";
    string ans = "example good a";

    string res = Solution().reverseWords(s);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
