#include <deque>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        vector<int> res;
        deque<int> q;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (!q.empty() && i - k + 1 > q.front()) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[q.front()]);
            }
        }
        return res;
    }
};

void test_case_1() {
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = {3, 3, 5, 5, 6, 7};

    vector<int> res = Solution().maxSlidingWindow(nums, k);

    assert(res == ans);
}

int main(void) {
    test_case_1();

    return 0;
}
