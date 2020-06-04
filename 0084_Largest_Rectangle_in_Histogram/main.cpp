class Solution {
  public:
    int largestRectangleArea(vector<int> &heights) {
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
};
