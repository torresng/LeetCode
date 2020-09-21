// T = O(n*m), S = O(m)
class Solution {
    int largestRectangleInHistogram(vector<int> heights) {
        if (heights.empty()) {
            return 0;
        }
        int n = heights.size(), res = 0;
        stack<int> st;
        for (int r = 0; r <= n; r++) {
            int h = r == n ? 0 : heights[r];
            while (!st.empty() && h < heights[st.top()]) {
                int k = st.top();
                st.pop();
                int l = st.empty() ? -1 : st.top();
                res = max(res, heights[k] * (r - l - 1));
            }
            st.push(r);
        }
        return res;
    }

  public:
    int maximalRectangle(vector<vector<char>> &matrix) {
        if (matrix.empty() || matrix[0].empty()) {
            return 0;
        }
        int n = matrix.size(), m = matrix[0].size();
        int res = 0;
        vector<int> heights(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                heights[j] = matrix[i][j] == '0' ? 0 : heights[j] + 1;
            }
            res = max(res, largestRectangleInHistogram(heights));
        }
        return res;
    }
};
