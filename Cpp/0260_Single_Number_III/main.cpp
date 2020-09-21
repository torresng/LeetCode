// T = O(n), S = O(1)
class Solution {
  public:
    vector<int> singleNumber(vector<int> &nums) {
        if (nums.empty()) {
            return {};
        }
        int s = 0;
        for (auto x : nums) {
            s ^= x;
        }
        int mask = s & (-s);
        int first = 0;
        cout << mask << endl;
        for (auto x : nums) {
            if ((x & mask) != 0) {
                first ^= x;
            }
        }
        return {first, s ^ first};
    }
};
