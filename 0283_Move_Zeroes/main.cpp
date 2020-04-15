// T = O(n), S = O(1)
class Solution {
  public:
    void moveZeroes(vector<int> &nums) {
        int slow = 0;
        for (int fast = 0; fast < nums.size(); fast++) {
            if (nums[fast] != 0) {
                swap(nums[fast], nums[slow]);
                slow++;
            }
        }
    }
};
