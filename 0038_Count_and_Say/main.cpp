#include <string>

using namespace std;

class Solution {
  public:
    string countAndSay(int n) {
        string s = "1";
        for (int i = 0; i < n - 1; i++) {
            string ns;
            for (unsigned j = 0; j < s.size(); j++) {
                unsigned k = j;
                while (k < s.size() && s[j] == s[k]) {
                    k++;
                }
                ns += to_string(k - j) + s[j];
                j = k - 1;
            }
            s = ns;
        }
        return s;
    }
};

void test_case_1() {
    int n = 1;
    string ans = "1";

    string res = Solution().countAndSay(n);
    assert(res == ans);
}

void test_case_2() {
    int n = 4;
    string ans = "1211";

    string res = Solution().countAndSay(n);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
