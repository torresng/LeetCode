// T = O(nlogn), S = O(1)
class Solution {
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end(),
             [](vector<int> &x, vector<int> &y) { return x[0] < y[0]; });
        vector<vector<int>> res;
        for (auto in : intervals) {
            int n = res.size();
            if (n == 0 || res[n - 1][1] < in[0]) {
                res.push_back(in);
            } else {
                res[n - 1][1] = max(res[n - 1][1], in[1]);
            }
        }
        return res;
    }
};
