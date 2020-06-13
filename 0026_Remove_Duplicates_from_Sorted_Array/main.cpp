// T = O(n), S = O(1)
class Solution {
  public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        int p = 1;
        for (int q = 1; q < n; q++) {
            if (nums[q - 1] != nums[q]) {
                nums[p++] = nums[q];
            }
        }
        return p;
    }
};
