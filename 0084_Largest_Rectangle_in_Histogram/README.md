# 84. Largest Rectangle in Histogram

**Hard**

Given *n*  non-negative integers representing the histogram's bar height where the  width of each bar is 1, find the area of largest rectangle in the  histogram.

 

![img](https://assets.leetcode.com/uploads/2018/10/12/histogram.png)
 Above is a histogram where width of each bar is 1, given height = `[2,1,5,6,2,3]`.

 

![img](https://assets.leetcode.com/uploads/2018/10/12/histogram_area.png)
 The largest rectangle is shown in the shaded area, which has area = `10` unit.

 

**Example:**

```
Input: [2,1,5,6,2,3]
Output: 10
```



## 思路

### 方法一  O ( n ^ 2 ) 

先用 i 從 0 到 n-1 遍歷 heights 找出每個右邊界，再在每個循環中再用 j 從 i 到 0 向找出每個左邊界，j 向左移時同時計算出 [ j , i ] 區間的面積，取出當中最大值即可。

可以優化上面這個算法，遍歷 i 時不用每次都也同時遍歷 j，只要遍歷 heights[ i ] > heights [ i + 1 ] 條件下的 j 即可，因為當 heights[ i ] < heights [ i + 1 ] 時，明顯最大面積肯定也包含 height [ i + 1 ]的。 

