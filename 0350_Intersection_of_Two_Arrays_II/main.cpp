#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        vector<int> res;
        unordered_map<int, int> m;
        for (auto v : nums1) {
            ++m[v];
        }
        for (auto v : nums2) {
            if (m[v]-- > 0) {
                res.push_back(v);
            }
        }
        return res;
    }
};

bool compare(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() != nums2.size()) {
        return false;
    }
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());
    for (unsigned i = 0; i < nums1.size(); ++i) {
        if (nums1[i] != nums2[i]) {
            return false;
        }
    }

    return true;
}

void test_case_1() {
    vector<int> nums1{1, 2, 2, 1};
    vector<int> nums2{2, 2};
    vector<int> ans{2, 2};

    vector<int> res = Solution().intersect(nums1, nums2);
    assert(compare(res, ans) == true);
}

void test_case_2() {
    vector<int> nums1{4, 9, 5};
    vector<int> nums2{9, 4, 9, 8, 4};
    vector<int> ans{4, 9};

    vector<int> res = Solution().intersect(nums1, nums2);
    assert(compare(res, ans) == true);
}

int main(void) {
    test_case_1();
    test_case_2();

    return 0;
}
