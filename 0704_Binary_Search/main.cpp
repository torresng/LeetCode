class Solution {
  public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return -1;
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
        if (nums[l] == target) {
            return l;
        }
        return -1;
    }
};
