// T = O(n*amount), S = O(n*amount)
class Solution {
  public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        vector<vector<int>> d(n + 1, vector<int>(amount + 1));
        for (int i = 0; i <= n; i++) {
            d[i][0] = 1;
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                int useCurCoin = coins[i - 1] <= j ? d[i][j - coins[i - 1]] : 0;
                d[i][j] = d[i - 1][j] + useCurCoin;
            }
        }
        return d[n][amount];
    }
};

// T = O(n*amount), S = O(amount)
class Solution {
  public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        vector<int> d(amount + 1);
        d[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                int useCurCoin = coins[i - 1] <= j ? d[j - coins[i - 1]] : 0;
                d[j] = d[j] + useCurCoin;
            }
        }
        return d[amount];
    }
};
