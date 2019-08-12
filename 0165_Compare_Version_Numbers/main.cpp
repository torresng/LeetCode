#include <iostream>
#include <string>

using namespace std;

class Solution {
  public:
    int compareVersion(string version1, string version2) {
        unsigned i = 0, j = 0;
        while (i < version1.size() || j < version2.size()) {
            unsigned x = i, y = j;
            while (x < version1.size() && version1[x] != '.') {
                x++;
            }
            while (y < version2.size() && version2[y] != '.') {
                y++;
            }
            int a = i == x ? 0 : atoi(version1.substr(i, x - i).c_str());
            int b = j == y ? 0 : atoi(version2.substr(j, y - j).c_str());
            if (a < b) {
                return -1;
            }
            if (a > b) {
                return 1;
            }
            i = x + 1, j = y + 1;
        }
        return 0;
    }
};

void test_case_1() {
    string version1 = "0.1";
    string version2 = "1.1";
    int ans = -1;

    int res = Solution().compareVersion(version1, version2);
    assert(ans == res);
}

void test_case_2() {
    string version1 = "1.0.1";
    string version2 = "1";
    int ans = 1;

    int res = Solution().compareVersion(version1, version2);
    assert(ans == res);
}

void test_case_3() {
    string version1 = "7.5.2.4";
    string version2 = "7.5.3";
    int ans = -1;

    int res = Solution().compareVersion(version1, version2);
    assert(ans == res);
}

void test_case_4() {
    string version1 = "1.01";
    string version2 = "1.001";
    int ans = 0;

    int res = Solution().compareVersion(version1, version2);
    assert(ans == res);
}

void test_case_5() {
    string version1 = "1.0";
    string version2 = "1.0.0";
    int ans = 0;

    int res = Solution().compareVersion(version1, version2);
    assert(ans == res);
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();

    return 0;
}
