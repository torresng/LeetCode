class Solution {
    vector<int> tmp;
    int mergeSort(vector<int> &nums, int l, int r) {
        if (l >= r) {
            return 0;
        }
        int mid = (l + r) >> 1;
        int res = mergeSort(nums, l, mid) + mergeSort(nums, mid + 1, r);

        int i = l, j = mid + 1;
        while (i <= mid && j <= r) {
            if (nums[i] <= 2L * nums[j]) {
                i++;
            } else {
                res += (mid - i + 1);
                j++;
            }
        }
        i = l, j = mid + 1;
        int k = 0;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                tmp[k++] = nums[i++];
            } else {
                tmp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            tmp[k++] = nums[i++];
        }
        while (j <= r) {
            tmp[k++] = nums[j++];
        }
        for (i = l, k = 0; i <= r; i++, k++) {
            nums[i] = tmp[k];
        }

        return res;
    }

  public:
    int reversePairs(vector<int> &nums) {
        if (nums.empty()) {
            return 0;
        }
        int n = nums.size();
        tmp = vector<int>(n);
        int res = mergeSort(nums, 0, n - 1);
        return res;
    }
};
