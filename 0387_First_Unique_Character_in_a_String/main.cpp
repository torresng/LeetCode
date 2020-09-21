// T = O(n), S = O(m)
class Solution {
  public:
    int firstUniqChar(string s) {
        if (s.empty()) {
            return -1;
        }
        int n = s.size();
        vector<int> count(26, 0);
        vector<int> pos(26, -1);
        for (int i = 0; i < n; i++) {
            int idx = s[i] - 'a';
            count[idx]++;
            if (pos[idx] == -1) {
                pos[idx] = i;
            }
        }
        int res = INT_MAX;
        for (int i = 0; i < 26; i++) {
            if (count[i] == 1) {
                res = min(res, pos[i]);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
