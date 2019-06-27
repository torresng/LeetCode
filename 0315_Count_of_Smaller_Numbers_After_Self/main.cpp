#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> t, res(n);

        for (int i = n - 1; i >= 0; --i) {
            int l = 0, r = t.size();
            while (l < r) {
                int mid = (l + r) >> 1;
                if (t[mid] >= nums[i]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            }
            res[i] = l;
            t.insert(t.begin() + l, nums[i]);
        }

        return res;
    }
};

bool compare(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() != nums2.size()) {
        return false;
    }
    for (unsigned i = 0; i < nums1.size(); ++i) {
        if (nums1[i] != nums2[i]) {
            return false;
        }
    }

    return true;
}

void test_case_1() {
    vector<int> nums{5, 2, 6, 1};
    vector<int> ans{2, 1, 1, 0};

    vector<int> res = Solution().countSmaller(nums);
    for (auto v : res) {
        cout << v << " ";
    }
    cout << endl;
    assert(compare(ans, res) == true);
}

int main(void) {
    test_case_1();

    return 0;
}
