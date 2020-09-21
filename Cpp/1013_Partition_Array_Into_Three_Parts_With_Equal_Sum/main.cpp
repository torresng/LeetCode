#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    bool canThreePartsEqualSum(vector<int> &A) {
        int sum = 0;
        for (auto num : A) {
            sum += num;
        }
        if (sum % 3 != 0) {
            return false;
        }
        int avg = sum / 3;
        int cnt = 0, cur = 0;
        for (auto num : A) {
            cur += num;
            if (cnt == 2) {
                return true;
            }
            if (cur == avg) {
                cnt++;
                cur = 0;
            }
        }
        return false;
    }
};

void test_case_1() {
    vector<int> A{3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
    bool ans = true;
    assert(Solution().canThreePartsEqualSum(A) == ans);
}

void test_case_2() {
    vector<int> A{1, -1, 1, -1};
    bool ans = false;
    assert(Solution().canThreePartsEqualSum(A) == ans);
}

void test_case_3() {
    vector<int> A{10, -10, 10, -10, 10, -10, 10, -10};
    bool ans = true;
    assert(Solution().canThreePartsEqualSum(A) == ans);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
