#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<string, int> hash;
        for (int i = 0; i + 10 <= (int)s.size(); i++) {
            string str = s.substr(i, 10);
            hash[str]++;
            if (hash[str] == 2) {
                res.push_back(str);
            }
        }
        return res;
    }
};

void test_case_1() {
    string s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT";
    vector<string> ans{"AAAAACCCCC", "CCCCCAAAAA"};

    vector<string> res = Solution().findRepeatedDnaSequences(s);
    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
