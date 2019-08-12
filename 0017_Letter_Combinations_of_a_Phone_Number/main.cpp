#include <iostream>
#include <vector>

using namespace std;

class Solution {
    string chars[8] = {"abc", "def",  "ghi", "jkl",
                       "nmo", "pqrs", "tuv", "wxyz"};

  public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return vector<string>();
        }
        vector<string> state(1, "");

        for (auto u : digits) {
            vector<string> now;
            for (auto c : chars[u - '2']) {
                for (auto s : state) {
                    now.push_back(s + c);
                }
            }
            state = now;
        }
        return state;
    }
};

bool compare(vector<string> v1, vector<string> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    int n = v1.size();
    for (int i = 0; i < n; i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }

    return true;
}

void test_case_1() {
    string digits = "23";
    vector<string> ans{"ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"};

    vector<string> res = Solution().letterCombinations(digits);
    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
