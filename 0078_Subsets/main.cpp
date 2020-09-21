// T = O(2^n), S = O(n)
class Solution {
    vector<vector<int>> res;
    vector<int> v;
    void dfs(vector<int> &nums, int start) {
        res.push_back(v);
        for (int i = start; i < nums.size(); i++) {
            v.push_back(nums[i]);
            dfs(nums, i + 1);
            v.pop_back();
        }
    }

  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        int n = nums.size();
        dfs(nums, 0);
        return res;
    }
};

// T = O(n*2^n), S = O(1)
class Solution {
  public:
    vector<vector<int>> subsets(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        int n = nums.size();
        int N = pow(2, n);
        vector<vector<int>> res;
        for (int i = 0; i < N; i++) {
            vector<int> v;
            for (int j = 0; j < n; j++) {
                if ((i >> j) & 1) {
                    v.push_back(nums[j]);
                }
            }
            res.push_back(v);
        }
        return res;
    }
};
