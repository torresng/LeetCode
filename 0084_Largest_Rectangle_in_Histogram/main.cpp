#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int res = 0;
        int n = heights.size();
        vector<int> left(n), right(n);

        stack<int> stk;
        for (int i = 0; i < n; i++) {
            while (stk.size() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                left[i] = -1;
            } else {
                left[i] = stk.top();
            }
            stk.push(i);
        }

        while (!stk.empty()) {
            stk.pop();
        }

        for (int i = n - 1; i >= 0; i--) {
            while (stk.size() && heights[stk.top()] >= heights[i]) {
                stk.pop();
            }
            if (stk.empty()) {
                right[i] = n;
            } else {
                right[i] = stk.top();
            }
            stk.push(i);
        }

        for (int i = 0; i < n; i++) {
            res = max(res, heights[i] * (right[i] - left[i] - 1));
        }
        return res;
    }
};

/*
class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
        int res = 0;
        heights.push_back(0);
        int n = heights.size();
        stack<int> stk;
        stk.push(-1);
        for (int i = 0; i < n; i++) {
            while (stk.top() != -1 && heights[stk.top()] >= heights[i]) {
                int x = stk.top();
                stk.pop();
                res = max(res, (i - stk.top() - 1) * heights[x]);
            }
            stk.push(i);
        }
        return res;
    }
};
*/

void test_case_1() {
    vector<int> heights{2, 1, 5, 6, 2, 3};
    int ans = 10;

    int res = Solution().largestRectangleArea(heights);
    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
