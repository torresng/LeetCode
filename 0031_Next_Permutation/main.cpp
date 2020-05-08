// T = O(n), S = O(1)
class Solution {
  public:
    void nextPermutation(vector<int> &nums) {
        if (nums.empty() || nums.size() < 2) {
            return;
        }
        int n = nums.size();
        int p = n - 2;
        while (p >= 0 && nums[p] >= nums[p + 1]) {
            p--;
        }
        if (p >= 0) {
            int i = n - 1;
            while (i > p && nums[i] <= nums[p]) {
                i--;
            }
            swap(nums[i], nums[p]);
        }
        reverse(nums.begin() + p + 1, nums.end());
    }
};
