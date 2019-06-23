# 10. Regular Expression Matching

Given an input string (`s`) and a pattern (`p`), implement regular expression matching with support for `'.'` and `'*'`.

```
'.' Matches any single character.
'*' Matches zero or more of the preceding element.
```

The matching should cover the **entire** input string (not partial).

**Note:**

- `s` could be empty and contains only lowercase letters `a-z`.
- `p` could be empty and contains only lowercase letters `a-z`, and characters like `.` or `*`.

**Example 1:**

```
Input:
s = "aa"
p = "a"
Output: false
Explanation: "a" does not match the entire string "aa".
```

**Example 2:**

```
Input:
s = "aa"
p = "a*"
Output: true
Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
```

**Example 3:**

```
Input:
s = "ab"
p = ".*"
Output: true
Explanation: ".*" means "zero or more (*) of any character (.)".
```

**Example 4:**

```
Input:
s = "aab"
p = "c*a*b"
Output: true
Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
```

**Example 5:**

```
Input:
s = "mississippi"
p = "mis*is*p*."
Output: false
```

## 思路

可以用DP來解這題，先創建一個二維數組dp，dp[ i ] [ j ] 代表 s[ 0 .. i - 1 ] 能否與 p[ 0 .. j - 1 ] 匹配，可以得出如下推導

```
當 i = 0 and j = 0 時有 
		dp[0][0] = true;		
// 因為當 s 和 p 都為空時明顯是匹配的
     
否則當 p[j - 1] != '*' 時 
		dp[i][j] = i > 0 && dp[i - 1][j - 1] && ( s[i - 1] == p[j - 1] || p[j - 1] == '.' )
// 1. 當 p[j - 1]不是 '*' 時，那我們先判斷 dp[i - 1][j - 1] 是否為true（即 s[i - 2] 和 p[j - 2] 是否匹配），
// 2. 當為true時才判斷 s[i - 1] 是否跟 p[j - 1] 相等，或 p[j - 1]是否為 '.' （因為 '.' 可以匹配任何字符)。
// 3. 這里注意邊界，所以在最開頭需要判斷 i 是否大於 0，否則當 i 為 0 時， i - 1 就成了 -1 了。

否則 p[j - 1] 肯定是 '*' 了，當 j > 1，則 
		dp[i][j] = dp[i] [j - 2] || ( i > 0 && dp[i - 1][j] && ( s[i - 1] == p[j - 2] || p[j - 2] == '.' ))
		
// 1. 因為 '*' 代表前面的一個字符可出現零次或多次，我們先判斷當 '*' 代表前面的字符出現一次的情況下，
// 即看看 dp[i] [j - 2] 是否為true（ dp [i][j - 2] 代表 s[i-1] 跟 p[j - 3] 是否匹配，
// 因為 p[j - 1]為 '*'，而 p[j - 2]為 '*' 的前一個字符，所這里為了判斷 '*' 前面的字符出現零次的情況下，
// 所以這里直接比較 s[i - 1] 和 p[j - 3]，即 dp[i][j - 2] 是否為true。 
// 2. 當 '*' 代表前面字符出現零次條件也不成立時，我們看看 '*' 代表前面字符出現一次和多次的情況。
// 我們先判斷 dp[i-1][j] 是否為true（即判斷 s[0 .. i-2]和 p[0 .. j-1] 是否匹配，代表 '*' 前面的字符已經出現過一次），
// 再判斷 s[i - 1] 是為與 '*' 前面的字符匹配，即是否與 p[j - 2] 匹配，或 '*' 前面的字符判斷是否為 '.'，即 p[j - 2] 為 '.'（代表任何字符）
// 3. 注意這里也要小心邊界條件。

```

