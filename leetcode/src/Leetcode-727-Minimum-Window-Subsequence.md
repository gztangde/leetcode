---
title: Leetcode 727. Minimum Window Subsequence
date: 2019-03-05 11:33:52
updated: 2019-03-05 11:33:52
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Leetcode 727. Minimum Window Subsequence

Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.

If there is no such window in S that covers all characters in T, return the empty string "". If there are multiple such minimum-length windows, return the one with the left-most starting index.

Example 1:

Input:

S = "abcdebdde", T = "bde"
Output: "bcde"

Explanation:

"bcde" is the answer because it occurs before "bdde" which has the same length.
"deb" is not a smaller window because the elements of T in the window must occur in order.

Note:

* All the strings in the input will only contain lowercase letters.
* The length of S will be in the range [1, 20000].
* The length of T will be in the range [1, 100].

**Difficulty**:Medium

**Category**:

<!-- more -->

# Solution

## Solution 1: DP

该方案来源于博客： [Minimum Window Subsequence 最小窗口序列](http://www.cnblogs.com/grandyang/p/8684817.html)

字符串且还是Hard的题，十有八九都是要用动态规划Dynamic Programming来做的，那么就直接往DP上去想吧. DP的第一步就是设计dp数组，像这种两个字符串的题，一般都是一个**二维数组**，想想该怎么定义。**确定一个子串的两个关键要素是起始位置和长度**，那么我们的dp值到底应该是定起始位置还是长度呢？That is a question! 仔细想一想，其实起始位置是长度的基础，因为我们一旦知道了起始位置，那么当前位置减去起始位置，就是长度了，所以我们dp值定为起始位置。那么 `dp[i][j]` 表示范围 **S 中前 i 个字符包含范围 T 中前 j 个字符的子串的起始位置**，注意这里的包含是子序列包含关系。然后就是确定长度了，有时候会使用字符串的原长度，有时候会多加1，看个人习惯吧，这里博主长度多加了个1。

```cpp
class Solution {
 public:
  string minWindow(string S, string T) {
    int m = S.size(), n = T.size(), start = -1, minLen = INT_MAX;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= m; ++i) dp[i][0] = i;
    for (int i = 1; i <= m; ++i) {
      for (int j = 1; j <= min(i, n); ++j) {
        dp[i][j] = (S[i - 1] == T[j - 1]) ? dp[i - 1][j - 1] : dp[i - 1][j];
      }

      // If dp[i][n] != -1, then s[0: i] have included T.
      if (dp[i][n] != -1) {
        // dp[i][n] is the start index which begin with the T[0]
        int len = i - dp[i][n];
        if (minLen > len) {
          minLen = len;
          start = dp[i][n];
        }
      }
    }
    return (start != -1) ? S.substr(start, minLen) : "";
  }
};
```

## Solution 2: Two Points

```cpp
class Solution {
 public:
  string minWindow(string S, string T) {
    int m = S.size(), n = T.size(), start = -1, minLen = INT_MAX, i = 0, j = 0;
    while (i < m) {
      if (S[i] == T[j]) {
        if (++j == n) {
          int end = i + 1;
          while (--j >= 0) {
            while (S[i--] != T[j])
              ;
          }
          ++i;
          ++j;
          if (end - i < minLen) {
            minLen = end - i;
            start = i;
          }
        }
      }
      ++i;
    }
    return (start != -1) ? S.substr(start, minLen) : "";
  }
};
```