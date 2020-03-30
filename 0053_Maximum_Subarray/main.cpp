class Solution {
  public:
    int maxSubArray(vector<int> &nums) {
        int res = INT_MIN, cur = 0;
        for (auto num : nums) {
            cur = cur <= 0 ? num : cur + num;
            res = max(res, cur);
        }
        return res;
    }
};
