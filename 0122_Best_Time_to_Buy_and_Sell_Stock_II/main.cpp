// T = O(n), S = O(1)
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        if (prices.empty()) {
            return 0;
        }
        int n = prices.size();
        int res = 0;
        for (int i = 1; i < n; i++) {
            if (prices[i - 1] < prices[i]) {
                res += (prices[i] - prices[i - 1]);
            }
        }
        return res;
    }
};
