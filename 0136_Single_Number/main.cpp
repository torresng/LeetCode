class Solution {
  public:
    // T = O(n), S = O(1)
    int singleNumber(vector<int> &nums) {
        int res = 0;
        for (auto n : nums) {
            res ^= n;
        }
        return res;
    }
};
