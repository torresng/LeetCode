# 154. Find Minimum in Rotated Sorted Array II

Hard

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  `[0,1,2,4,5,6,7]` might become  `[4,5,6,7,0,1,2]`).

Find the minimum element.

The array may contain duplicates.

**Example 1:**

```
Input: [1,3,5]
Output: 1
```

**Example 2:**

```
Input: [2,2,2,0,1]
Output: 0
```

**Note:**

- This is a follow up problem to [Find Minimum in Rotated Sorted Array](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/description/).
- Would allow duplicates affect the run-time complexity? How and why?



## 思路

1. 先判斷整個序列是否有序，如果是直接返回 nums[ 0 ] 即可。
2. 如果 nums[ mid ] 比 nums[ r ] 大，則右邊的序列不是有序的，最小值在右邊的序列中
3. 如果 nums[ mid ] 比 nums[ r ] 小，則右邊的序列是有序的，最小值在左邊的序列中，注意包含mid的，即最小值在 [ l , mid ] 中，有可能nums [ mid ] 是最小值。因此這里移動 r = mid，而不是 r = mid - 1。
4. 否則還不知道那邊有序的情況下，將 r 向前移動一位。