// T = O(nlog(n)), S = O(1)
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int res = 0, p = 0;
        while (p < n) {
            int len = 1;
            while (p < n - 1) {
                if (nums[p + 1] - nums[p] > 1) {
                    break;
                }
                if (nums[p + 1] - nums[p] == 1) {
                    len++;
                }
                p++;
            }
            res = max(res, len);
            p++;
        }

        return res;
    }
};

// T = O(n), S = O(n)
class Solution {
  public:
    int longestConsecutive(vector<int> &nums) {
        unordered_set<int> set;
        for (auto num : nums) {
            set.insert(num);
        }
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n && !set.empty(); i++) {
            set.erase(nums[i]);
            int low = nums[i], high = nums[i];
            while (set.find(--low) != set.end()) {
                set.erase(low);
            }
            while (set.find(++high) != set.end()) {
                set.erase(high);
            }
            res = max(res, high - low - 1);
        }
        return res;
    }
};
