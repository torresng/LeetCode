// T = O(n), S = O(1)
class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        if (n < 2) {
            return 0;
        }
        int res = 0, buy = prices[0];
        for (int i = 1; i < n; i++) {
            if (buy > prices[i]) {
                buy = prices[i];
            } else {
                res = max(res, prices[i] - buy);
            }
        }
        return res;
    }
};
