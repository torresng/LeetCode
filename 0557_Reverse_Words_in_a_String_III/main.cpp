// T = O(n), S = O(n)
class Solution {
  public:
    string reverseWords(string s) {
        int n = s.size();
        int start = 0, end = 0;
        while (start < n) {
            while (end < n && s[end] != ' ') {
                end++;
            }
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
            end = start;
        }
        return s;
    }
};
