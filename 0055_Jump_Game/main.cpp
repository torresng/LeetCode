// T = O(n), S = O(1)
class Solution {
  public:
    bool canJump(vector<int> &nums) {
        if (nums.empty()) {
            return false;
        }
        int n = nums.size(), maxv = 0;
        for (int i = 0; i < n; i++) {
            if (maxv >= n - 1) {
                return true;
            }
            if (i > maxv) {
                return false;
            }
            maxv = max(maxv, i + nums[i]);
        }
        return false;
    }
};
