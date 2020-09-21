class Solution {
  public:
    // T = O(n), S = O(1)
    int missingNumber(vector<int> &nums) {
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            res = res ^ i ^ nums[i];
        }
        return res;
    }
};
