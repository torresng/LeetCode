class Solution {
    // T = O(k*log(k))
    string getKey(string str) {
        sort(str.begin(), str.end());
        return str;
    }

    // T = O(k)
    string getgetKeyByCount2(string str) {
        int hash[26] = {0};
        for (auto c : str) {
            hash[c - 'a']++;
        }
        string res;
        for (int i = 0; i < 26; i++) {
            if (hash[i] != 0) {
                res += (to_string(i) + 'a') + to_string(hash[i]);
            }
        }
        return res;
    }

  public:
    // T = O(n*k)
    // T = O(n*k*log(k)), S = O(n)
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        if (strs.empty()) {
            return {};
        }
        int n = strs.size();
        unordered_map<string, vector<string>> map;
        for (auto str : strs) {
            string key = getgetKeyByCount2(str);
            auto iter = map.find(key);
            if (iter != map.end()) {
                iter->second.push_back(str);
            } else {
                map[key] = vector<string>{str};
            }
        }
        vector<vector<string>> res;
        for (auto m : map) {
            res.push_back(m.second);
        }
        return res;
    }
};
