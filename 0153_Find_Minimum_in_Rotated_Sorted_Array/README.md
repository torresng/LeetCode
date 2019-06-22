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
4. 否則看看那一方有序，有序的一方不可能包含最小值，直接判斷另一方即可。注意開頭已經判斷了整個序列是否有序，和第二跟第三步已經判斷了nums[mid]是最大值或最小值，所以到了這步不可能出現兩邊同時有序的情況。

注意代碼中只需判斷到 l < r 的情況，不用判斷 l == r 的情況，因為這題肯定會有解。而[No. 0033. Search in Rotated Sorted Array](https://github.com/torresng/LeetCode-Cpp/tree/master/0033_Search_in_Rotated_Sorted_Array) 有可能沒有解，所以 No.0033 需要判斷 l <= r 的情況。

