class Solution {
  public:
    // T = O(n), S = O(n)
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> hash;
        for (int i = 0; i < nums.size(); i++) {
            int n = target - nums[i];
            if (hash.count(n)) {
                return {hash[n], i};
            }
            hash[nums[i]] = i;
        }
        return {-1, -1};
    }
};
