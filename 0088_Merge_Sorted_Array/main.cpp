#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1, k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k--] = nums1[i--];
            } else {
                nums1[k--] = nums2[j--];
            }
        }
        while (j >= 0) {
            nums1[k--] = nums2[j--];
        }
    }
};

bool compare(vector<int> v1, vector<int> v2) {
    if (v1.size() != v2.size()) {
        return false;
    }
    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());
    for (unsigned i = 0; i < v1.size(); i++) {
        if (v1[i] != v2[i]) {
            return false;
        }
    }
    return true;
}

void test_case_1() {
    vector<int> nums1{1, 2, 3, 0, 0, 0}, nums2{2, 5, 6};
    int m = 3, n = 3;

    vector<int> ans{1, 2, 2, 3, 5, 6};
    Solution().merge(nums1, m, nums2, n);
    vector<int> &res = nums1;
    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
