---
title: Leetcode 91. Decode Ways
date: 2018-12-23 09:09:31
updated: 2018-12-23 09:09:31
categories: Leetcode
tags: Leetcode
notshow: true
top:
---

# Leetcode 91. Decode Ways

A message containing letters from  `A-Z`  is being encoded to numbers using the following mapping:

> 'A' -> 1
> 'B' -> 2
> ...
> 'Z' -> 26

Given a  **non-empty**  string containing only digits, determine the total number of ways to decode it.

**Example 1:**

> **Input:** "12"
> **Output:** 2
> **Explanation:** It could be decoded as "AB" (1 2) or "L" (12).

**Example 2:**

> **Input:** "226"
> **Output:** 3
> **Explanation:** It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

**Difficulty**:Medium

**Category**:String, Dynamic-Programming

<!-- more -->

# Solution

## Solution 1: DP

建立一位dp数组，长度比输入数组长多多2，全部初始化为1，因为斐波那契数列的前两项也为1，然后从第三个数开始更新，对应数组的第一个数。对每个数组首先判断其是否为0，若是将改为dp赋0，若不是，赋上一个dp值，此时相当如加上了dp[i - 1], 然后看数组前一位是否存在，如果存在且满足前一位不是0，且和当前为一起组成的两位数不大于26，则当前dp值加上dp[i - 2], 至此可以看出来跟斐波那契数组的递推式一样.

Use f[n] = how many ways for the 0 to n:

* If s[n] != 0, f[n] = f[n-1] + f[n-2]; (s[n-1] and s[n] have the number 10 - 26)
* If s[n] == 0, f[n] = f[n-2]

Time complexity: O(n)
Space complexity: O(1)

```cpp
class Solution {
 public:
  int numDecodings(string s) {
    if (s.empty() || (s.length() > 1 && s[0] == '0')) return 0;

    // Set dp vector and the edge value
    vector<int> f(s.length() + 1, 0);
    f[0] = 1;
    for (size_t i = 1; i <= s.length(); ++i) {
      // If the elements is 0, then 
      f[i] = s[i - 1] == '0' ? 0 : f[i - 1];
      if (i >= 2 && (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] <= '6'))) {
        f[i] += f[i - 2];
      }
    }
    return f[s.length()];
  }
};
```
