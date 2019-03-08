---
title: Leetcode 712. Minimum ASCII Delete Sum for Two Strings
date: 2019-02-04 17:03:27
updated: 2019-02-04 17:03:27
categories: 
- [Leetcode]
tags: Leetcode
mathjax: true
top:
---

# Question

Given two strings  `s1, s2`, find the lowest ASCII sum of deleted characters to make two strings equal.

**Example 1:**  

**Input:** s1 = "sea", s2 = "eat"
**Output:** 231
**Explanation:** Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
Deleting "t" from "eat" adds 116 to the sum.
At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.

**Example 2:**  

**Input:** s1 = "delete", s2 = "leet"
**Output:** 403
**Explanation:** Deleting "dee" from "delete" to turn the string into "let",
adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.

**Note:**

- `0 < s1.length, s2.length <= 1000`.
- All elements of each string will have an ASCII value in  `[97, 122]`.

**Difficulty**:Medium

**Category**:

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  int minimumDeleteSum(string s1, string s2) {
    const size_t m = s1.length();
    const size_t n = s2.length();
    int f[m + 1][n + 1];
    f[0][0] = 0;
    for (size_t i = 1; i <= m; ++i) f[i][0] = f[i - 1][0] + s1[i - 1];
    for (size_t j = 1; j <= n; ++j) f[0][j] = f[0][j - 1] + s2[j - 1];

    for (size_t i = 1; i <= m; ++i) {
      for (size_t j = 1; j <= n; ++j) {
        if (s1[i - 1] == s2[j - 1]) {
          f[i][j] = f[i - 1][j - 1];
        } else {
          f[i][j] = min(f[i - 1][j] + s1[i - 1], f[i][j - 1] + s2[j - 1]);
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