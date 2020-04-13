// T = O(n), S = O(1)
class Solution {
  public:
    int rob(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int prev1 = 0, prev2 = 0;
        for (auto num : nums) {
            int cur = max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = cur;
        }
        return prev1;
    }
};
