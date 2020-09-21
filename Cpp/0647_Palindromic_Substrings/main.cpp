class Solution {
  public:
    // T = O(n), S = O(1)
    int expend(string s, int i, int j) {
        int count = 0;
        while (i >= 0 && j < s.size() && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        if (s.empty()) {
            return 0;
        }
        int count = 0;
        for (int i = 0; i < s.size(); i++) {
            count += expend(s, i, i);
            count += expend(s, i, i + 1);
        }
        return count;
    }
};
