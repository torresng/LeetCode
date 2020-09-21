class Solution {
  public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int len1 = nums1.size(), len2 = nums2.size();
        if ((len1 + len2) & 1) {
            return (double)findKSortedArrays(nums1, nums2,
                                             (len1 + len2) / 2 + 1);
        } else {
            double a = findKSortedArrays(nums1, nums2, (len1 + len2) / 2);
            double b = findKSortedArrays(nums1, nums2, (len1 + len2) / 2 + 1);
            return (a + b) / 2.0;
        }
    }

    int findKSortedArrays(vector<int> &nums1, vector<int> &nums2, int k) {
        int base1 = 0, base2 = 0, len1 = nums1.size(), len2 = nums2.size();
        while (true) {
            if (len1 == 0) {
                return nums2[base2 + k - 1];
            }
            if (len2 == 0) {
                return nums1[base1 + k - 1];
            }
            if (k == 1) {
                return min(nums1[base1], nums2[base2]);
            }

            int i = min(k / 2, len1), j = min(k - i, len2);
            int a = nums1[base1 + i - 1], b = nums2[base2 + j - 1];

            if (i + j == k && a == b) {
                return a;
            }
            if (a <= b) {
                base1 += i;
                len1 -= i;
                k -= i;
            }
            if (a >= b) {
                base2 += j;
                len2 -= j;
                k -= j;
            }
        }
        return 0;
    }
};
