#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    int trap(vector<int> &height) {
        int res = 0;
        stack<int> stk;
        for (int i = 0; i < (int)height.size(); i++) {
            int last = 0;
            while (!stk.empty() && height[stk.top()] <= height[i]) {
                int t = stk.top();
                stk.pop();
                res += (i - t - 1) * (height[t] - last);
                last = height[t];
            }
            if (!stk.empty()) {
                res += (i - stk.top() - 1) * (height[i] - last);
            }
            stk.push(i);
        }
        return res;
    }
};

void test_case_1() {
    vector<int> height{0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int ans = 6;

    int res = Solution().trap(height);

    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
