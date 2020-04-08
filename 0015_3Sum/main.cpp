// T = O(n ^ 2), S = O(1)
class Solution {
  public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        int n = nums.size();
        sort(nums.begin(), nums.end());

        for (int k = n - 1; k >= 2; k--) {
            if (nums[k] < 0) {
                break;
            }
            int target = -nums[k];
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] == target) {
                    res.push_back({nums[i], nums[j], nums[k]});
                    while (i < j && nums[i] == nums[i + 1]) {
                        i++;
                    }
                    while (i < j && nums[j] == nums[j - 1]) {
                        j--;
                    }
                    i++, j--;
                } else if (nums[i] + nums[j] < target) {
                    i++;
                } else {
                    j--;
                }
            }
            while (k >= 2 && nums[k] == nums[k - 1]) {
                k--;
            }
        }
        return res;
    }
};
