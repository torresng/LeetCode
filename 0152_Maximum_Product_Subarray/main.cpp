// T = O(n), S = O(1)
class Solution {
  public:
    int maxProduct(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int curMax = nums[0], curMin = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int a = curMax * nums[i], b = curMin * nums[i], c = nums[i];
            curMax = max(max(a, b), c);
            curMin = min(min(a, b), c);
            res = max(curMax, res);
        }
        return res;
    }
};
