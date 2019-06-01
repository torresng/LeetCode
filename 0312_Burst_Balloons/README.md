# 312. Burst Balloons

Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

**Note:**

* You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
* 0 >= n >= 500, 0 >= nums[i] >= 100

**Example:**

```
Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
```

## 思路

  我們可以用Dynamic Programming來解這題，dp[ i ] [ j ] 代表nums在區間 [ i , j ] 獲得的最大硬幣。

  我們來分析一下簡單情況

1. 當 i == j 時，即 [ i , j ] 只有一個數時，dp[i][j] 的值為 
  
```
dp[i][j] = nums[i-1] * nums[i] * nums[i+1]
```

2. 當 i = j + 1 時，即 [ i , j ] 有兩個數，dp[ i ] [ j ] 的值為 

```
dp[i][j] = max(nums[i-1] * nums[i] * nums[i+1] + nums[i-1] * nums[j] * nums[j+1], 
               nums[j-1] * nums[j] * nums[j+1] + nums[i-1] * nums[i] * nums[j+1])
         = max(dp[i][j-1] + nums[i-1] * nums[j] * nums[j+1],
               dp[i+1][j] + nums[i-1] * nums[i] * nums[j+1])
```

這里解釋一下，當打破了第i個氣球，獲得 nums[ i - 1 ] * nums[ i ] * nums[ i + 1 ] 硬幣，接下來只能打破第 j 個氣球，但因為打破第i個氣球前，i 和 j 是相隣的，打破第 i 個氣球後，就變成了第 i - 1 個氣球和第 j 個氣球相隣，所以之後打破第 j 個氣球時所獲得的硬幣為 nums[ i - 1 ] * nums[ j ] * nums[ j + 1 ]。先打破第j個氣球也同理，然後 dp[ i ] [ j ] 的值為兩者的最大者。

那麼當 i < j 時，dp[ i ] [ j ] 的值是甚麼？我們可以用 k 遍歷整個 [ i , j ]，k 代表在[ i , j ]區間中最後一個被打破的氣球，那麼dp[ i ] [ j ]  的值可以從dp[ i ] [ k - 1] 和 dp [ k + 1 ] [ j ] 的值得出

```
dp[i][j] = max(dp[i][j], dp[i][k-1] + nums[i-1] * nums[k] * nums[j+1] + dp[k+1][j])
```

由於我們可以在 nums 的頭和尾插入數值 1， 所以最後可以用上面的公式統一計算 dp[ i ] [ j ]。還有要注意的是因為較大的區間是根據較小的區間來得出結果的，所以要先計算好所有的小區間，才能計算出大區間。
