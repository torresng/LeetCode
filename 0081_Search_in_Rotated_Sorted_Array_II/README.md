# 81. Search in Rotated Sorted Array II

Medium

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., `[0,0,1,2,2,5,6]` might become `[2,5,6,0,0,1,2]`).

You are given a target value to search. If found in the array return `true`, otherwise return `false`.

**Example 1:**

```
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
```

**Example 2:**

```
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
```

**Follow up:**

- This is a follow up problem to [Search in Rotated Sorted Array](https://leetcode.com/problems/search-in-rotated-sorted-array/description/), where `nums` may contain duplicates.
- Would this affect the run-time complexity? How and why?



## 思路

二分思路可參考 [No.0033. Search in Rotated Sorted Array](https://github.com/torresng/LeetCode-Cpp/tree/master/0033_Search_in_Rotated_Sorted_Array)，需要注意的是因為這題數字可重複，所以取得中間值時不能用No.0033的思路判斷左或右那個己排好序，所以這里用的方法是判斷一方已排好序的同時也判斷另一方是否沒有排好序。當判斷不了哪一方已排好序時，我們只能移動將 r 向前移動一位（或 l 向後移動一位）。

所以算法最壞情況的時間複雜度為 O(n)