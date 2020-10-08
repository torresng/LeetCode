// T = O(logn), S = O(1)
class Solution {
  public:
    int singleNonDuplicate(vector<int> &nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (mid - 1 >= 0 && nums[mid] == nums[mid - 1]) {
                mid--;
            } else if (mid + 1 < n && nums[mid] == nums[mid + 1]) {

            } else {
                return nums[mid];
            }
            if ((mid - l) % 2 == 1) {
                r = mid - 1;
            } else {
                l = mid + 2;
            }
        }
        return -1;
    }
};
