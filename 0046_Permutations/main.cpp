class Solution {
  public:
    // T = O(n * n!), S = O(n);
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int> &nums) {
        dfs(nums, 0);
        return res;
    }
    void dfs(vector<int> &nums, int start) {
        if (start == nums.size()) {
            res.push_back(nums);
            return;
        }
        for (int i = start; i < nums.size(); i++) {
            swap(nums[i], nums[start]);
            dfs(nums, start + 1);
            swap(nums[i], nums[start]);
        }
    }
};
