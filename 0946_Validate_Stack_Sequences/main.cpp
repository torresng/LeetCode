// T = O(n), S = O(n)
class Solution {
  public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        if (pushed.empty() && popped.empty()) {
            return true;
        }
        stack<int> st;
        int n = pushed.size();
        for (int i = 0, j = 0; i < n; i++) {
            st.push(pushed[i]);
            while (!st.empty() && st.top() == popped[j]) {
                j++;
                st.pop();
            }
        }
        return st.empty();
    }
};

// T = O(n), S = O(n)
class Solution {
  public:
    bool validateStackSequences(vector<int> &pushed, vector<int> &popped) {
        if (pushed.empty() && popped.empty()) {
            return true;
        }
        int n = pushed.size();
        vector<int> st(n);
        int top = -1;
        for (int i = 0, j = 0; i < n; i++) {
            st[++top] = pushed[i];
            while (top != -1 && st[top] == popped[j]) {
                j++;
                top--;
            }
        }
        return top == -1;
    }
};
