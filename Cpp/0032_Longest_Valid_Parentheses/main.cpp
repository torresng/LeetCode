// T = O(n), S = O(n)
class Solution {
  public:
    int longestValidParentheses(string s) {
        if (s.empty()) {
            return 0;
        }
        int n = s.size();
        stack<int> st;
        int res = 0;
        st.push(-1);
        for (int i = 0; i < n; i++) {
            if (st.top() != -1 && s[st.top()] == '(' && s[i] == ')') {
                st.pop();
                res = max(res, i - st.top());
            } else {
                st.push(i);
            }
        }
        return res;
    }
};

// T = O(n), S = O(n)
class Solution {
  public:
    int longestValidParentheses(string s) {
        if (s.empty()) {
            return 0;
        }
        int n = s.size(), left = 0, res = 0;
        vector<int> d(n, 0);
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                left++;
            } else if (left > 0) {
                d[i] = d[i - 1] + 2;
                d[i] += i - d[i] >= 0 ? d[i - d[i]] : 0;
                res = max(res, d[i]);
                left--;
            }
        }
        return res;
    }
};
