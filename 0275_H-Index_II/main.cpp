#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        int l = 0, r = n;
        while (l < r) {
            int mid = (l + r + 1) >> 1;
            if (citations[n - mid] >= mid) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
};

void test_case_1() {
    vector<int> citations{0, 1, 3, 5, 6};
    int ans = 3;
    int res = Solution().hIndex(citations);
    assert(res == ans);
}

void test_case_2() {
    vector<int> citations{1};
    int ans = 1;
    int res = Solution().hIndex(citations);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
