#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  public:
    int numUniqueEmails(vector<string> &emails) {
        unordered_set<string> hash;
        for (auto email : emails) {
            int at = email.find('@');
            string name;
            for (auto c : email.substr(0, at)) {
                if (c == '+') {
                    break;
                } else if (c != '.') {
                    name += c;
                }
            }
            string domain = email.substr(at + 1);
            hash.insert(name + "@" + domain);
        }
        return hash.size();
    }
};

void test_case_1() {
    vector<string> emails{"test.email+alex@leetcode.com",
                          "test.e.mail+bob.cathy@leetcode.com",
                          "testemail+david@lee.tcode.com"};
    int ans = 2;

    int res = Solution().numUniqueEmails(emails);
    assert(res == ans);
}

int main() {
    test_case_1();

    return 0;
}
