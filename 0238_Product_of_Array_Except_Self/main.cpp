// T = O(n), S = O(1)
class Solution {
  public:
    vector<int> productExceptSelf(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        int n = nums.size();
        vector<int> v(n);
        int s = 1;
        for (int i = 0; i < n; i++) {
            v[i] = s;
            s *= nums[i];
        }
        s = 1;
        for (int i = n - 1; i >= 0; i--) {
            v[i] *= s;
            s *= nums[i];
        }
        return v;
    }
};
