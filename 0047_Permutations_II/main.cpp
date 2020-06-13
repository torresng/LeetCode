class Solution {
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int> nums, int i, int start, int state) {
        if (nums.size() == i) {
            res.push_back(path);
            return;
        }
        int n = nums.size();
        if (i == 0 || nums[i] != nums[i - 1]) {
            start = 0;
        }
        for (int k = start; k < n; k++) {
            if (!((state >> k) & 1)) {
                path[k] = nums[i];
                dfs(nums, i + 1, k + 1, (1 << k) + state);
            }
        }
    }

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        path.resize(n);
        dfs(nums, 0, 0, 0);
        return res;
    }
};

// T = O(n*n!), S = O(1)
class Solution {
    int nextPermutation(vector<int> &nums) {
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
            swap(nums[p], nums[i]);
        }
        reverse(nums.begin() + p + 1, nums.end());
        return p != -1;
    }

  public:
    vector<vector<int>> permuteUnique(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        res.push_back(nums);
        while (nextPermutation(nums)) {
            res.push_back(nums);
        }
        return res;
    }
};
