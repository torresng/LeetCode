#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    int search(vector<int> &nums, int target) {
        if (nums.empty()) {
            return -1;
        }

        int l = 0, r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target <= nums[mid]) {
                    r = mid;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] <= target && target <= nums[r]) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
        }

        return nums[l] == target ? l : -1;
    }

    /*
    // 劃分左右區間 [0, pivot - 1] [pivot, n - 1]
    // 其中 nums[0] <= nums[pivot - 1], nums[pivot] < nums[n - 1]
  int search(vector<int> &nums, int target) {
      if (nums.empty()) {
          return -1;
      }

      int n = nums.size();
      int l = 0, r = n - 1;
      while (l < r) {
          int mid = (l + r) >> 1;

          if (nums[mid] > nums[r]) {
              l = mid + 1;
          } else if (nums[mid] < nums[l]) {
              r = mid;
          } else {
              break;
          }
      }

      int pivot = l;
      l = 0, r = pivot - 1;
      while (l < r) {
          int mid = (l + r) >> 1;
          if (nums[mid] >= target) {
              r = mid;
          } else {
              l = mid + 1;
          }
      }
      if (nums[l] == target) {
          return l;
      }

      l = pivot, r = n - 1;
      while (l < r) {
          int mid = (l + r) >> 1;
          if (nums[mid] >= target) {
              r = mid;
          } else {
              l = mid + 1;
          }
      }
      return nums[l] == target ? l : -1;
  }
  */
};

void test_case_1() {
    vector<int> nums{4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int ans = 4;
    int res = Solution().search(nums, target);
    assert(res == ans);
}

void test_case_2() {
    vector<int> nums{2, 4, 5, 6, 7, 0, 1};
    int target = 0;
    int ans = 5;
    int res = Solution().search(nums, target);
    assert(res == ans);
}

void test_case_3() {
    vector<int> nums{5, 6, 7, 0, 1, 2, 4};
    int target = 0;
    int ans = 3;
    int res = Solution().search(nums, target);
    assert(res == ans);
}

void test_case_4() {
    vector<int> nums{7, 0, 1, 2, 4, 5, 6};
    int target = 0;
    int ans = 1;
    int res = Solution().search(nums, target);
    assert(res == ans);
}

void test_case_5() {
    vector<int> nums{3, 1};
    int target = 1;
    int ans = 1;
    int res = Solution().search(nums, target);
    assert(res == ans);
}

int main(void) {
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();

    return 0;
}
