// T = O(log(n)), S = O(1)
class Solution {
  public:
    int findMin(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        }
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l < r) {
            if (nums[l] < nums[r]) {
                return nums[l];
            }
            int mid = (l + r) >> 1;
            if (nums[0] > nums[mid]) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l];
    }
};
