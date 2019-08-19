#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<bool> st;

  public:
    bool makesquare(vector<int> &nums) {
        int sum = 0;
        for (int u : nums) {
            sum += u;
        }
        if (!sum || sum % 4) {
            return false;
        }

        sort(nums.begin(), nums.end());
        reverse(nums.begin(), nums.end());

        st = vector<bool>(nums.size());

        return dfs(nums, 0, 0, sum / 4);
    }

  private:
    bool dfs(vector<int> &nums, int u, int curLen, int length) {
        if (curLen == length) {
            u++, curLen = 0;
        }
        if (u == 4) {
            return true;
        }

        for (unsigned i = 0; i < nums.size(); i++) {
            if (!st[i] && curLen + nums[i] <= length) {
                st[i] = true;
                if (dfs(nums, u, curLen + nums[i], length)) {
                    return true;
                }
                st[i] = false;

                if (!curLen) {
                    return false;
                }
                if (curLen + nums[i] == length) {
                    return false;
                }
                while (i + 1 < nums.size() && nums[i] == nums[i + 1]) {
                    i++;
                }
            }
        }
        return false;
    }
};

void test_case_1() {
    vector<int> nums{1, 1, 2, 2, 2};
    bool ans = true;

    bool res = Solution().makesquare(nums);
    assert(res == ans);
}

void test_case_2() {
    vector<int> nums{5,5,5,5,4,4,4,4,3,3,3,3};
    bool ans = true;

    bool res = Solution().makesquare(nums);
    assert(res == ans);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
