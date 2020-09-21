// T = O(n), S = O(n)
class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        int n = nums.size();
        vector<bool> v(n, false);
        for (auto x : nums) {
            v[x - 1] = true;
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (!v[i]) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};

// T = O(n), S = O(1)
class Solution {
  public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int idx = abs(nums[i]) - 1;
            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }
        }
        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }
};
