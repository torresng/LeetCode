// T = O(n*amount), S = O(n*amount)
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        vector<vector<int>> d(n + 1, vector<int>(amount + 1));
        for (int i = 1; i <= amount; i++) {
            d[0][i] = INT_MAX;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                int useCurCoin = (coins[i - 1] <= j) ? d[i][j - coins[i - 1]]
                                                     : INT_MAX;
                if (useCurCoin < INT_MAX) {
                    useCurCoin += 1;
                }
                d[i][j] = min(d[i - 1][j], useCurCoin);
            }
        }
        return d[n][amount] != INT_MAX ? d[n][amount] : -1;
    }
};

// T = O(n*amount), S = O(n)
class Solution {
  public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        vector<int> d(amount + 1);
        for (int i = 1; i <= amount; i++) {
            d[i] = INT_MAX;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = coins[i - 1]; j <= amount; j++) {
                if (d[j - coins[i - 1]] != INT_MAX) {
                    d[j] = min(d[j], d[j - coins[i - 1]] + 1);
                }
            }
        }
        return d[amount] != INT_MAX ? d[amount] : -1;
    }
};
