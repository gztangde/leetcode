---
title: Leetcode 115. Distinct Subsequences
date: 2018-12-23 09:09:31
updated: 2018-12-23 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Question

Given a string  **S**  and a string  **T**, count the number of distinct subsequences of  **S**  which equals  **T**.

A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie,  `"ACE"`  is a subsequence of  `"ABCDE"`  while  `"AEC"`  is not).

**Example 1:**

![](/images/in-post/2018-12-23-Leetcode-115-Distinct-Subsequences/2018-12-24-10-04-09.png)

**Example 2:**

![](/images/in-post/2018-12-23-Leetcode-115-Distinct-Subsequences/2018-12-24-10-37-53.png)

**Difficulty**:Hard

**Category**:String, Dynamic-Programming

<!-- more -->

------------

# Analyze

------------

# Solution

```cpp
// eg. f(i, j) = f(i − 1, j)
// f(i, j) = f(i − 1, j) + f(i − 1, j − 1)
class Solution {
 public:
  int numDistinct(string s, string t) {
    int m = t.length(), n = s.length();

    int f[m + 1][n + 1];
    for (size_t i = 0; i <= n; ++i) f[0][i] = 1;
    for (size_t j = 1; j <= m; ++j) f[j][0] = 0;

    for (size_t i = 1; i <= m; ++i) {
      for (size_t j = 1; j <= n; ++j) {
        f[i][j] = f[i][j - 1] + (t[i - 1] == s[j - 1] ? f[i - 1][j - 1] : 0);
      }
    }
    return f[m][n];
  }
};
```
