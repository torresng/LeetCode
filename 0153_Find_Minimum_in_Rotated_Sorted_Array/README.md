# 153. Find Minimum in Rotated Sorted Array

Medium

Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  `[0,1,2,4,5,6,7]` might become  `[4,5,6,7,0,1,2]`).

Find the minimum element.

You may assume no duplicate exists in the array.

**Example 1:**

```
Input: [3,4,5,1,2] 
Output: 1
```

**Example 2:**

```
Input: [4,5,6,7,0,1,2]
Output: 0
```



## 思路

1. 先判斷整個序列是否已經排好序，如果是則明顯 nums[0] 就是最小值。
2. 如果 nums[mid] 值比 nums[ mid + 1 ] 大，那 nums[ mid + 1 ]就是最小值
3. 如果 nums[mid] 值比 nums[ mid - 1 ] 小，那 nums[ mid ]就是最小值
4. 否則看看那一方有序，有序的一方不可能包含最小值，直接判斷另一方即可，因為開頭已經判斷了整個序列是否有序，所以這