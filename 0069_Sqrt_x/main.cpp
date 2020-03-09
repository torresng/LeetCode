#include <iostream>

using namespace std;

class Solution {
  public:
    int mySqrt(int x) {
        int l = 0, r = x;
        while (l < r) {
            int mid = ((long)l + r + 1) >> 1;
            if (mid <= (x / mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

void test_case_1() {
    int x = 4;
    int ans = 2;
    int res = Solution().mySqrt(x);
    assert(res == ans);
}

void test_case_2() {
    int x = 8;
    int ans = 2;
    int res = Solution().mySqrt(x);
    assert(res == ans);
}

int main(void) {
    test_case_1();
    test_case_2();

    return 0;
}
