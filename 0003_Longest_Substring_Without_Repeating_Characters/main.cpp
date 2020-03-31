// T = O(n), S = O(m)
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        unordered_map<char, int> map;
        int i = 0, j = 0;
        for (; i < s.size(); i++) {
            for (; j < s.size(); j++) {
                if (map[s[j]] == 1) {
                    break;
                }
                map[s[j]]++;
            }
            res = max(res, j - i);
            map[s[i]]--;
        }
        return res;
    }
};

// T = O(n), S = O(m)
class Solution {
  public:
    int lengthOfLongestSubstring(string s) {
        int res = 0;
        vector<int> index(255, -1);
        int i = 0, j = 0;
        for (; j < s.size(); j++) {
            i = max(index[s[j]] + 1, i);
            res = max(res, j - i + 1);
            index[s[j]] = j;
        }
        return res;
    }
};
