class Solution {
  public:
    int minCostClimbingStairs(vector<int> &cost) {
        if (cost.empty()) {
            return 0;
        }
        int n = cost.size();
        if (n == 1) {
            return cost[0];
        }
        int first = cost[0], second = cost[1];
        for (int i = 2; i < n; i++) {
            int cur = min(first, second) + cost[i];
            first = second;
            second = cur;
        }
        return min(first, second);
    }
};
