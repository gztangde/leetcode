---
title: Leetcode 583. Delete Operation for Two Strings
date: 2019-02-04 16:00:58
updated: 2019-02-04 16:00:58
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given two words  _word1_  and  _word2_, find the minimum number of steps required to make  _word1_  and  _word2_  the same, where in each step you can delete one character in either string.

**Example 1:**  

**Input:** "sea", "eat"
**Output:** 2
**Explanation:** You need one step to make "sea" to "ea" and another step to make "eat" to "ea".

**Note:**  

1. The length of given words won't exceed 500.
2. Characters in given words can only be lower-case letters.

**Difficulty**:Medium

**Category**:String

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  int minDistance(string word1, string word2) {
    const size_t m = word1.length();
    const size_t n = word2.length();
    int f[m + 1][n + 1];
    for (size_t i = 0; i <= m; ++i) f[i][0] = i;
    for (size_t j = 0; j <= n; ++j) f[0][j] = j;

    for (size_t i = 1; i <= m; ++i) {
      for (size_t j = 1; j <= n; ++j) {
        if (word1[i - 1] == word2[j - 1]) {
          f[i][j] = f[i - 1][j - 1];
        } else {
          f[i][j] = min(f[i - 1][j], f[i][j - 1]) + 1;
        }
      }
    }
    return f[m][n];
  }
};
```

# Related Question

* [Leetcode 72. Edit Distance](./Leetcode-72-Edit-Distance/)
* [Leetcode 712. Minimum ASCII Delete Sum for Two Strings](./Leetcode-712-Minimum-ASCII-Delete-Sum-for-Two-Strings/)
* [Leetcode 583. Delete Operation for Two Strings](./Leetcode-583-Delete-Operation-for-Two-Strings/)