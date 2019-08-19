#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int n = numbers.size();
        for (int j = 0, i = n - 1; j < n; j++) {
            while (j < i - 1 && numbers[j] + numbers[i - 1] >= target) {
                i--;
            }
            if (numbers[j] + numbers[i] == target) {
                return {j + 1, i + 1};
            }
        }
        return {-1, -1};
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
    vector<int> numbers{2, 7, 11, 15};
    int target = 9;
    vector<int> ans{1, 2};

    vector<int> res = Solution().twoSum(numbers, target);
    assert(compare(res, ans) == true);
}

int main() {
    test_case_1();

    return 0;
}
