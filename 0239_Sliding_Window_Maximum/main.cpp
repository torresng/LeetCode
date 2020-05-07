// T = O(n), S = O(k);
class Solution {
  public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        if (nums.empty()) {
            return {};
        }
        vector<int> res;
        int n = nums.size();
        deque<int> q;
        for (int i = 0; i < n; i++) {
            while (!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            while (!q.empty() && nums[q.back()] < nums[i]) {
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
