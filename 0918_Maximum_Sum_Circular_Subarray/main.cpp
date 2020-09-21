#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int maxSubarraySumCircular(vector<int> &A) {
        int n = A.size();
        for (int i = 0; i < n; i++) {
            A.push_back(A[i]);
        }
        vector<int> sum(n * 2 + 1);
        for (int i = 1; i <= 2 * n; i++) {
            sum[i] = sum[i - 1] + A[i - 1];
        }
        int res = INT_MIN;
        deque<int> q;
        q.push_back(0);
        for (int i = 1; i <= n * 2; i++) {
            if (!q.empty() && i - n > q.front()) {
                q.pop_front();
            }
            if (!q.empty()) {
                res = max(res, sum[i] - sum[q.front()]);
            }
            while (!q.empty() && sum[q.back()] >= sum[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }

        return res;
    }
};

void test_case_1() {
    vector<int> A{1, -2, 3, -2};
    int ans = 3;

    int res = Solution().maxSubarraySumCircular(A);
    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
