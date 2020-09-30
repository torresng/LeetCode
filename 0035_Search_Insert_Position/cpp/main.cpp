class Solution {
  public:
    int searchInsert(vector<int> &nums, int target) {
        if (nums.empty()) {
            return 0;
        }
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (nums[mid] <= target) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        if (nums[l] < target) {
            return l + 1;
        }
        return l;
    }
};
