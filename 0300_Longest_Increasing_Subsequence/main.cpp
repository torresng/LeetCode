// T = O(nlog(n)), S = O(n)
class Solution {
    int binarySearch(vector<int> &arr, int len, int x) {
        int l = 0, r = len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (arr[mid] >= x) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }

  public:
    int lengthOfLIS(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size(), len = 0;
        vector<int> d(n);
        for (int i = 0; i < n; i++) {
            int x = binarySearch(d, len, nums[i]);
            d[x] = nums[i];
            if (x == len) {
                len++;
            }
        }
        return len;
    }
};
