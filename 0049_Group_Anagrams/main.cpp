#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> hash;

        for (auto str : strs) {
            string tmp = str;
            sort(tmp.begin(), tmp.end());
            hash[tmp].push_back(str);
        }

        for (auto item : hash) {
            res.push_back(item.second);
        }

        return res;
    }
};

bool compare(vector<vector<string>> v1, vector<vector<string>> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    sort(
        v1.begin(), v1.end(),
        [](auto &vv1, auto &vv2) -> auto { return vv1.size() < vv2.size(); });
    sort(
        v2.begin(), v2.end(),
        [](auto &vv1, auto &vv2) -> auto { return vv1.size() < vv2.size(); });

    for (unsigned i = 0; i < v1.size(); i++) {
        if (v1[i].size() != v2[i].size()) {
            return false;
        }
        sort(v1[i].begin(), v1[i].end());
        sort(v2[i].begin(), v2[i].end());

        for (unsigned j = 0; j < v1[i].size(); j++) {
            if (v1[i][j] != v2[i][j]) {
                return false;
            }
        }
    }

    return true;
}

void test_case_1() {
    vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> ans{{"ate", "eat", "tea"}, {"nat", "tan"}, {"bat"}};

    vector<vector<string>> res = Solution().groupAnagrams(strs);

    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
