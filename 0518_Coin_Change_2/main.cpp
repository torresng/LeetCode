#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        vector<int> f(amount + 1);
        f[0] = 1;
        for (auto c : coins) {
            for (int j = c; j <= amount; j++) {
                f[j] += f[j - c];
            }
        }
        return f[amount];
    }
};

void test_case_1() {
    int amount = 5;
    vector<int> coins{1, 2, 5};
    int ans = 4;

    int res = Solution().change(amount, coins);
    assert(res == ans);
}

void test_case_2() {
    int amount = 3;
    vector<int> coins{2};
    int ans = 4;

    int res = Solution().change(amount, coins);
    assert(res == ans);
}

void test_case_3() {
    int amount = 10;
    vector<int> coins{10};
    int ans = 0;

    int res = Solution().change(amount, coins);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
