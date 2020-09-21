// T = O(n), S = O(1)
class Solution {
  public:
    int romanToInt(string s) {
        int map[256];
        map['I'] = 1, map['V'] = 5, map['X'] = 10, map['L'] = 50;
        map['C'] = 100, map['D'] = 500, map['M'] = 1000;
        int n = s.size();
        int result = map[s[n - 1]];
        for (int i = n - 2; i >= 0; i--) {
            int cur = map[s[i]], pre = map[s[i + 1]];
            if (cur < pre) {
                result -= cur;
            } else {
                result += cur;
            }
        }
        return result;
    }
};
