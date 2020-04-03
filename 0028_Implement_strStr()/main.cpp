// KMP
class Solution {
  public:
    vector<int> next;
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int n = haystack.size(), m = needle.size();
        string s = " " + haystack, p = " " + needle;
        next.resize(m + 1);

        for (int i = 2, j = 0; i <= m; i++) {
            while (j != 0 && p[i] != p[j + 1]) {
                j = next[j];
            }
            if (p[i] == p[j + 1]) {
                j++;
            }
            next[i] = j;
        }

        for (int i = 1, j = 0; i <= n; i++) {
            while (j != 0 && s[i] != p[j + 1]) {
                j = next[j];
            }
            if (s[i] == p[j + 1]) {
                j++;
            }
            if (j == m) {
                return i - m;
            }
        }
        return -1;
    }
};
