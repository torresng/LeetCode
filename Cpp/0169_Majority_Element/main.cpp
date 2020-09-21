// T = O(n), S = O(1)
class Solution {
  public:
    int majorityElement(vector<int> &nums) {
        int cur = 0, count = 0;
        for (auto num : nums) {
            if (count == 0) {
                cur = num;
                count = 1;
            } else if (num == cur) {
                count++;
            } else {
                count--;
            }
        }
        return cur;
    }
};
