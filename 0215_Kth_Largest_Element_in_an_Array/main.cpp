// T = O(nlogk), S = O(k);
class Solution {
  public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        for (auto num : nums) {
            if (heap.size() < k) {
                heap.push(num);
            } else if (num > heap.top()) {
                heap.pop();
                heap.push(num);
            }
        }
        return heap.top();
    }
};

// Quick sort
// T(avg) = O(n), T(worst) = O(n^2) S = O(1)
class Solution {
  public:
    int quick_sort(vector<int> &nums, int l, int r, int k) {
        if (l == r) {
            return nums[l];
        }
        int i = l - 1, j = r + 1, x = nums[(l + r) >> 1];
        while (i < j) {
            do {
                i++;
            } while (nums[i] > x);
            do {
                j--;
            } while (nums[j] < x);
            if (i < j) {
                swap(nums[i], nums[j]);
            }
        }
        int si = j - l + 1;
        if (k <= si) {
            return quick_sort(nums, l, j, k);
        } else {
            return quick_sort(nums, j + 1, r, k - si);
        }
    }
    int findKthLargest(vector<int> &nums, int k) {
        int n = nums.size();
        return quick_sort(nums, 0, n - 1, k);
    }
};
