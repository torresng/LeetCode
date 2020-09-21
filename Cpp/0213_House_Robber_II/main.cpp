// T = O(n), S = O(1)
class Solution {
    int rob(vector<int> &nums, int start, int end) {
        int prev1 = 0, prev2 = 0;
        for (int i = start; i <= end; i++) {
            int cur = max(prev1, prev2 + nums[i]);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }

  public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(rob(nums, 0, n - 2), rob(nums, 1, n - 1));
    }
};
