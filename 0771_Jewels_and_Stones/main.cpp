// T = O(n + m), S = O(k)
class Solution {
public:
    int numJewelsInStones(string J, string S) {
        if(J.empty() || S.empty()) { return 0; }
        bool hash[256] = {false};
        for(char c : J) {
            hash[c] = true;
        }
        int res = 0;
        for(char c : S) {
            if(hash[c]) {
                res++;
            }
        }
        return res;
    }
};
