---
title: Leetcode 171. Excel Sheet Column Number
date: 2019-01-22 17:17:03
updated: 2019-01-22 17:17:03
categories: 
- [Leetcode]
- [Leetcode, Math]
tags: Leetcode
notshow: true
top:
---

# Question

Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:
```

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28 
    ...
```

**Example 1:**

> **Input:** "A"
> **Output:** 1

**Example 2:**

> **Input:** "AB"
> **Output:** 28

**Example 3:**

> **Input:** "ZY"
> **Output:** 701

**Difficulty**:Easy

**Category**:Math

<!-- more -->

# Analyze

# Solution

```cpp
class Solution {
 public:
  int titleToNumber(string s) {
    int ans = 0;
    for (const char c : s) {
      ans *= 26;
      ans += c - 'A' + 1;
    }
    return ans;
  }
};
```


